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

LL f[SZ];
int rst[SZ];
int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
	f[1] = rst[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,f[i] = (1 + 1ll * i * (i - 1) % mod) % mod,rst[i] = 1;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                rst[m] = rst[i];
                LL pk = m / rst[m],p = pri[j];
                f[m] = f[rst[m]] * (f[pk / p] + pk * pk / p % mod * (p - 1) % mod) % mod;
           		break;
            }
            else {
				f[m] = f[i] * f[pri[j]] % mod;
                rst[m] = i;
            }
		}
    }
    for(int i = 1;i <= n;i ++) f[i] = (1ll * i * f[i] % mod + f[i - 1]) % mod;
}

LL f2[SZ];
LL N;
bool use[SZ];

inline LL sum3(LL n) { n %= mod; return n * (n + 1) % mod * 500000004 % mod * n % mod * (n + 1) % mod * 500000004 % mod; }
inline LL sum2(LL n) { n %= mod; return n * (n + 1) % mod * (2 * n + 1) % mod * 166666668 % mod; }
inline LL sum1(LL n) { n %= mod; return n * (n + 1) % mod * 500000004 % mod; }

LL dfs(LL n) {
    if(n <= 1e7) return f[n];
    LL t = N / n;
    if(use[t]) return f2[t];
    use[t] = 1;
    LL ans = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans += (sum1(r) - sum1(i - 1)) % mod * sum3(n / i) % mod) %= mod;
    }
    for(LL i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= dfs(n / i) * (sum2(r) - sum2(i - 1)) % mod) %= mod;
    }
    ans += mod; ans %= mod;
    return f2[t] = ans;
}

LL get(LL n) {
	LL ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int d = 1;d <= i;d ++)
			if(i % d == 0)
                (ans += 1ll * i * d % mod * d % mod) %= mod;
    return ans;
}

int main() {
	shai(1e7);
    N = read();
    printf("%lld\n",dfs(N));
    return 0;
}

