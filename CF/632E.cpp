#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
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

struct Complex{
	double x,y;
	Complex(int a) : x(a),y(0) {};
	Complex(double a = 0,double b = 0) : x(a),y(b) {};
	Complex operator +(const Complex &o) const { return Complex(x + o.x,y + o.y); }
	Complex operator -(const Complex &o) const { return Complex(x - o.x,y - o.y); }
	Complex operator *(const Complex &o) const { return Complex(x * o.x - y * o.y,x * o.y + y * o.x); }
	Complex operator *(const double &o) const { return Complex(x * o,y * o); }
	Complex operator /(const double &o) const { return Complex(x / o,y / o); }
};
Complex conj(const Complex &o) { return Complex(o.x,-o.y); }

Complex ksm(Complex a,int b) {
	Complex ans = 1;
	while(b) {
		if(b & 1) ans = a * ans;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

struct FFT {
	Complex wn[SZ],wnInv[SZ];
	void init(int n) {
		for(int i = 0;i < n;i ++) {
			wn[i] = Complex(cos(2 * PI / n * i),sin(2 * PI / n * i));
			wnInv[i] = conj(wn[i]);
		}
	}
	void Transform(Complex a[],int n,const Complex wn[]) {
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

void multiply(int a[],int &n,int b[],int &m) {
    int len = 1;
    while(len < n + m) len <<= 1;
    for(int i = 0;i < len;i ++) c1[i] = c2[i] = 0;
    for(int i = 0;i < n;i ++) c1[i] = a[i];
    for(int i = 0;i < m;i ++) c2[i] = b[i];
    fft.init(len); fft.dft(c1,len); fft.dft(c2,len);
    for(int i = 0;i < len;i ++) c1[i] = c1[i] * c2[i];
    fft.idft(c1,len);
    m += n;
    for(int i = 0;i < m;i ++) b[i] = ((int)(c1[i].x + 0.5) > 0);
}

int a[SZ],b[SZ];

int main() {
	int n = read(),k = read();
	for(int i = 1;i <= n;i ++) {
		int x = read();
		a[x] = 1;
	}
    int lena = 1001,lenb = 1;
    b[0] = 1;
    while(k) {
    	if(k & 1) multiply(a,lena,b,lenb);
    	multiply(a,lena,a,lena);
    	k >>= 1;
    }
//    cout << lenb << endl;
	//for(int i = 0;i < lenb;i ++) cout << b[i] << " "; puts("");
	for(int i = 0;i < lenb;i ++)
		if(b[i]) printf("%d ",i);
	return 0;
}
