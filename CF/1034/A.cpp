#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
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

int a[SZ],tong[15000010];
bool vis[15000010];
int pri[15000010],tot = 0;

void shai(int n) {
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
			vis[m] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

vector<pii> g;

int main() {

	int n = read();
	int d = 0,maxn = 0;
	for(int i = 1;i <= n;i ++) {
		a[i] = read(),d = __gcd(d,a[i]);
		tong[a[i]] ++;
		maxn = max(maxn,a[i]);
	}	
	bool same = 1;
	for(int i = 1;i <= n;i ++) if(a[i] != d) same = 0;
	if(same) { puts("-1"); return 0;}
	
	//for(int i = 1;i <= n;i ++) a[i] /= d;

	int ans = n - 1;
	shai(maxn);
	for(int i = 1;i <= tot;i ++) {
		LL m = d * pri[i];
		if(m > maxn) break;
		int t = 0;
		for(int j = m;j <= maxn;j += m) {
			t += tong[j];
		}
		//cout << m << " " << t << endl;
		ans = min(ans,n - t);
	}
	cout << ans << endl;
	return 0;
	/*//cout << ans << endl;
	for(int k = 0;k < g.size();k ++) {
		int p = g[k].first,x = g[k].second,d = 0;
		for(int i = 1;i <= n;i ++) {
			int t = 0,aa = a[i];
			while(aa % p == 0) aa /= p,t ++;
			if(t == x) d ++;
		}
		ans = min(ans,d);
	}
	printf("%d\n",ans);*/
	return 0;
}
