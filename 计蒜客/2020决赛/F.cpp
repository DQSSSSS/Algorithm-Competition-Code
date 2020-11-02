#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

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

int C(int n,int m) {
    if(n<m) return 0;
    return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main() {
    int n = read(),m = read();
    fac[0] = 1; inv[1] = 1; inv[0] = 1;
    for(int i = 1;i <= 1e6;i ++) fac[i] = 1ll*fac[i-1]*i%mod;
    for(int i = 2;i <= 1e6;i ++) inv[i] = (mod-1ll*mod/i*inv[mod%i]%mod)%mod;
    for(int i = 1;i <= 1e6;i ++) inv[i] = 1ll*inv[i-1]*inv[i]%mod;
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        (ans += 1ll*C(n,i) * C(m-1,i-1)) %= mod;
    }
    cout << ans << endl;
}


