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
LL d[SZ],mu[SZ],pk[SZ];

void shai(int n) {
	d[1] = mu[1] = pk[1] = 1;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,mu[i] = -1,d[i] = i + 1,pk[i] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
            	mu[m] = 0;
				pk[m] = pk[i] * pri[j];
                d[m] = (d[i] + d[m / pk[m]] * pk[m] % mod) % mod;
            	break;
            }
            else {
            	mu[m] = -mu[i];
            	pk[m] = pri[j];
            	d[m] = d[i] * d[pri[j]];
            }
        }
        //cout << i << " " << d[i] << endl;
	}
	for(int i = 1;i <= n;i ++) (d[i] += d[i - 1]) %= mod,(mu[i] = 1ll * mu[i] * i % mod + mu[i - 1]) %= mod;
}

LL sum1(LL n) { n %= mod; return n * (n + 1) % mod * 500000004 % mod; }

LL f(LL n) {
    if(n <= MAXN) return d[n];
	LL ans = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans += (n / i) * ((sum1(r) - sum1(i - 1)) % mod) % mod) %= mod;
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
        (ans -= dfs(n / i) * ((sum1(r) - sum1(i - 1)) % mod) % mod) %= mod;
    }
    return mu2[t] = ans;
}

int main() {
	shai(MAXN);
	N = read();
    LL ans = 0,n = N;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        LL x = f(n / i),y = (dfs(r) - dfs(i - 1)) % mod;
        ans += y % mod * x % mod * x % mod;
        ans %= mod;
    //	cout << i << " " << y << " " << n / i << " " << x << endl;
    }
    if(ans < 0) ans += mod;
    printf("%lld\n",ans);
	return 0;
}
