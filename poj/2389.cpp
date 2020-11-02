#include <cstdio>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 +a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

struct FastFourierTransform
{
	complex<double> omega[SZ],omegaInv[SZ];
	
	void init(const int n)
	{
		for(int i = 0; i < n;i ++)
		{
			omega[i] = complex<double>(cos(2 * PI / n * i),sin(2 * PI / n * i));
			omegaInv[i] = conj(omega[i]);
		}
	}
	
	void Transform(complex<double> *a,const int n,complex<double> *omega)
	{
		int k = 0;
		while((1 << k) < n) k ++;
		for(int i = 0;i < n;i ++)
		{
			int t = 0;
			for(int j = 0;j < k;j ++)
				if(i & (1 << j)) t |= (1 << (k - j - 1));
			if(t > i) swap(a[t],a[i]);
		}
		
		for(int l = 2;l <= n;l *= 2)
		{
			int m = l / 2;
			for(complex<double> *p = a;p != a + n;p += l)
			{
				for(int i = 0;i < m;i ++)
				{
					complex<double> t = omega[n / l * i] * p[m + i];
					p[m + i] = p[i] - t;
					p[i] += t;
				}
			}
		}
	}
	
	void dft(complex<double> *a,const int n) {
		Transform(a,n,omega);
	}
	void idft(complex<double> *a,const int n) {
		Transform(a,n,omegaInv);
		for(int i = 0;i < n;i ++) a[i] /= n;
	}
	
}fft;

void multiply(int *a1,int n1,int *a2,int n2,int *res)
{
	int n = 1;
	while(n < n1 + n2) n *= 2;
	static complex<double> c1[SZ],c2[SZ];
	for(int i = 0;i < n1;i ++) c1[i].real(a1[i]);
	for(int i = 0;i < n2;i ++) c2[i].real(a2[i]);
	fft.init(n);
	fft.dft(c1,n); fft.dft(c2,n);
	for(int i = 0;i < n;i ++) c1[i] *= c2[i];
	fft.idft(c1,n);
	for(int i = 0;i < n1 + n2 - 1;i ++) res[i] = static_cast<int>(floor(c1[i].real() + 0.5));
}

char s[SZ];
int a[SZ],b[SZ],res[SZ];

int main()
{
	int n,m;
	scanf("%s",s); n = strlen(s); for(int i = 0;i < n;i ++) a[i] = s[n - 1 - i] - '0';
	scanf("%s",s); m = strlen(s); for(int i = 0;i < m;i ++) b[i] = s[m - 1 - i] - '0';
	multiply(a,n,b,m,res);
	int x = 0,len = n + m - 1;
	for(int i = 0;i < len;i ++)
		res[i] += x,x = res[i] / 10,res[i] %= 10;
	if(x) res[len ++] = x;
	reverse(res,res + len);
	for(int i = 0;i < len;i ++) printf("%d",res[i]);
	return 0;
}
