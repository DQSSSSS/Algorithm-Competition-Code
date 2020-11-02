#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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
		if(b & 1) ans = a * ans % mod;
		a = a * a %mod;
		b >>= 1;
	}
	return ans;
}

struct haha {
	int x,y;
}a[SZ];

bool cmpx(haha a,haha b) { return a.x < b.x; }
bool cmpy(haha a,haha b) { return a.y < b.y; }

int n;
LL tree[SZ];

void add(int x,LL d) {
    for(int i = x;i <= n;i += i & -i)
    	(tree[i] += d) %= mod;
}

LL ask(int x) {
	LL ans = 0;
	for(int i = x;i > 0;i -= i & -i)
		(ans += tree[i]) %= mod;
	return ans;
}

int lsh[SZ];
LL l[SZ],r[SZ];

int main() {
    n = read();
    for(int i = 1;i <= n;i ++)
    	a[i].x = read(),a[i].y = read();
    LL ans = (LL)n * (n + 1) % mod * ksm(2,mod - 2) % mod;
    ans %= mod;
    ans += n; ans %= mod;
    sort(a + 1,a + 1 + n,cmpy);
	for(int i = 1,lst = 1;i <= n;i ++) {
		if(i == n || a[i].y != a[i + 1].y) {
			LL t = i - lst + 1;
            ans -= t * (t + 1) % mod * ksm(2,mod - 2) % mod;
            ans %= mod;
			lst = i + 1;
		}
	}

	for(int i = 1;i <= n;i ++) lsh[i] = a[i].x;
	sort(lsh + 1,lsh + 1 + n);
    int m = unique(lsh + 1,lsh + 1 + n) - lsh - 1;
	for(int i = 1;i <= n;i ++)
		a[i].x = lower_bound(lsh + 1,lsh + 1 + m,a[i].x) - lsh;

	for(int i = 1,lst = 1;i <= n;i ++) {
		if(i == n || a[i].y != a[i + 1].y) {
			for(int j = lst;j <= i;j ++) {
                l[j] = ask(n) - ask(a[j].x);
                l[j] %= mod;
			}
			for(int j = lst;j <= i;j ++) {
                add(a[j].x,1);
			}
			lst = i + 1;
		}
	}
	for(int i = 1;i <= n;i ++) tree[i] = 0;

	for(int i = n,lst = n;i >= 1;i --) {
		if(i == 1 || a[i].y != a[i - 1].y) {
			for(int j = lst;j >= i;j --) {
                r[j] = ask(n) - ask(a[j].x);
				r[j] %= mod;
			}
			for(int j = lst;j >= i;j --) {
                add(a[j].x,1);
			}
			lst = i - 1;
		}
	}
	//for(int i = 1;i <= n;i ++) cout << l[i] << " "; puts("");
	//for(int i = 1;i <= n;i ++) cout << r[i] << " "; puts("");
	for(int i = 1;i <= n;i ++) {
		ans += r[i] * l[i] % mod;
		ans %= mod;
	}
	ans += mod; ans %= mod;
	cout << ans << endl;
	return 0;
}
/**
5
1113 1111
1112 1112
1113 1113
1114 1114
1115 1111
*/
