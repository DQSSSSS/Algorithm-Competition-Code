#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL inv[SZ],fac[SZ],n = 100000,biao[110][110];

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

LL C(LL n,LL m) {
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    fac[0] = 1;
    for(LL i = 1;i <= n;i ++) fac[i] = fac[i - 1] * i % mod;
    inv[n] = ksm(fac[n],mod - 2);
    for(LL i = n - 1;i >= 0;i --) inv[i] = inv[i + 1] * (i + 1) % mod;
	for(int i = 0;i <= n;i += 1000) {
		LL ans = 0;
		for(int j = 0;j <= i;j ++) {
			(ans += C(i,j)) %= mod;
            if(j % 1000 == 0)
            	biao[i / 1000][j / 1000] = ans;
		}
	}
	int T = read(),B = 1000;
	while(T --) {
        int n = read(),m = read();
        LL ans = biao[n / B][m / B],dn = n % B,dm = m % B;
        for(int i = 1;i <= dn;i ++) {
            int nown = n / B * B + i;
            int nowm = m / B * B;
            ans = (ans * 2 - C(nown - 1,nowm)) % mod;
        }
        for(int i = 1;i <= dm;i ++)
        	(ans += C(n,m / B * B + i)) %= mod;
		printf("%lld\n",(ans + mod) % mod);
	}
	return 0;
}
