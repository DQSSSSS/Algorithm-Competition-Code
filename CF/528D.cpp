#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 550010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct FFT {
    complex<double> wn[SZ],wnInv[SZ];
    void init(int n) {
        for(int i = 0;i < n;i ++) {
            wn[i] = complex<double>(cos(2 * PI / n * i),sin(2 * PI / n * i));
            wnInv[i] = conj(wn[i]);
        }
    }   

    void Transform(complex<double> *a,int n,const complex<double> *wn) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i < j) swap(a[i],a[j]);
            for(int k = n >> 1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l <<= 1) {
            int m = l / 2;
            for(complex<double> *p = a;p != a + n;p += l) {
                for(int i = 0;i < m;i ++) {
                    complex<double> t = wn[n / l * i] * p[m + i];
                    p[m + i] = p[i] - t;
                    p[i] += t;
                }
            }
        }
    }

    void dft(complex<double> *a,int n) {
        Transform(a,n,wn);
    }
    void idft(complex<double> *a,int n) {
        Transform(a,n,wnInv);
        for(int i = 0;i < n;i ++) a[i] /= n;
    }
}fft;

complex<double> c1[SZ],c2[SZ];

int len;

void multiply(int *a,int n,int *b,int m,int *ans) {
    for(int i = 0;i < len;i ++) c1[i] = c2[i] = 0;
    for(int i = 0;i < n;i ++) c1[i].real(a[i]);
    for(int i = 0;i < m;i ++) c2[i].real(b[i]);
    fft.dft(c1,len); fft.dft(c2,len);
    for(int i = 0;i < len;i ++) c1[i] = c1[i] * c2[i];
    fft.idft(c1,len);
    for(int i = 0;i < n + m - 1;i ++) ans[i] += c1[i].real() + 0.5;
	/*for(int i = 0;i < n;i ++) cout << a[i] << " "; puts("");
    for(int i = 0;i < m;i ++) cout << b[i] << " "; puts("");
    for(int i = 0;i < n + m - 1;i ++) cout << ans[i] << " "; puts("");
    puts("--------------");*/
}

char s1[SZ],s2[SZ];
char biao[] = {'A','G','C','T'};
int tmp[SZ];
int a[SZ],b[SZ],ans[SZ];

int main() {
	int n = read(),m = read(),k = read();
	scanf("%s%s",s1,s2);
	len = 1; while(len <= n) len <<= 1;
	fft.init(len);
	for(int cc = 0;cc < 4;cc ++) {
		char c = biao[cc];
		for(int i = 0;i < n;i ++) tmp[i] = 0;
		for(int i = 0;i < n;i ++) {
			if(s1[i] == c) 
				tmp[max(0,i - k)] ++,
				tmp[min(n,i + k + 1)] --;
		}
		for(int i = 1;i < n;i ++) tmp[i] += tmp[i - 1];
		for(int i = 0;i < n;i ++) a[i] = tmp[i] >= 1;
		for(int i = 0;i < m;i ++) b[m - i - 1] = s2[i] == c;
		multiply(a,n,b,m,ans);
	}
	int Ans = 0;
	for(int i = m - 1;i < n;i ++)
		if(ans[i] == m) Ans ++;
	printf("%d\n",Ans);
	return 0;
}
