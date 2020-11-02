#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

int anc[SZ][22],deep[SZ],sz[SZ];
vector<int> g[SZ];

void dfs(int u,int fa) {
	deep[u] = deep[fa] + 1;
	anc[u][0] = fa;
	for(int i = 1;anc[u][i - 1];i ++)
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	sz[u] = 1;
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(v == fa) continue;
    	dfs(v,u);
    	sz[u] += sz[v];
    }
}

int jump(int x,int d) {
	for(int i = 20;i >= 0;i --)
        if(d >> i & 1)
           	x = anc[x][i];
	return x;
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

int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
    	int x = read(),y = read();
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    dfs(1,0);
    int m = read();
    while(m --) {
		int x = read(),y = read();
        int lca = ask_lca(x,y);
        int d = deep[x] + deep[y] - 2 * deep[lca];
       	if(x == y) { printf("%d\n",n); continue; }
        if(d % 2 == 1) { puts("0"); continue; }
        int mid = d / 2;
        if(deep[x] < deep[y]) swap(x,y);
        int ans = 0;
        if(deep[x] == deep[y]) {
        	int sonx = jump(x,deep[x] - deep[lca] - 1);
        	int sony = jump(y,deep[y] - deep[lca] - 1);
        	ans = n - sz[sonx] - sz[sony];
		}
		else {
            int son = jump(x,mid - 1);
            ans = sz[anc[son][0]] - sz[son];
		}
		printf("%d\n",ans);
    }
    return 0;
}
