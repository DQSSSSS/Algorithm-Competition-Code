#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

struct Complex {
	LD x,y;
	Complex(LD x = 0,LD y = 0) :x(x),y(y) {}
	Complex operator +(Complex o) const { return Complex(x+o.x,y+o.y); }
	Complex operator -(Complex o) const { return Complex(x-o.x,y-o.y); }
	Complex operator /(LD o) const { return Complex(x/o,y/o); }
	Complex operator *(Complex o) const { return Complex(x*o.x-y*o.y,x*o.y+y*o.x); }
};

struct FFT {
	Complex wn[SZ],wnInv[SZ];
	void init(int n) {
		for(int i = 0;i < n;i ++) {
			wn[i] = Complex(cos(2 * PI / n * i),sin(2 * PI / n * i));
			wnInv[i] = Complex(wn[i].x,-wn[i].y);
		}
	}
	
	void Transform(Complex a[],int n,Complex wn[]) {
		for(int i = 0,j = 0;i < n;i ++) {
			if(i > j) swap(a[i],a[j]);
			for(int k = n >> 1;(j ^= k) < k;k >>= 1);
		}
		for(int l = 2;l <= n;l <<= 1) {
			int m = l >> 1;
			for(Complex *p = a;p != a + n;p += l) {
				for(int i = 0;i < m;i ++) {
					Complex t = wn[n / l * i] * p[i + m];
					p[i + m] = p[i] - t;
					p[i] = p[i] + t;
				}
			}
		}
	}	
	
	void dft(Complex a[],int n) {
		Transform(a,n,wn);
	}
	void idft(Complex a[],int n) {
		Transform(a,n,wnInv);
		for(int i = 0;i < n;i ++) a[i] = a[i] / n;
	}
}fft;

Complex c1[SZ],c2[SZ];
int len;

void multiply(LL a[],int n,LL b[],int m,LL ans[]) {
	for(int i = 0;i < len;i ++) c1[i] = c2[i] = 0;
	for(int i = 0;i < n;i ++) c1[i].x = a[i];
	for(int i = 0;i < m;i ++) c2[i].x = b[i];
	fft.dft(c1,len); fft.dft(c2,len);
	for(int i = 0;i < len;i ++) c1[i] = c1[i] * c2[i];
	fft.idft(c1,len);
	for(int i = 0;i < n + m - 1;i ++) ans[i] += c1[i].x + 0.5;
	/*for(int i = 0;i < n;i ++) cout << a[i] << " "; puts("");
	for(int i = 0;i < m;i ++) cout << b[i] << " "; puts("");
	for(int i = 0;i < n + m - 1;i ++) cout << (int)(c1[i].x + 0.5) << " "; puts("");
	puts("--------");*/
}

char s[SZ],t[SZ];
LL a0[SZ],a1[SZ],a2[SZ],a3[SZ];	
LL b0[SZ],b1[SZ],b2[SZ],b3[SZ];
LL ans[SZ];	
const int A = 0;

int main() {
	freopen("10.in","r",stdin);
	scanf("%s%s",s,t);
	int n = strlen(s),m = strlen(t);
	for(int i = 0;i < n;i ++) {
		a0[i] = 1;
		a1[i] = s[i] - 'a' + 1;
		a2[i] = a1[i] * a1[i];
	}
	for(int i = 0;i < m;i ++) {
		int c;
		if(t[m - i - 1] == '?') c = A;
		else c = t[m - i - 1] - 'a' + 1;
		//cout << c << endl;
		b0[i] = c * c * c;
		b1[i] = -2 * c * c;
		b2[i] = c;
	}
	len = 1;
	while(len < n + m) len <<= 1;
	fft.init(len);
	multiply(a0,n,b0,m,ans);
	multiply(a1,n,b1,m,ans);
	multiply(a2,n,b2,m,ans);
	//multiply(a3,n,b3,m,ans);
	//for(int i = 0;i < n + m - 1;i ++) cout << ans[i] << " "; puts("");
	for(int i = m - 1;i < n;i ++)
		if(ans[i] == 0) { 
			printf("%d\n",i - m + 1);
		}
	return 0;
}
/**
aaa
aaa

*/
