#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 10010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,m;
vector<int> g[SZ];
int anc[SZ][22],deep[SZ],lg[SZ];

void dfs(int u,int fa) {
	anc[u][0] = fa;
    deep[u] = deep[fa] + 1;
    for(int i = 1;i <= lg[deep[u]];i ++)
    	anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(v == fa) continue;
        dfs(v,u);
    }
}

int asklca(int u,int v) {
	if(deep[u] < deep[v]) swap(u,v);
    int dd = deep[u] - deep[v];
    for(int i = lg[n];i >= 0;i --)
    	if(dd & (1 << i))
    		u = anc[u][i];
    if(u == v) return u;
	for(int i = lg[n];i >= 0;i --)
    	if(anc[u][i] != anc[v][i])
    		u = anc[u][i],v = anc[v][i];
    return anc[u][0];
}

int askdist(int u,int v) {
	return deep[u] + deep[v] - 2 * deep[asklca(u,v)];
}

int main() {
    int T = read();
    for(int i = 1;i <= 1000;i ++) lg[i] = log2(i);
    while(T --) {
    	n = read(),m = read();
    	for(int i = 1;i <= n;i ++) g[i].clear();
    	for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
    	}
    	dfs(1,0);
    	int lastans = 0;
        while(m --) {
        	int x = read(),y = read(),w = read();
            x = (x + lastans) % n + 1;
            y = (y + lastans) % n + 1;
            w = (w + lastans) % n;
            int ans = 0;
            for(int i = 1;i <= n;i ++) {
				if(askdist(i,x) <= w || askdist(i,y) <= w)
					ans ++;
            }
            printf("%d\n",lastans = ans);
        }
    }
	return 0;
}
