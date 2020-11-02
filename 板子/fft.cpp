#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1 << 18;
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

struct Complex {
    double x,y;
    Complex(double x = 0,double y = 0) :x(x),y(y) {}
    Complex operator *(const Complex &o) const { return Complex(x*o.x-y*o.y,x*o.y+y*o.x);}
    void operator /=(const double &o) { x /= o; y /= o;}
    Complex operator +(const Complex &o) const { return Complex(x + o.x,y + o.y);}
    Complex operator -(const Complex &o) const { return Complex(x - o.x,y - o.y);}
};


struct FFT {
    void Transform(Complex a[],int n,const int opt) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i > j) swap(a[i],a[j]);
            for(int k = n >> 1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l <<= 1) {
            int m = l / 2;
            Complex wn = (Complex){cos(2*PI/l),opt*sin(2*PI/l)};
            for(Complex *p = a;p != a + n;p += l) {
                Complex w = (Complex){1,0};
                for(int i = 0;i < m;i ++,w = w * wn) {
                    Complex t = w * p[i + m];
                    p[i + m] = p[i] - t;
                    p[i] = p[i] + t;
                }
            }
        }
    }
    void dft(Complex a[],int n) {
        Transform(a,n,1);
    }

    void idft(Complex a[],int n) {
        Transform(a,n,-1);
        for(int i = 0;i < n;i ++) {
            a[i].x /= n;
            a[i].y /= n;
        }
    }
}fft;

void multiply(int *a1,int n1,int *a2,int n2,int *res) {
	int n = 1;
	while(n < n1 + n2) n *= 2;
	static Complex c1[SZ],c2[SZ];
	for(int i = 0;i < n1;i ++) c1[i]=a1[i];
	for(int i = 0;i < n2;i ++) c2[i]=a2[i];
	fft.dft(c1,n); fft.dft(c2,n);
	for(int i = 0;i < n;i ++) c1[i] = c1[i]*c2[i];
	fft.idft(c1,n);
	for(int i = 0;i < n1 + n2 - 1;i ++) res[i] = c1[i].x+0.5;
}

char s[SZ];
int a[SZ],b[SZ],res[SZ];

int main() {
	int n = read() + 1,m = read() + 1;
	for(int i = 0;i < n;i ++) a[i] = read();
	for(int i = 0;i < m;i ++) b[i] = read();
	multiply(a,n,b,m,res);
	for(int i = 0;i < n + m - 1;i ++) printf("%d ",res[i]);
	return 0;
}

