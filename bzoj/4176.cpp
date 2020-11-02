#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

bool vis[SZ];
int pri[SZ],tot = 0;
const int MAXN = 1e6;
LL dcnt[SZ],mu[SZ],pmi[SZ];

void shai(int n) {
	dcnt[1] = mu[1] = dcnt[1] = pmi[1] = 1;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,mu[i] = -1,dcnt[i] = 2,pmi[i] = 1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
            	mu[m] = 0;
				pmi[m] = pmi[i] + 1;
                dcnt[m] = dcnt[i] / (pmi[i] + 1) * (pmi[m] + 1);
            	break;
            }
            else {
            	mu[m] = -mu[i];
            	pmi[m] = 1;
            	dcnt[m] = dcnt[i] * 2;
            }
        }
        (dcnt[i] += dcnt[i - 1]) %= mod;
        (mu[i] += mu[i - 1]) %= mod;
	}
}

LL f(LL n) {
    if(n <= MAXN) return dcnt[n];
	LL ans = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans += (n / i) * (r - i + 1) % mod) %= mod;
    }
    return ans;
}

LL N,mu2[SZ];
bool use[SZ];

LL dfs(LL n) {
	if(n <= MAXN) return mu[n];
    LL t = N / n;
    if(use[t]) return mu2[t];
	use[t] = 1;
    LL ans = 1;
    for(LL i = 2,r;i <= n;i = r + 1) {
    	r = n / (n / i);
        (ans -= dfs(n / i) * (r - i + 1) % mod) %= mod;
    }
    return mu2[t] = ans;
}

int main() {
	shai(MAXN);
	N = read();
    LL ans = 0,n = N;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        LL x = f(n / i);
        ans += (dfs(r) - dfs(i - 1)) % mod * x % mod * x % mod;
        ans %= mod;
    }
    if(ans < 0) ans += mod;
    printf("%lld\n",ans);
	return 0;
}

