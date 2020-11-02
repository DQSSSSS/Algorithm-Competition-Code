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

LL f[SZ];

void shai(int n) {
    for(int i = 1;i <= n;i ++) f[i] = 1ll * (i - 1) * (i - 2);
    for(int i = 1;i <= n;i ++)
    	for(int j = 2 * i;j <= n;j += i)
    		f[j] -= f[i];
    for(int i = 1;i <= n;i ++) (f[i] += f[i - 1]) %= mod;
}

LL f2[SZ],cnt = 0,N;
int use[SZ];

LL dfs(LL n) {
    if(n <= 1e6) return f[n];
    LL t = N / n;
    if(use[t] == cnt) return f2[t];
    LL ans = n * (n - 1) % mod * (n - 2) % mod * 333333336 % mod;
    for(LL i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= dfs(n / i) * (r - i + 1) % mod) %= mod;
    }
    use[t] = cnt;
    return f2[t] = ans;
}

int main() {
	shai(1e6);
    int T = read();
    while(T --) {
		N = read(); cnt ++;
        LL ans = dfs(N);
        ans += mod; ans %= mod;
        printf("%lld\n",ans);
    }
    return 0;
}

