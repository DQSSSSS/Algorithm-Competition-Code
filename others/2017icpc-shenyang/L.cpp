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

vector<int> g[SZ];

int sz[SZ],ans,n,m;

void dfs(int u,int fa) {
	sz[u] = 1;
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(v == fa) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
    if(sz[u] >= m && n - sz[u] >= m) ans ++;
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) g[i].clear(); ans = 0;
        for(int i = 1;i < n;i ++) {
        	int x = read(),y = read();
        	g[x].push_back(y);
        	g[y].push_back(x);
        }
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
