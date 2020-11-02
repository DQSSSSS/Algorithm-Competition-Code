#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 550010;
const int INF = 1e9 + 10;
const int mod = 7340033;
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
    double x,y;
	Complex(double a = 0,double b = 0) : x(a),y(b) {};
    Complex operator +(const Complex &o) const { return Complex(x+o.x,y+o.y); }
    Complex operator -(const Complex &o) const { return Complex(x-o.x,y-o.y); }
    Complex operator *(const Complex &o) const { return Complex(x*o.x-y*o.y,x*o.y+y*o.x); }
    void operator /=(const double &d) { x/=d; y/=d; }
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
        for(int i = 0;i < n;i ++) a[i] /= n;
    }

}fft;

Complex c1[SZ],c2[SZ];

void multiply(int a[],int n,int b[],int m,LL ans[]) {
	int len = 1;
	while(len < n + m) len <<= 1;
    for(int i = 0;i < n;i ++) c1[i] = a[i];
    for(int i = 0;i < m;i ++) c2[i] = b[i];
    fft.init(len); fft.dft(c1,len); fft.dft(c2,len);
    for(int i = 0;i < len;i ++) c1[i] = c1[i] * c2[i];
    fft.idft(c1,len);
	for(int i = 0;i < n + m - 1;i ++) ans[i] = floor(c1[i].x + 0.5);
}

int n,x;

void pre(int num[],int a[]) {
	int len = 0,s = 0;
    for(int i = 0;i < n;i ++){
        if(num[i] == 0) a[len ++] = s + 1,s = 0;
        else s ++;
    }
    a[len ++] = s + 1;
}

int a[SZ],b[SZ],num[SZ];
LL ans[SZ];

int main() {
    n = read(),x = read();
    for(int i = 0;i < n;i ++) {
    	int y = read();
        num[i] = y < x ? 0 : 1;
    }
    pre(num,a);
    n ++;
    for(int i = 0;i < n;i ++) b[i] = a[n - i - 1];
    //for(int i = 0;i < n;i ++) cout << a[i] << " "; puts("");
    //for(int i = 0;i < n;i ++) cout << b[i] << " "; puts("");
    multiply(a,n,b,n,ans);
    ans[n - 1] = 0;
    for(int i = 0;i < n;i ++) ans[n - 1] += 1ll * a[i] * (a[i] - 1) / 2;
   // for(int i = 0;i < 2 * n - 1;i ++) cout << ans[i] << " "; puts("");
    for(int i = n - 1;i < 2 * n - 1;i ++){
    	printf("%lld ",ans[i]);
    }
    return 0;
}
