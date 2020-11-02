#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = acos(-1);
const int SZ = 3e5 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int getG(int p) {
	if(p == 2) return 1;
	if(p == 13) return 2;
	if(p == 103) return 5;
	if(p == 100003) return 2;
}

struct Complex {
	double x,y;
	Complex() :x(0),y(0) {};
	Complex(double x) :x(x),y(0) {};
	Complex(double x,double y) :x(x),y(y) {};
	Complex operator *(const Complex &o) const { return Complex(x*o.x-y*o.y,x*o.y+y*o.x); }
	void operator +=(const Complex &o) { x+=o.x; y+=o.y; }
	void operator -=(const Complex &o) { x-=o.x; y-=o.y; }
	Complex operator -(const Complex &o) { return Complex(x-o.x,y-o.y); }
	void operator /=(const double &o) { x/=o; y/=o; }
};

struct FFT {
	Complex wn[SZ],wnInv[SZ];
	void init(int n) {
		for(int i = 0;i < n;i ++) {
			wn[i] = Complex(cos(2 * PI / n * i),sin(2 * PI / n * i));
			wnInv[i] = Complex(wn[i].x,-wn[i].y);
		}
	}
	
	void Transform(Complex a[],int n,const Complex wn[]) {
		for(int i = 0,j = 0;i < n;i ++) {
			if(i > j) swap(a[i],a[j]);
			for(int k = n >> 1;(j ^= k) < k;k >>= 1);
		}
		for(int l = 2;l <= n;l <<= 1) {
			int m = l / 2;
			for(Complex *p = a;p != a + n;p += l) {
				for(int i = 0;i < m;i ++) {
					Complex t = wn[n / l * i] * p[i + m];
					p[i + m] = p[i] - t;
					p[i] += t;
				}
			}
		}
	}	
	
	void dft(Complex a[],int n) {
		Transform(a,n,wn);
	}
	
	void idft(Complex a[],int n) {
		Transform(a,n,wnInv);
		for(int i = 0;i < n;i ++) a[i] /= n;
	}
}fft;

Complex c1[SZ],c2[SZ];

int mod,a[SZ];
double b[SZ];
double r[3][SZ];
int id[SZ],pw[SZ];

void work(int mod) {
	int ii;
	if(mod == 13) ii = 0;
	if(mod == 103) ii = 1;
	if(mod == 100003) ii = 2;
	double *r = ::r[ii];
	for(int i = 0;i < mod;i ++) { double x = sin(2*PI*i/mod); r[i] = pow(2,x*x*x); }
}

int main() {
	//freopen("kk.out","w",stdout);
	work(13); work(103); work(100003);
	int g = 2;
	for(int i = 0,t = 1;i < mod;i ++) {
        id[t] = i; pw[i] = t;
        t = 1ll * t * g % mod;
    }
    for(int i = 0;i < mod - 1;i ++) c2[i] = r[2][pw[i + 1]];
    int len = 1;
    while(len < 2 * mod - 2) len <<= 1;
    fft.init(len); fft.dft(c2,len);
	while(~scanf("%d",&mod)) {
		for(int i = 0;i < mod;i ++)
			scanf("%d",&a[i]);
		if(mod <= 103) {
			int ii;
			if(mod == 13) ii = 0;
			if(mod == 103) ii = 1;
			for(int i = 0;i < mod;i ++) {
				double ans = 0;
				for(int j = 0;j < mod;j ++)	
					ans += a[j] * r[ii][i*j%mod];
				printf("%.3f%c",ans,i == mod - 1 ? '\n' : ' ');
			}
			continue;
		}	
		int n = mod - 1;
		for(int i = 0;i < len;i ++) {
			c1[i] = 0;
			if(i < n) c1[i] = a[pw[n - i]];
		}
		fft.dft(c1,len);
		for(int i = 0;i < len;i ++) c1[i] = c1[i] * c2[i];
		fft.idft(c1,len);
		for(int i = 0;i < n;i ++) b[i] = c1[i].x + c1[i + n].x;
		
		double b0 = 0;
		for(int i = 0;i < mod;i ++) b0 += a[i];
		printf("%.3f ",b0);
		for(int i = 1;i < mod;i ++) 
			printf("%.3f ",b[id[i]-1] + a[0]);
	}
	return 0;
}
