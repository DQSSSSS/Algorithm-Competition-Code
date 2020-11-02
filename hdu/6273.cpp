#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int a[SZ],b[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read(),m = read();
		for(int i = 1;i <= n;i ++) a[i] = b[i] = 0;
		for(int i = 1;i <= m;i ++) {
			int l = read(),r = read(),x = read();
			if(x == 2) a[r + 1] --,a[l] ++;
			if(x == 3) b[r + 1] --,b[l] ++;
		}
		int m2 = m,m3 = m;
		for(int i = 1;i <= n;i ++) {
			a[i] += a[i - 1];
			b[i] += b[i - 1];
			m2 = min(m2,a[i]);
			m3 = min(m3,b[i]);
		}
		int ans = ksm(2,m2) * ksm(3,m3) % mod;
		printf("%d\n",ans);
	}
	return 0;
}
