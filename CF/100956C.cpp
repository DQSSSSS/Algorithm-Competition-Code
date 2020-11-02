#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
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

void exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    LL t = x; x = y; y = t - a / b * y;
}

LL inv(LL a,LL m) {
    LL x,k;
    exgcd(a,m,x,k);
    return x;
}

LL ksm(LL a,LL b,LL mod) {
    LL ans = 1 % mod;
    while(b) {
        if(b&1) ans = mul(a,ans,mod);
        a = mul(a,a,mod);
        b >>= 1;
    }
    return ans;
}


namespace MR {
    bool check(LL a,LL n,LL x,LL t) {
        LL ans = ksm(a,x,n),lst = ans;
        for(int i = 1;i <= t;i ++) {
            ans = mul(ans,ans,n);
            if(ans == 1 && lst != 1 && lst != n - 1) return true;
            lst = ans;
        }
        if(ans != 1) return true;
        return false;
    }
    const int S = 8;
    bool Miller_Rabin(LL n) {
        if(n < 2) return false;
        if(n == 2) return true;
        if((n & 1) == 0) return false;
        LL x = n - 1,t = 0;
        while((x & 1) == 0) x >>= 1,t ++;
        for(int i = 0;i < S;i ++) {
            LL a = rand() % (n - 1) + 1;
            if(check(a,n,x,t)) return false;
        }
        return true;
    }
}

namespace Pr {
    LL Pollard_rho(LL x,LL c) {
        LL i = 1,k = 2,x0 = rand() % (x - 1) + 1,y = x0;
        while(1) {
            i ++;
            x0 = (mul(x0,x0,x) + c) % x;
            LL d = __gcd(abs(y-x0),x);
            if(d != 1 && d != x) return d;
            if(y == x0) return x;
            if(i == k) y = x0,k <<= 1;
        }
    }

    void findfac(LL n,LL factor[]) {
        if(n == 1) return ;
        if(MR :: Miller_Rabin(n)) {
            factor[++ factor[0]] = n;
            return ;
        }
        LL p = n;
        while(p >= n) p = Pollard_rho(n,rand() % (n - 1) + 1);
        findfac(p,factor); findfac(n/p,factor);
    }
}

LL fac[SZ];
int n,m;
LL a[SZ],b[SZ];

void getFac(LL M,LL fac[]) {
    fac[0] = 0;

    Pr::findfac(M,fac); return ;


}

void work(LL M) {
    getFac(M,fac);
    sort(fac+1,fac+1+fac[0]);
    vector<pll> g;
    for(int i = 1,lst = 1;i <= fac[0];i ++) {
        if(i == fac[0] || fac[i]!=fac[i+1]) {
            LL p = fac[i],t = i-lst+1;
            g.push_back(make_pair(p,t));
            lst = i + 1;
        }
    }

    LL ans = 1;
    for(auto gg : g) {
        LL p = gg.first;
        LL t = gg.second;
        LL nta = 0,ntb = 0;
        for(int i = 1;i <= n;i ++) {
            LL x = a[i];
            while(x % p == 0) x /= p,nta ++;
        }
        for(int i = 1;i <= m;i ++) {
            LL x = b[i];
            while(x % p == 0) x /= p,ntb ++;
        }
        LL tt = nta - ntb;
        if(nta < ntb) {
            puts("DIVISION BY ZERO");
            return;
        }
        for(int i = 1;i <= nta - ntb;i ++)
            ans = mul(ans,p,M);
    }

    for(int i = 1;i <= n;i ++) {
        LL x = a[i];
        for(auto gg : g) {
            LL p = gg.first;
            while(x % p == 0) x /= p;
        }
        ans = mul(ans,x,M);
    }
    for(int i = 1;i <= m;i ++) {
        LL x = b[i];
        for(auto gg : g) {
            LL p = gg.first;
            while(x % p == 0) x /= p;
        }
        ans = mul(ans,inv(x,M),M);
    }
    printf("%lld\n",ans);
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= m;i ++) b[i] = read();
    int k = read();
    while(k --) {
        LL M = read();
        work(M);
    }
}
