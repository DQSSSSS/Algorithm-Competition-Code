#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

int n,L;
LL S;
int anc[SZ][22],deep[SZ],top[SZ];
LL dist[SZ],w[SZ];

void dfs_lca(int u,int f) {
	deep[u] = deep[f] + 1;
	dist[u] = dist[f] + w[f];
	anc[u][0] = f;
	for(int i = 1;anc[u][i - 1];i ++) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		dfs_lca(v,u);
	}
}	

int work(int u) {
	if(w[u] > S) return -1;
	int ans = u,l = 1;
	LL s = w[u];
	for(int i = 20;i >= 0;i --)	{
		if(!anc[ans][i]) continue;
		if(dist[ans] - dist[anc[ans][i]] + s <= S) {
			if(deep[ans] - deep[anc[ans][i]] + l <= L) {
				s += dist[ans] - dist[anc[ans][i]];
				l += deep[ans] - deep[anc[ans][i]];
				ans = anc[ans][i];
			}
		}
	}
	return ans;
}

int f[SZ];

int dfs(int u) {
	int Mindep = 0;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		int x = dfs(v);
		if(x > 1) {
			Mindep = max(Mindep,x - 1);
		}
		f[u] += f[v];
	}
	if(Mindep == 0) {
		f[u] ++;
		Mindep = deep[u] - deep[top[u]] + 1;
	}
	return Mindep;
}			

int main() {
	n = read(),L = read(),S = read();
	for(int i = 1;i <= n;i ++) w[i] = read();
	for(int i = 2;i <= n;i ++) {
		int x = read();
		g[x].push_back(i);
	}
	dfs_lca(1,0);
	for(int i = 1;i <= n;i ++) {
		top[i] = work(i);
		if(top[i] == -1){ puts("-1"); return 0; }
	}
	dfs(1);
	cout << f[1] << endl;
	return 0;
}
