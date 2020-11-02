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

int ans = 0;
int val[SZ];
int dfn[SZ],dfs_clock = 0,low[SZ];
int sccnum[SZ],scccnt = 0,to[SZ];
stack<int> s;
vector<int> g[SZ];
bool badguy[SZ],vis[SZ];

void dfs(int u) {
	s.push(u);
    dfn[u] = low[u] = ++ dfs_clock;
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(!dfn[v]) {
    		dfs(v);
    		low[u] = min(low[u],low[v]);
    	}
    	else if(!sccnum[v]) {
    		low[u] = min(low[u],dfn[v]);
    	}
    }
    if(low[u] == dfn[u]) {
        scccnt ++;
        vector<int> tmp;
        int t = 0,badman = 0;
        while(233) {
        	int x = s.top(); s.pop();
			sccnum[scccnt] = x;
            t ++;
            if(val[x]) badman ++,tmp.push_back(x);
        	if(x == u) break;
        }
        if(badman == 1 && t > 1) {
            badguy[to[tmp[0]]] = 1;
    	}
    }
}

struct edge {
	int v,w;
};
vector<edge> g2[SZ];

void dfs2(int u) {
	vis[u] = 1;
	ans ++;
    for(int i = 0;i < g2[u].size();i ++) {
    	int v = g2[u][i].v;
        if(g2[u][i].w || vis[v]) continue;
        dfs2(v);
    }
}

int main() {
    int T = read();
    while(T --) {
    	int n = read();
    	ans = 0; scccnt = 0; dfs_clock = 0;
    	for(int i = 1;i <= n;i ++) {
    		g2[i].clear(),g[i].clear();
    		to[i] = dfn[i] = low[i] = sccnum[i] = badguy[i] = vis[i] = 0;
    	}
    	for(int i = 1;i <= n;i ++) {
    		int v = read();
    		char s[22];
            scanf("%s",s);
            g[i].push_back(v);
            to[i] = v;
            val[i] = s[0] == 'w';
            g2[v].push_back((edge){i,s[0] == 'w'});
    	}
    	for(int i = 1;i <= n;i ++)
    		if(!dfn[i])
    			dfs(i);
		for(int i = 1;i <= n;i ++)
			if(badguy[i])
				dfs2(i);
        printf("0 %d\n",ans);
    }
}
/**
10
2 v
3 v
4 w
5 v
6 v
3 v
8 v
4 v
10 w
9 v

*/
