#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
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
	while(b){
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int C[3100][3100],B[3100],inv[3100];

void pre() {
	C[0][0] = 1;
	for(int i = 1;i <= 3010;i ++) {
		C[i][0] = 1;
		for(int j = 1;j <= i;j ++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	inv[1] = 1;B[0] = 1;
	for(int i = 2;i <= 3010;i ++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1;i <= 3009;i ++) {
		for(int j = 0;j <= i - 1;j ++)
			(B[i] += 1ll * C[i + 1][j] * B[j] % mod) %= mod;
		B[i] = -1ll * B[i] * inv[i + 1] % mod;
	}
}

namespace poly {

	int a[3100];

	void pre_poly(int m) {
		pre();
		for(int i = 1;i <= m + 1;i ++) a[i] = 0;
		int x = ksm(m + 1,mod - 2);
		for(int k = 1;k <= m + 1;k ++) a[k] = 1ll * C[m + 1][m + 1 - k] * B[m + 1 - k] % mod * x % mod;
		if(m) a[m] ++;
	}
	
	LL mi(int n,int m) {
		//pre_poly(m);
		LL ans = 0;
		for(int k = 1;k <= m + 1;k ++) {
			(ans += a[k] * ksm(n,k) % mod) %= mod;
		}
		ans += mod; ans %= mod;
		return ans;
	}
}

int p[SZ],a[SZ];

int main() {
	int m = read(),w = read(),n = 1;
	poly :: pre_poly(m);
	for(int i = 1;i <= w;i ++) {
		p[i] = read(),a[i] = read();
		n = 1ll * n * ksm(p[i],a[i]) % mod;
	}
	LL ans = 0;
	for(int j = 1;j <= m + 1;j ++) {
		LL b = 1;
		for(int i = 1;i <= w;i ++) {
			LL tmp = 0;
			LL pri = p[i],mi = m - j;
			if(mi < 0) pri = ksm(ksm(pri,-mi),mod - 2);
			else pri = ksm(pri,mi);
			b = 1ll * b * (1 - pri) % mod;
		}
		b = b * poly::a[j] % mod * ksm(n,j) % mod;
		(ans += b) %= mod;
	}
	ans += mod; ans %= mod;
	cout << ans << endl;
	return 0;
}
/**
3 2
2 1
5 1
*/
