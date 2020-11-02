#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a * ans %mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

LL a[SZ];

int main() {
	LL n = read(),m = read(),A = read();
	for(int i = 1;i <= m;i ++) a[i] = read();
	sort(a + 1,a + 1 + m);
	LL ans = ksm(A,n-2*a[m]);
	for(int i = m;i >= 1;i --) a[i] -= a[i - 1];
	for(int i = 1;i <= m;i ++) {
		LL t = ksm(A,a[i]);
		LL tmp = (ksm(A,2*a[i])-t*(t-1)%mod*ksm(2,mod-2)%mod)%mod;
		ans *= tmp; ans %= mod;
	}
	ans += mod; ans %= mod;
	cout << ans << endl;
	return 0;
}

