#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 15000010;
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
	a %= mod;
	while(b) {
		if(b & 1) ans = a *ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int g[233],cnt;

LL f[2][SZ],zssum;

void dp(int S) {
    f[0][0] = 1;
    zssum = 0;
    for(int i = 1;i <= cnt;i ++) zssum += g[i];
    for(int i = 1;i <= cnt;i ++) {
        int now = i & 1,lst = now ^ 1;
        for(int j = 0;j < g[i];j ++) {
            LL tot = 0;
            for(int k = j;k <= S * cnt - zssum;k += g[i]) {
                (tot += f[lst][k]) %= mod;
                if(k - j >= S) (tot -= f[lst][k - S]) %= mod;
                f[now][k] = tot;
            }
        }
    }
}

LL C(LL n,LL m) {
	LL ans = 1;
    for(LL i = n;i >= n - m + 1;i --)
    	(ans *= i % mod) %= mod;
	for(LL i = 1;i <= m;i ++) (ans *= ksm(i,mod - 2)) %= mod;
	return ans;
}

int main() {
    int S,q;
    scanf("%d%d",&S,&q);
    int s = S;
	for(int i = 2;i * i <= s;i ++)
    	if(s % i == 0) {
			s /= i; g[++ cnt] = i;
            if(s % i == 0) {
				while(q --) puts("0");
                return 0;
            }
    	}
    if(s != 1) g[++ cnt] = s;
    dp(S);
    int lst = cnt & 1;
    while(q --) {
    	LL n = read() - zssum;
    	if(n < 0) { puts("0"); continue; }
        LL lim = min(1ll * cnt,n / S);
		LL tt = n / S,rst = n - tt * S;
        LL ans = 0;
        for(int i = 0;i <= lim;i ++) {
            (ans += f[lst][i*S+rst]*C(tt-i+cnt-1,cnt-1)%mod) %= mod;
        }
        ans += mod; ans %= mod;
        printf("%lld\n",ans);
    }
	return 0;
}
