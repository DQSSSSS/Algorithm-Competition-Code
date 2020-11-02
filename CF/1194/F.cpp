#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL fac[SZ],invfac[SZ];

LL C(int n,int m) {
    return fac[n] * invfac[m] % mod * invfac[n-m] % mod;
}

LL nn = 0,mm = 0,aa = 1;

LL ask(LL n,LL m) {
    if(m < 0) return 0;
    m = min(n,m);
    while(n > nn) aa = (2 * aa - C(nn,mm) + mod) % mod,nn ++;
    while(m > mm) aa = (aa + C(nn,mm+1)) % mod,mm ++;
    while(m < mm) aa = (aa - C(nn,mm) + mod) % mod,mm --;
    return aa;
}

int a[SZ];

int main() {
    int n = read();
    LL T = read();
    fac[0] = 1;
    for(int i = 1;i <= n;i ++) fac[i] = 1ll * i * fac[i-1] % mod;
    for(int i = 0;i <= n;i ++) invfac[i] = ksm(fac[i],mod - 2);
    for(int i = 1;i <= n;i ++) a[i] = read();
    LL ans = 0,sum = 0;
    for(int i = 1;i <= n;i ++) {
        sum += a[i];
        LL tmp = ksm(2,n-i) * (ask(i-1,T-sum) + ask(i-1,T-sum-1)) % mod;
        (ans += tmp) %= mod;
    }
    ans = ans * ksm(ksm(2,n),mod-2) % mod;
    ans += mod; ans %= mod;
    cout << ans << endl;
}
