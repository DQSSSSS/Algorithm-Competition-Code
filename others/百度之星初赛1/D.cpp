#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 2010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

LL f[SZ],C[SZ][SZ],fac[SZ],mi[SZ],g[SZ];

LL ask(LL n,LL k) {
	return C[n][k] % mod * C[n][k] % mod * fac[k] % mod * mi[k] % mod;
}

int main() {
	f[0] = 1; f[1] = 0;
    for(int i = 2;i <= 1000;i ++) f[i] = (i - 1) * ((f[i - 1] + f[i - 2]) % mod) % mod;
  	fac[0] = 1;
    for(int i = 1;i <= 2000;i ++) fac[i] = i * fac[i - 1] % mod;
    mi[0] = 1;
    for(int i = 1;i <= 2000;i ++) mi[i] = 2 * mi[i - 1] % mod;
	C[0][0] = 1;
	for(int i = 1;i <= 1000;i ++) {
		C[i][0] = 1;
		for(int j = 1;j <= i;j ++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}

	for(int n = 1;n <= 1000;n ++) {
		for(int k = 0;k <= n;k ++) {
			LL d = ;
            if(k & 1) g[n] += d;
            else g[n] -= d;
		}
	}
	for(int i = 1;i <= 10;i ++) cout << g[i] << endl;

	LL n,D;
	while(~scanf("%lld%lld",&n,&D)) {
		LL ans = 0,d = 1;
		for(int k = 0;k <= n;k ++) {
			LL a = C[n][k] % mod * C[n][k] % mod * fac[k] % mod * mi[k] % mod;
			LL b = g[n - k] % mod;
			(ans += d * a % mod * b % mod) %= mod;
			d = d * D % mod;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
