#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

struct haha {
	int l,r;
}a[SZ];

LL sum[SZ];

int main() {
	int n = read(),h = read();
	for(int i = 1;i <= n;i ++) {
		a[i].l = read(),a[i].r = read();
	}
	for(int i = 2;i <= n;i ++) sum[i] = sum[i - 1] + a[i].l - a[i - 1].r;
	sum[n + 1] = 1e9 + sum[n];
	LL ans = 0;
//	for(int i = 1;i <= n + 1;i ++) cout << sum[i] << " "; puts("");
	for(int i = 1;i <= n;i ++) {
		int pos = lower_bound(sum + i + 1,sum + n + 1,sum[i] + h) - sum;
		LL d = h - (sum[pos - 1] - sum[i]);
	//	cout << i << " " << pos << " " << a[pos - 1].r - a[i].l + d << endl;
		ans = max(ans,a[pos - 1].r - a[i].l + d);
	}
	ans = min(ans,(LL)2e9);
	cout << ans << endl;
	return 0;
}
/**
3 4
2 5
8 9
10 11
*/
