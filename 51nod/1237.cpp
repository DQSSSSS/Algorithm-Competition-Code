#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 10000010;
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

int f[SZ],rst[SZ],cnt[SZ];
int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
	f[1] = rst[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,f[i] = (2ll * i - 1) % mod,rst[i] = 1,cnt[i] = 1;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                rst[m] = rst[i];
                cnt[m] = cnt[i] + 1;
                LL pk = m / rst[m],p = pri[j];
                f[m] = 1ll * f[rst[m]] * (pk + pk / p * (p - 1) % mod * cnt[m] % mod) % mod;
           		break;
            }
            else {
				f[m] = 1ll * f[i] * f[pri[j]] % mod;
                rst[m] = i;
                cnt[m] = 1;
            }
		}
    }
    for(int i = 1;i <= n;i ++) f[i] = (1ll * f[i] + f[i - 1]) % mod;
}

int f2[SZ];
LL N;
bool use[SZ];

inline LL sum1(LL n) { n %= mod; return n * (n + 1) % mod * 500000004 % mod; }

LL dfs(LL n) {
    if(n <= 1e7) return 1ll * f[n];
    LL t = N / n;
    if(use[t]) return 1ll * f2[t];
    use[t] = 1;
    LL ans = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans += (sum1(r) - sum1(i - 1)) % mod * sum1(n / i) % mod) %= mod;
    }
    for(LL i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= dfs(n / i) * ((r - i + 1) % mod) % mod) %= mod;
    }
    ans += mod; ans %= mod;
    return f2[t] = ans;
}

int main() {
	shai(1e7);
    N = read();
    LL ans = dfs(N);
    (ans *= 2) %= mod; ans -= N % mod * ((N + 1) % mod) % mod * 500000004 % mod;
    ans %= mod;
    ans += mod; ans %= mod;
    printf("%lld\n",ans);
    return 0;
}

/**
10000000000
447077130
*/
