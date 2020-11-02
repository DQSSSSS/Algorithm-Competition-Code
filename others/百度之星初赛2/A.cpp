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

vector<int> g[SZ];
bool vis[SZ];
int du[SZ];

void dfs(int u,int f) {
	vis[u] = 1;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f || vis[v]) continue;
		dfs(v,u);
	}
}

int main() {
	int T = read();
	while(T --) {
		int n = read(),m = read(),k = read();
		for(int i = 1;i <= n;i ++) {
			du[i] = 0;
			vis[i] = 0;
			g[i].clear();
		}
		for(int i = 1;i <= m;i ++) {
			int x = read(),y = read();
			x ++; y ++;
            g[x].push_back(y);
            g[y].push_back(x);
            du[x] ++; du[y] ++;
		}
		int u = 1;
        for(int i = 1;i <= n;i ++)
        	if(du[i] > du[u])
        		u = i;
        dfs(u,0);
        for(int i = 1;i <= n;i ++)
        	if(!vis[i]) {
        		dfs(i,0);
				g[u].push_back(i);
				g[i].push_back(u);
			}
        for(int i = 1;i <= n;i ++) vis[i] = 0;
        int ans = g[u].size();
        vis[u] = 1;
        for(int i = 0;i < g[u].size();i ++)
        	vis[g[u][i]] = 1;
		for(int i = 1,t = 1;i <= n && t <= k;i ++)
			if(!vis[i])
				t ++,ans ++;
		printf("%d\n",ans);
	}
	return 0;
}
