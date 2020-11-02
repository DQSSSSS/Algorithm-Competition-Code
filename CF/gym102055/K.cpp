#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

inline LL mul(LL x,LL y,LL z) {
    return (x*y-(LL)(((long double)x*y+0.5)/(long double)z)*z+z)%z;
}

LL ksm(LL a,LL b,LL mod) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = mul(ans,a,mod);
        a = mul(a,a,mod);
        b >>= 1;
    }
    return ans;
}

void exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    LL t = x; x = y;
    y = t - a / b * y;
}

pll get(LL n) {
    LL gen = sqrt(n);
    for(LL i = gen;i >= 2;i --)
        if(n % i==0)
            return make_pair(i,n/i);
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        LL n = read(),c = read();
        pll a = get(n);
        LL phi = (a.first-1)*(a.second-1),x,y;
        exgcd((1<<30)+3,phi,x,y);
        x%=phi; x+=phi; x%=phi; x+=phi;
        LL ans = ksm(c,x,n);
        printf("Case %d: %lld\n",++ cc,ans);
    }
}
/**
3
181857896263 167005790444
218128229323 156323229335
352308724847 218566715941
*/

