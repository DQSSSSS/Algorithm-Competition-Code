#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const double PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct FFTranform {
    complex<double> omega[SZ],omegaInv[SZ];

    void init(int n) {
        for(int i = 0;i < n;i ++) {
            omega[i] = complex<double>(cos(2 * PI / n * i),sin(2 * PI / n * i));
            omegaInv[i] = conj(omega[i]);
        }
    }

	void Transform(complex<double> *a,int n,complex<double> *omega) {
        int k = 0;
        while((1 << k) < n) k ++;
        for(int i = 0;i < n;i ++) {
        	int t = 0;
        	for(int j = 0;j < k;j ++)
                if(i & (1 << j)) t |= 1 << (k - j - 1);
            if(t > i) swap(a[t],a[i]);
        }
        for(int l = 2;l <= n;l *= 2) {
            int m = l / 2;
            for(complex<double> *p = a;p != a + n;p += l) {
                for(int i = 0;i < m;i ++) {
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

complex<double> c1[SZ],c2[SZ];

void multiply(int *a1,int n1,int *a2,int n2,int *ans) {
	int n = 1;
    while(n < 2 * n1 || n < 2 * n2) n *= 2;
    for(int i = 0;i < n1;i ++) c1[i].real(a1[i]);
    for(int i = 0;i < n2;i ++) c2[i].real(a2[i]);
    fft.init(n); fft.dft(c1,n); fft.dft(c2,n);
    for(int i = 0;i < n;i ++) c1[i] *= c2[i];
    fft.idft(c1,n);
    for(int i = 0;i < n1 + n2 - 1;i ++) ans[i] = c1[i].real() + 0.5;
}

char s1[SZ],s2[SZ];
int a[SZ],b[SZ],c[SZ];

int main() {
	scanf("%s%s",s1,s2);
    int n = strlen(s1),m = strlen(s2);
    for(int i = 0;i < n;i ++) a[i] = s1[n - i - 1] - '0';
    for(int i = 0;i < m;i ++) b[i] = s2[m - i - 1] - '0';
	multiply(a,n,b,m,c);
	for(int i = 0;i < n + m - 1;i ++) c[i + 1] += c[i] / 10,c[i] %= 10;
	int pos = c[n + m - 1] ? n + m - 1 : n + m - 2;
	for(int i = pos;i >= 0;i --) printf("%d",c[i]);
	return 0;
}
