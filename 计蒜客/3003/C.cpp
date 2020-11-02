#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 3e5 + 10;
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

int n;
int A[SZ],B[SZ],C[SZ];
int ta[SZ],tb[SZ],tc[SZ];
Complex ta2[SZ],tb2[SZ],tc2[SZ];
LL sa[SZ],sb[SZ],sc[SZ];
Complex ab[SZ],ac[SZ],bc[SZ];

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read();
        for(int i = 1;i <= n;i ++) A[i] = read();
        for(int i = 1;i <= n;i ++) B[i] = read();
        for(int i = 1;i <= n;i ++) C[i] = read();
        int len = 262144;
        int maxn = 2e5;
        for(int i = 0;i <= len;i ++) {
            ta[i] = tb[i] = tc[i] = 0;
            ta2[i] = tb2[i] = tc2[i] = 0;
            sa[i] = sb[i] = sc[i] = 0;
        }
        for(int i = 1;i <= n;i ++) ta[A[i]] ++;
        for(int i = 1;i <= n;i ++) tb[B[i]] ++;
        for(int i = 1;i <= n;i ++) tc[C[i]] ++;
        for(int i = 1;i <= maxn;i ++) {
            ta2[i] = ta[i];
            tb2[i] = tb[i];
            tc2[i] = tc[i];
            sa[i] = sa[i-1] + ta[i];
            sb[i] = sb[i-1] + tb[i];
            sc[i] = sc[i-1] + tc[i];
        }
        LL ans = 0;
        if(n <= 1000) {
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= n;j ++) {
                    int a = A[i],b = B[j];
                    if(a==b) {
                        ans += sc[a+b]-sc[abs(a-b)];
                    }
                    else
                        ans += sc[a+b]-sc[abs(a-b)-1];
                }
        }
        else {
            fft.dft(ta2,len);
            fft.dft(tb2,len);
            fft.dft(tc2,len);
            for(int i = 0;i < len;i ++) ab[i] = ta2[i] * tb2[i];
            for(int i = 0;i < len;i ++) ac[i] = ta2[i] * tc2[i];
            for(int i = 0;i < len;i ++) bc[i] = tc2[i] * tb2[i];
            fft.idft(ab,len);
            fft.idft(bc,len);
            fft.idft(ac,len);

           /* for(int i = 1;i <= 10;i ++) printf("%d ",ta[i]); puts("");
            for(int i = 1;i <= 10;i ++) printf("%d ",tb[i]); puts("");
            for(int i = 1;i <= 10;i ++) printf("%d ",sa[i]); puts("");
            for(int i = 1;i <= 10;i ++) printf("%d ",sc[i]); puts("");
            for(int i = 1;i <= 10;i ++) printf("%lld ",(LL)(ab[i].x+0.5)); puts("");
*/
            for(int i = 1;i <= maxn;i ++) ans += ((LL)(ab[i].x+0.5)) * sc[i];
            for(LL i = maxn,tmp=0;i >= 1;tmp+=tb[i]*sc[i],i --) ans -= ta[i]*tmp;
            for(LL i = maxn,tmp=0;i >= 1;tmp+=ta[i]*sc[i],i --) ans -= tb[i]*tmp;
            for(LL i = 1;i <= maxn;i ++) ans -= ta[i]*tb[i]*sc[i];

            for(int i = 1;i <= maxn;i ++) ans += ((LL)(ac[i].x+0.5)) * sb[i];
            for(LL i = maxn,tmp=0;i >= 1;tmp+=tc[i]*sb[i],i --) ans -= ta[i]*tmp;
            for(LL i = maxn,tmp=0;i >= 1;tmp+=ta[i]*sb[i],i --) ans -= tc[i]*tmp;
            for(LL i = 1;i <= maxn;i ++) ans -= ta[i]*tc[i]*sb[i];

            for(int i = 1;i <= maxn;i ++) ans += ((LL)(bc[i].x+0.5)) * sa[i];
            for(LL i = maxn,tmp=0;i >= 1;tmp+=tb[i]*sa[i],i --) ans -= tc[i]*tmp;
            for(LL i = maxn,tmp=0;i >= 1;tmp+=tc[i]*sa[i],i --) ans -= tb[i]*tmp;
            for(LL i = 1;i <= maxn;i ++) ans -= tc[i]*tb[i]*sa[i];

            for(int i = 1;i <= maxn;i ++) ans += ta[i]*tb[i]*tc[i];
            for(int i = 1;i <= maxn;i ++) ans += ta[i]*tb[i]*sc[i-1];
            for(int i = 1;i <= maxn;i ++) ans += ta[i]*tc[i]*sb[i-1];
            for(int i = 1;i <= maxn;i ++) ans += tc[i]*tb[i]*sa[i-1];
        }
        printf("Case #%d: %lld\n",++ cc,ans);
    }
}
