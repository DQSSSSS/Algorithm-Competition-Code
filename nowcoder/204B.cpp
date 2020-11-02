#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 550010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[SZ];
int ls[SZ][2],rs[SZ][2];
int b[2][32],mi[32],n;

LL baoli() {
	LL ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = i + 1;j <= n;j ++)
			for(int k = j + 1;k <= n;k ++)
				(ans += 1ll * (a[i] ^ a[j]) * (a[j] ^ a[k]) % mod * (a[k] ^ a[i]) % mod) %= mod;
	return ans;
}

int main() {
	n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	mi[0] = 1;
	for(int i = 1;i < 30;i ++) mi[i] = mi[i - 1] * 2 % mod;
	int ans = 0;
	for(int l = 0;l < 30;l ++) {
		memset(b,0,sizeof b);
		for(int i = 1;i <= n;i ++) 
			for(int j = 0;j <= 1;j ++)
				ls[i][j] = rs[i][j] = 0;
		for(int i = 1,b0 = 0,b1 = 0;i <= n;i ++) {
			for(int j = 0;j < 30;j ++) {
				if(a[i] >> j & 1) {
					(ls[i][0] += 1ll * mi[j] * (b0 - b[0][j]) % mod) %= mod;
					(ls[i][1] += 1ll * mi[j] * (b1 - b[1][j]) % mod) %= mod;
				}
				else {
					(ls[i][0] += 1ll * mi[j] * b[0][j] % mod) %= mod;
					(ls[i][1] += 1ll * mi[j] * b[1][j] % mod) %= mod;
				}
			}
			for(int j = 0;j < 30;j ++) b[a[i] >> l & 1][j] += a[i] >> j & 1;
			if(a[i] >> l & 1) b1 ++;
			else b0 ++;
		}
		memset(b,0,sizeof b);
		for(int i = n,b0 = 0,b1 = 0;i >= 1;i --) {
			for(int j = 0;j < 30;j ++) {
				if(a[i] >> j & 1) {
					(rs[i][0] += 1ll * mi[j] * (b0 - b[0][j]) % mod) %= mod;
					(rs[i][1] += 1ll * mi[j] * (b1 - b[1][j]) % mod) %= mod;
				}
				else {
					(rs[i][0] += 1ll * mi[j] * b[0][j] % mod) %= mod;
					(rs[i][1] += 1ll * mi[j] * b[1][j] % mod) %= mod;
				}
			}
			for(int j = 0;j < 30;j ++) b[a[i] >> l & 1][j] += a[i] >> j & 1;
			if(a[i] >> l & 1) b1 ++;
			else b0 ++;
		}
		for(int i = 1;i <= n;i ++) {
			LL s = (1ll * ls[i][0] * rs[i][1] % mod + 1ll * ls[i][1] * rs[i][0] % mod);
			(ans += mi[l] * s % mod) %= mod;
		}
	}
	cout << ans << endl;
	//cout << baoli() << endl;
	return 0;
}
