#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 3e5 + 10;
const double PI = acos(-1);

struct Complex {
    double x,y;
    Complex(double x = 0,double y = 0) :x(x),y(y) {}
    Complex operator *(const Complex &o) const { return Complex(x*o.x-y*o.y,x*o.y+y*o.x); }
    void operator /=(const double &o) { x /= o, y /= o; }
    Complex operator +(const Complex &o) { return Complex(x+o.x,o.y+y); }
    Complex operator -(const Complex &o) { return Complex(x-o.x,y-o.y); }
};

struct FFT {
    void Transform(Complex a[],int n,const int opt) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i>j) swap(a[i],a[j]);
            for(int k =  n>>1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l <<= 1) {
            int m = l / 2;
            Complex wn = Complex(cos(2*PI/l),opt*sin(2*PI/l));
            for(Complex *p = a;p != a + n;p += l) {
                Complex w = Complex(1,0);
                for(int i = 0;i < m;i ++,w = w * wn) {
                    Complex t = w * p[i+m];
                    p[i+m] = p[i] - t;
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
        for(int i = 0;i < n;i ++) a[i] /= n;
    }
}fft;

void multiply(int a[],int n,int b[],int m,int c[]) {
    static Complex c1[SZ],c2[SZ];
    int len = 1;
    while(len < n+m) len *= 2;
    for(int i = 0;i < len;i ++) c1[i] = c2[i] = 0;
    for(int i = 0;i < n;i ++) c1[i] = a[i];
    for(int i = 0;i < m;i ++) c2[i] = b[i];
    fft.dft(c1,len);
    fft.dft(c2,len);
    for(int i = 0;i < len;i ++) c1[i] = c1[i] * c2[i];
    fft.idft(c1,len);
    for(int i = 0;i < n+m-1;i ++) c[i] = c1[i].x + 0.5;
}

int n,m;
char s[SZ],t[SZ];
int A[SZ],a[SZ],b[SZ],c[SZ];

void work(char c1,char c2) {
    for(int i = 0;i < n;i ++) a[i] = s[i] == c1 ? 1 : 0;
    for(int i = 0;i < m;i ++) b[i] = t[i] == c2 ? 1 : 0;
    multiply(a,n,b,m,c);
    for(int i = 0;i < n+m-1;i ++) A[i] += c[i];

    //for(int i = 0;i < n;i ++) printf("%d",a[i]); puts("");
    //for(int i = 0;i < m;i ++) printf("%d",b[i]); puts("");
    //for(int i = 0;i < n+m-1;i ++) printf("%d",c[i]); puts("");
}

int main() {
    scanf("%d%d%s%s",&n,&m,s,t);
    reverse(t,t+m);
    work('S','R');
    work('P','S');
    work('R','P');
    int ans = 0;
    for(int i = m-1;i < n+m-1;i ++) {
        ans = max(ans,A[i]);
    }
    cout << ans << endl;
}
