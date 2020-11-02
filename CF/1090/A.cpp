#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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
	int k,mx;
}a[SZ];

bool cmp(haha a,haha b) { return a.mx < b.mx; }

int main(){
	int n = read();
	for(int i = 1;i <= n;i ++) {
		int k = read(),mx = 0;
		a[i].k = k;
		while(k --) {
			int x = read();
			mx = max(mx,x);
		}
		a[i].mx = mx;
	}
	sort(a + 1,a + 1 + n,cmp);
	LL ans = 0;
	for(int i = 1;i < n;i ++) {
		ans += 1ll * (a[n].mx - a[i].mx) * a[i].k;
	}
	printf("%lld\n",ans);
	return 0;
}

