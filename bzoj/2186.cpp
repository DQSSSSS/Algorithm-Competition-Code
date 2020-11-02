#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 10000010;
const int INF = 1e9 + 10;
//const int mod = 1e9 + 7;
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

bool vis[SZ];
int pri[SZ],tot;
int fac[SZ],inv[SZ],f[SZ],mod;

void shai(int n) {
    fac[0] = fac[1] = inv[1] = f[1] = 1;
    for(register int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
        	vis[m] = 1;
            if(i % pri[j] == 0) {
            	break;
            }
            else {
            }
        }
        fac[i] = 1ll * fac[i - 1] * i % mod;
   		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
        if(!vis[i]) f[i] = 1ll * f[i - 1] * (i - 1) % mod * inv[i] % mod;
       	else f[i] = f[i - 1];
    }
}

int main() {
	int T = read();
	mod = read();
	shai(1e7);
	while(T --) {
		int n = read(),m = read();
		LL ans = 1ll * fac[n] * f[m] % mod;
        printf("%lld\n",ans);
	}
	return 0;
}
