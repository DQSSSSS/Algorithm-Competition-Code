#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
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

int pri[SZ],tot = 0,mu[SZ];
bool vis[SZ];

void shai(int n) {
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

LL fib[SZ],nfib[SZ],g[SZ];

LL bl(int n,int m) {
	LL ans = 1;
    for(int i = 1;i <= n;i ++)
    	for(int j = 1;j <= m;j ++)
			ans *= fib[__gcd(i,j)];
	return ans;
}

int main() {

	shai(1e6);
    fib[0] = 0; fib[1] = 1; nfib[1] = 1; g[1] = 1;
	for(int i = 2;i <= 1e6;i ++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        nfib[i] = ksm(fib[i],mod - 2);
        g[i] = 1;
	}

	for(int d = 1;d <= 1e6;d ++) {
		for(int n = d;n <= 1e6;n += d) {
            int x = n / d;
            if(mu[x] == 0) continue;
            (g[n] *= (mu[x] == 1 ? fib[d] : nfib[d])) %= mod;
		}
	}
	g[0] = 1;
	//for(int i = 1;i <= 1e6;i ++) cout << i << " " << g[i] << endl;
	for(int i = 1;i <= 1e6;i ++) (g[i] *= g[i - 1]) %= mod;

	int T = read();
	while(T --) {
        int n = read(),m = read();
        if(n > m) swap(n,m);
		LL ans = 1;
		//for(int i = 1;i <= n;i ++) (ans *= ksm(g[i],1ll * (n / i) * (m / i))) %= mod;
		for(int i = 1,r;i <= n;i = r + 1) {
            r = min(n / (n / i),m / (m / i));
            LL tmp = g[r] * ksm(g[i - 1],mod - 2) % mod;
            (ans *= ksm(tmp,(1ll * n / i) * (m / i) % (mod - 1))) %= mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

