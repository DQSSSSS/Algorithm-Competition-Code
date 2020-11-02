#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL ksm(LL a,LL b,LL p) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % p;
        a = a *a % p;
        b >>= 1;
    }
    return ans;
}

LL mul(LL a,LL b,LL p) {
    return a * a% p;
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

LL get(LL x) {
    LL f[111]; f[0] = 0;
    Pr::findfac(x,f);
    sort(f+1,f+1+f[0]);
    LL ans = 1;
    for(int i = 1,j = 1;i <= f[0];i ++) {
        if(i == f[0] || f[i] != f[i+1]) {
            if(f[i] % 4 == 1) ans *= 3*(i-j+1)+1;
            j = i + 1;
        }
    }
    return ans;
}

int main() {
    freopen("biao.out","w",stdout);
    LL ans = 0;
    printf("{");
    for(int i = 1;i <= 1e9;i ++) {
        ans += get(i);
        if(i%100000 == 0)
            printf("%lld,",ans);
    }
    printf("}");
}
