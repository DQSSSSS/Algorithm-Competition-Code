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

vector<int> g[SZ];

struct edge {
	int t,id;
}l[SZ];

int head[SZ],nxt[SZ],tot = 0;

void build(int f,int t) {
	l[++ tot] = (edge){t};
	nxt[tot] = head[f];
	head[f] = tot;
}

int bcnt = 0,bri[SZ];
int dfn[SZ],low[SZ],dfs_clock = 0;

void tarjan(int u,int fa)
{
    dfn[u] = low[u]= ++ dfs_clock;
    for(int i = head[u];i;i = nxt[i]) {
        int v = l[i].t;
        if(fa == v) continue;
        if(!dfn[v]) {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]) bcnt ++,bri[l[i].id] = 1;
        }
        else if(dfn[v] < dfn[u]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
}

int c[SZ];
void dfs_ltk(int u,int color) {
    c[u] = color;
    for(int i = head[u];i;i = nxt[i]) {
        int v = l[i].t;
        if(!bri[l[i].id] && !c[v]) {
            dfs_ltk(v,color);
        }
    }
}

int sz[SZ],fa[SZ];

void dfs(int u,int f) {
	sz[u] = 1;
	fa[u] = f;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

int ff[SZ],tt[SZ],a[SZ];

int main() {
	//freopen("233.txt","w",stdout);
	int n = read(),m = read();
	for(int i = 1;i <= m;i ++) {
		int x = read(),y = read();
		build(x,y); build(y,x);
		ff[i] = x; tt[i] = y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	for(int i = 1;i <= n;i ++)
        if(!dfn[i])
            tarjan(i,0);
    int ccnt = 0;
    for(int i = 1;i <= n;i ++)
        if(!c[i])
            dfs_ltk(i,++ ccnt);
	
	dfs(1,0);
	int q = read();
	while(q --) {
		int k = read();
		LL ans = 0;
		for(int i = 1;i <= k;i ++) {
			a[i] = read();
			int x = a[i] < 0 ? tt[-a[i]] : ff[a[i]];
			int y = a[i] < 0 ? ff[-a[i]] : tt[a[i]];
			//cout << x << " " << y << endl;
			if(x == fa[y]) ans += sz[y];
			else ans -= sz[x];
		}
		if(ans < 0) ans += n;
		printf("%lld\n",ans);
	}
	return 0;
}
