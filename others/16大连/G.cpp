#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5e4 + 10;
const int mod = 1e9 + 7;

vector<int> G[SZ];

int n,k;
LL g[SZ],tmp[1030],a[SZ];
LL *f[SZ];

void dfs(int u,int fa) {
	int c = 1 << a[u];
	f[u] = new LL[(1 << k)];
	for(int j = 0;j < (1 << k);j ++) f[u][j] = 0;
	//for(int j = 0;j < (1 << k);j ++) cout << f[u][j] << " "; puts("");
	f[u][c] = 1;
	//cout << u << endl;
	for(int i = 0;i < G[u].size();i ++) {
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
		for(int j = 0;j < (1 << k);j ++) tmp[j] = f[u][j];
		for(int l = 0;l < k;l ++)
			for(int j = (1<<k)-1;j >= 0;j --)
				if(!(j & (1 << l)))
					tmp[j] += tmp[j ^ (1 << l)];
		/*if(u == 1){
			cout << v << endl;
			for(int j = 0;j < (1 << k);j ++) cout << tmp[j] << " "; puts("");
			for(int j = 0;j < (1 << k);j ++) cout << f[v][j] << " "; puts("");
		}*/
		for(int j = 0;j < (1 << k);j ++) {
			f[u][j | c] += f[v][j];
			g[u] += tmp[(~(j|c))&((1<<k)-1)] * f[v][j];
		}
		delete f[v];
		g[u] += g[v];
	}
	//cout << u << endl;
	//for(int j = 0;j < (1 << k);j ++) cout << f[u][j] << " "; puts("");
}

int main() {
	while(~scanf("%d%d",&n,&k)) {
		for(int i = 1;i <= n;i ++) {
			scanf("%d",&a[i]),a[i] --;
			G[i].clear(),g[i] = 0;
		}
		for(int i = 1;i < n;i ++) {
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if(k == 1) { LL ans = 1ll * n * n; printf("%lld\n",ans); continue; }
		dfs(1,0);
		delete f[1];
	/*for(int i = 1;i <= n;i ++) cout << g[i] << " "; puts("");
		for(int i = 1;i <= n;i ++) {
			for(int j = 0;j < (1 << k);j ++) 
				cout << f[i][j] << " "; puts("");
		}*/
		printf("%lld\n",g[1] * 2);
	}
	return 0;
}
/**
5 2
1 2 1 2 1
1 2
1 3
2 4
2 5
*/
