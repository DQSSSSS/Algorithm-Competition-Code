#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL f(int n,int k) {
    if(n == k) return 1;
    return k * ksm(n,n-k-1)%mod;
}

LL inv[SZ],fac[SZ];

LL C(int n,int m) {
    if(m > n) return 0;
    return fac[n] * inv[n-m] % mod * inv[m] % mod;
}

int main() {
    int n = read(),m = read(),a = read(),b = read();
    inv[0] = fac[0] = 1;
    for(int i = 1;i <= 1e6;i ++)
        fac[i] = fac[i - 1] * i % mod,inv[i] = ksm(fac[i],mod-2);

    LL ans = 0;
    for(int k = 1;k < n;k ++) {
        LL x = C(n-2,k-1)*fac[k-1]%mod*C(m-1,k-1)%mod*ksm(m,n-k-1)%mod*f(n,k+1)%mod;
        (ans += x) %= mod;
    }
    cout << ans << endl;
}
