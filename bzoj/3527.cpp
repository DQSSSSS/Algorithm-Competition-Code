#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef complex<long double> CD;
const int SZ = 1 << 18;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const long double PI = acos(-1);

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
	CD omega[SZ],omegaInv[SZ];
	
	void init(const int n)
	{
		for(int i = 0; i < n;i ++)
		{
			omega[i] = CD(cos(2 * PI / n * i),sin(2 * PI / n * i));
			omegaInv[i] = conj(omega[i]);
		}
	}
	
	void Transform(CD *a,const int n,CD *omega)
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
			for(CD *p = a;p != a + n;p += l)
			{
				for(int i = 0;i < m;i ++)
				{
					CD t = omega[n / l * i] * p[m + i];
					p[m + i] = p[i] - t;
					p[i] += t;
				}
			}
		}
	}
	
	void dft(CD *a,const int n) {
		Transform(a,n,omega);
	}
	void idft(CD *a,const int n) {
		Transform(a,n,omegaInv);
		for(int i = 0;i < n;i ++) a[i] /= n;
	}
	
}fft;

void multiply(const long double *a1,const int n1,const long double *a2,const long double n2,long double *res)
{
	int n = 1;
	while(n < n1 + n2) n <<= 1;
	static CD c1[SZ],c2[SZ];
	fill(c1,c1 + n,0); fill(c2,c2 + n,0);
	for(int i = 0;i < n1;i ++) c1[i].real(a1[i]);
	for(int i = 0;i < n2;i ++) c2[i].real(a2[i]);
	
	//for(int i = 0;i < n1;i ++) printf("%.3f ",(double)c1[i].real()); puts("");
	//for(int i = 0;i < n2;i ++) printf("%.3f ",(double)c2[i].real()); puts("");

	fft.init(n);
	fft.dft(c1,n); fft.dft(c2,n);
	for(int i = 0;i < n;i ++) c1[i] *= c2[i];
	fft.idft(c1,n);
	for(int i = 0;i < n1 + n2 - 1;i ++) res[i] = c1[i].real();
	//for (int i = 1; i <= n1; i++) printf("%.3f ",(double)res[i]); puts("");
}

/*
0.000 4006373.885 15375036.436 1717456.469 8514941.005 1410681.346
0.000 1.000 0.250 0.111 0.063 0.040
-0.000 4006373.885 16376629.907 6006368.232 10903040.872

0.000 1410681.346 8514941.005 1717456.469 15375036.436 4006373.885
0.000 1.000 0.250 0.111 0.063 0.040
16838672.693 4002934.092 8867611.341 1410681.346 -0.000
*/

long double q[SZ],g[SZ],A[SZ],B[SZ];

int main()
{
	int n = read();
	for(int i = 1;i <= n;i ++)
	{
		double x;
		scanf("%lf",&x);
		q[i] = x;
	}
	for(int i = 1;i <= n;i ++) g[i] = 1.0 / pow(i,2);
	/*
	for(int i = 1;i < n;i ++)
	{
		double x = 0;
		for(int j = 1;j < i;j ++)
			x += q[j] * g[i - j];
		printf("%.3f ",x);
	}
	puts("");
	*/
	multiply(q,n + 1,g,n + 1,A);
	reverse(q + 1,q + n + 1);
	multiply(q,n + 1,g,n + 1,B);
	for(int i = 1;i <= n;i ++) printf("%.10f\n",static_cast<double>(A[i] - B[n - i + 1]));
	return 0;
}
