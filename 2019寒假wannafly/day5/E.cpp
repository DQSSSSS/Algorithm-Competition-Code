#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

const double PI = acos(-1);

struct Complex {
    double x,y;
    Complex(double a=0,double b=0) { x = a; y = b; }
    Complex operator+(Complex &o) const { return (Complex){x+o.x,y+o.y}; }
    Complex operator-(Complex &o) const { return (Complex){x-o.x,y-o.y}; }
    Complex operator*(Complex &o) const { return (Complex){x*o.x-y*o.y,x*o.y+y*o.x}; }
    Complex operator/(int n) const { return (Complex){x/n,y/n}; }
};

struct FFT {
    Complex wn[SZ],wnInv[SZ];
    void init(int n) {
        for(int i = 0;i < n;i ++) {
            wn[i] = (Complex){cos(2 * PI / n * i),sin(2 * PI / n * i)};
            wnInv[i] = wn[i]; wnInv[i].y = -wnInv[i].y;
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
        for(int i = 0;i < n;i ++) a[i] = a[i] / n;
    }

}fft;

vector<int> ga[200010];
vector<int> gb[200010];

int n,m,a[SZ],b[SZ],len,lsh[SZ];
LL c[SZ];

Complex c1[SZ],c2[SZ];

void work(int id) {
    for(int i = 0;i < len;i ++) c1[i] = c2[i] = 0;
    for(int i = 0;i < ga[id].size();i ++) {
        c1[ga[id][i]] = ga[id][i];
    }
    for(int i = 0;i < gb[id].size();i ++) {
        c2[gb[id][i]] = gb[id][i];
    }
    //cout << lsh[id] << endl;
    //for(int i = 0;i <= n;i ++) cout << c1[i].x << " "; puts("");
    //for(int i = 0;i <= m;i ++) cout << c2[i].x << " "; puts("");
    fft.dft(c1,len);
    fft.dft(c2,len);
    for(int i = 0;i < len;i ++) c1[i] = c1[i] * c2[i];
    fft.idft(c1,len);
    for(int i = 0;i <= n + m;i ++) c[i] += c1[i].x + 0.5;
}

int main() {
    n = read(),m = read();
    for(int i = 0;i <= n;i ++) a[i] = read(),lsh[++lsh[0]]=a[i];
    for(int i = 0;i <= m;i ++) b[i] = read(),lsh[++lsh[0]]=b[i];
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
    for(int i = 0;i <= n;i ++) {
        int x = lower_bound(lsh+1,lsh+1+lsh[0],a[i])-lsh;
        ga[x].push_back(i);
    }
    for(int i = 0;i <= m;i ++) {
        int x = lower_bound(lsh+1,lsh+1+lsh[0],b[i])-lsh;
        gb[x].push_back(i);
    }

    len = 1;
    while(len < n + m + 2) len <<= 1;
    fft.init(len);

    int T = 10000;
    for(int i = 1;i <= lsh[0];i ++) {
        if(ga[i].size() > T && gb[i].size() > T) {
            work(i);
        }
        else {
            for(int j = 0;j < ga[i].size();j ++)
                for(int k = 0;k < gb[i].size();k ++)
                    c[ga[i][j]+gb[i][k]] += 1ll*ga[i][j]*gb[i][k];
        }
    }
    for(int i = 0;i <= n + m;i ++)
        printf("%lld%c",c[i]%mod," \n"[i == n+m]);
    return 0;
}
