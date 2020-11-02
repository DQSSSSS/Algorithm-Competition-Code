#include <bits/stdc++.h>
using namespace std;

typedef __int128 LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int s1[SZ],s2[SZ],ifac[SZ];

int lagrange(int n, int *x, int *y, int xi) {
    int ans = 0;
    s1[0] = (xi-x[0])%mod, s2[n+1] = 1;
    for (int i = 1; i <= n; i++) s1[i] = 1ll*s1[i-1]*(xi-x[i])%mod;
    for (int i = n; i >= 0; i--) s2[i] = 1ll*s2[i+1]*(xi-x[i])%mod;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = -1ll*mod/i*ifac[mod%i]%mod;
    for (int i = 2; i <= n; i++) ifac[i] = 1ll*ifac[i]*ifac[i-1]%mod;
    for (int i = 0; i <= n; i++)
        (ans += 1ll*y[i]*(i == 0 ? 1 : s1[i-1])%mod*s2[i+1]%mod
            *ifac[i]%mod*(((n-i)&1) ? -1 : 1)*ifac[n-i]%mod) %= mod;
    return (ans+mod)%mod;
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a *a % mod;
        b >>= 1;
    }
    return ans;
}

int fib[SZ],X[SZ],Y[SZ];

int main() {
    int n = read(),m = read();
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2;i <= m;i ++) {
        fib[i] = (fib[i-1] ++ fib[i-2]) % mod;
    }
    for(int i = 2;i <= m;i ++) {

    }
    int n = read(),m = read();

}
