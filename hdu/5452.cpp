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

vector<int> g[SZ];

int anc[SZ][22],pre[SZ],sz[SZ],dfs_clock = 0,deep[SZ];

void dfs(int u,int f) {
	anc[u][0] = f;
	sz[u] = 1;
	deep[u] = deep[f] + 1;
	for(int i = 1;anc[u][i - 1];i ++)
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

int ask_lca(int u,int v) {
	if(deep[u] < deep[v]) swap(u,v);
	int dd = deep[u] - deep[v];
	for(int i = 20;i >= 0;i --)
		if(dd >> i & 1)
			u = anc[u][i];
	if(u == v) return u;
	for(int i = 20;i >= 0;i --)
		if(anc[u][i] != anc[v][i])
			u = anc[u][i],v = anc[v][i];
	return anc[u][0];
}

int n,m,b[SZ];

void dfs2(int u,int f) {
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs2(v,u);
		b[u] += b[v];
	}
}

int main() {
	int T = read(),cc = 0;
	while(T --) {
		n = read(),m = read();
		dfs_clock = 0;
		for(int i = 1;i <= n;i ++) {
			b[i] = 0,g[i].clear();
			for(int j = 0;j <= 20;j ++)
				anc[i][j] = 0;
		}
		for(int i = 1;i < n;i ++) {
			int x = read(),y = read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		for(int i = 1;i <= m - n + 1;i ++) {
			int x = read(),y = read();
			int lca = ask_lca(x,y);
			b[x] ++; b[y] ++; b[lca] -= 2;
		}
		dfs2(1,0);
		int ans = 1e9;
		for(int i = 2;i <= n;i ++) 
			ans = min(ans,b[i] + 1);
		printf("Case #%d: %d\n",++ cc,ans);
	}
	return 0;
}
