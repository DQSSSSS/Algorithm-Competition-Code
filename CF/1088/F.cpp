#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 10000010;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[500010];
vector<int> g[500010];
int anc[500010][22],root;
LL ans = 0;

void dfs(int u,int fa) {
	anc[u][0] = fa;
	for(int i = 1;anc[u][i - 1];i ++) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	LL Min = 1e18;
	int i;
	for(i = 0;anc[u][i];i ++) {
		int v = anc[u][i];
		Min = min(Min,a[u] + a[v] + 1ll * i * a[v]);
	}
	if(i && anc[u][i - 1] != root) {
		Min = min(Min,a[u] + a[root] + 1ll * i * a[root]);
	}
	if(u != root) ans += Min;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v,u);
	}
}

int main() {
	int n = read();
	int minval = 1e9;
	for(int i = 1;i <= n;i ++) {
		a[i] = read();
		minval = min(minval,a[i]);
		if(a[i] == minval) root = i;
	}
	for(int i = 1;i < n;i ++) {
		int u = read(),v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(root,0);
	printf("%lld\n",ans);
	return 0;
}
