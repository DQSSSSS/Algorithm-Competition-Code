#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 500010;
const LL INF = 1e18;
const int mod = 100003;
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

int fac[SZ],inv[SZ];

LL C(int n,int m) {
    if(n<m) return 0;
    if(n < mod && m < mod) {
        return 1ll * fac[n] * inv[m] % mod * inv[n-m] % mod;
    }
    else
        return C(n/mod,m/mod) * C(n%mod,m%mod) % mod;
}

int main() {
    fac[0] = 1;
    inv[1] = 1;
    inv[0] = 1;
    for(int i = 1;i <= 100010;i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    for(int i = 2;i < mod;i ++) inv[i] = (mod-1ll*mod/i*inv[mod%i]%mod) % mod;
    for(int i = 1;i < mod;i ++) inv[i] = 1ll * inv[i] * inv[i-1] % mod;
    int n = read(),m = read(),k = read();
    LL ans = (C(n+m,n) - C(n+m,n+1) + mod) % mod * C(n+m,k) % mod;
    cout << ans << endl;
}

/*


*/

