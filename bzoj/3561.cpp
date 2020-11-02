#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 5e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const LD PI = acos(-1);

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
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

const int MAXN = 5e5;
int pri[SZ],tot,mu[SZ],f[SZ];
bool vis[SZ];

void shai(int n = MAXN) {
	mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
        	vis[m] = 1;
            if(i % pri[j] == 0) {
            	mu[m] = 0;
                break;
            }
            else {
            	mu[m] = -mu[i];
            }
        }
    }
}
LL mi[SZ],sum[SZ];

int main() {
    LL n = read(),m = read();
    if(n < m) swap(n,m);
    shai(n);
	LL ans = 0;
    for(int d = 1;d <= n;d ++) mi[d] = 1;
    for(int d = 1;d <= n;d ++) {
        for(int d1 = 1;1ll * d1 * d <= n;d1 ++)
            mi[d1] = 1ll * mi[d1] * d1 % mod,sum[d1] = (sum[d1 - 1] + mi[d1]) % mod;
        LL tmp = 0;
        for(int d1 = 1;1ll * d1 * d <= n;d1 ++)
        	if(mu[d1])
				(tmp += mi[d1] * mi[d1] % mod * mu[d1] * sum[n / d / d1] % mod * sum[m / d / d1] % mod) %= mod;
    	(ans += ksm(d,d) * tmp % mod) %= mod;
    }
    printf("%lld\n",ans);
	return 0;
}

