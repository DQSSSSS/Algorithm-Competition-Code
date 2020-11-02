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

LL f[SZ],phi[SZ];
int rst[SZ];
int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
	f[1] = rst[1] = phi[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,f[i] = (1 + 1ll * i * (i - 1) % mod) % mod,rst[i] = 1,phi[i] = i - 1;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                rst[m] = rst[i];
                LL pk = m / rst[m],p = pri[j];
                f[m] = f[rst[m]] * (1ll * f[pk / p] + pk * pk / p % mod * (p - 1) % mod) % mod;
                phi[m] = phi[i] * pri[j];
           		break;
            }
            else {
				f[m] = 1ll * f[i] * f[pri[j]] % mod;
                rst[m] = i;
                phi[m] = phi[i] * (pri[j] - 1);
            }
		}
    }
    for(int i = 1;i <= n;i ++) phi[i] = (i * phi[i]) % mod;
    for(int i = 1;i <= n;i ++) f[i] = (phi[i] + f[i - 1]) % mod;
}

unordered_map<LL,LL> f2;
int use[SZ];

inline LL sum2(LL n) { n %= mod; return n * (n + 1) % mod * ((2 * n + 1) % mod) % mod * 166666668 % mod; }
inline LL sum1(LL n) { n %= mod; return n * (n + 1) % mod * 500000004 % mod; }

LL dfs(LL n) {
    if(n <= 1e6) return 1ll * f[n];
    if(f2[n]) return f2[n];
    LL ans = sum2(n);
    for(LL i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= dfs(n / i) * ((sum1(r) - sum1(i - 1)) % mod) % mod) %= mod;
    }
    ans += mod; ans %= mod;
    return f2[n] = ans;
}

LL ask(LL n) {
    LL ans = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans += dfs(n / i) * ((r - i + 1) % mod) % mod) %= mod;
    }
    ans += n; ans %= mod; ans *= 500000004; ans %= mod;
    return ans;
}

int main() {
	shai(1e6);
    LL a = read(),b = read();
    LL ans = (ask(b) - ask(a - 1)) % mod;
    ans += mod; ans %= mod;
    printf("%lld",ans);
    return 0;
}


