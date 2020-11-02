#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

bool vis[SZ];
int pri[SZ],tot = 0;
const int MAXN = 1e6;
LL d[SZ],mu[SZ],sd[SZ],d2[SZ];
LL f[SZ],g[SZ];
LL pk[SZ],spk[SZ],spk2[SZ];

void shai(int n) {
	d[1] = mu[1] = spk[1] = spk2[1] = d2[1] = pk[1] = 1;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,mu[i] = -1,d[i] = i + 1,pk[i] = i,spk[i] = 1 + i,spk2[i] = 1 + i + 1ll * i * i,d2[i] = spk2[i];
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
            	mu[m] = 0;
            	pk[m] = pk[i] * pri[j];
				spk[m] = spk[i] + pk[m];
				spk2[m] = (1 + pk[m]) * spk[m] - pk[m];
                d[m] = d[i] / spk[i] * spk[m] ;
            	d2[m] = d2[i] / spk2[i] * spk2[m] ;
            	break;
            }
            else {
            	mu[m] = -mu[i];
            	pk[m] = pri[j];
            	spk[m] = 1 + pri[j];
            	spk2[m] = 1 + pri[j] + 1ll * pri[j] * pri[j];
            	d[m] = d[i] * d[pri[j]];
				d2[m] = d2[i] * d2[pri[j]];
            }
        }
	}
	for(int i = 1;i <= n;i ++) {
		g[i] = (g[i - 1] + i * d2[i] % mod) % mod;
        sd[i] = (sd[i - 1] + d[i]) % mod;
	}
	for(int i = 1;i <= n;i ++) {
		if(mu[i])
			for(int j = i;j <= n;j += i) {
				LL x = j / i;
				(f[j] += mu[i] * i * j % mod * sd[x] % mod * d[x] % mod) %= mod;
			}
        (f[i] += f[i - 1]) %= mod;
    }
}

int main() {
	shai(MAXN);
	int T = read(),cc = 0;
	while(T --) {
		int n = read();
		LL ans = 2 * f[n] - g[n];
		ans %= mod; ans += mod; ans %= mod;
    	printf("Case #%d: %lld\n",++ cc,ans);
	}
	return 0;
}

