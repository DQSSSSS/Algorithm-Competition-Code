#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const LL INF = 1e18 + 10;
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

void build(int f,int t) {
	g[f].push_back(t);
}

int dist[210][SZ];
bool vis[210][SZ];
queue<int> q;

void bfs(int s,int dist[],bool vis[]) {
    dist[s] = 0;
    q.push(s);
    vis[s] = 1;
    while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i];
			if(!vis[v]) {	
				dist[v] = dist[u] + 1;
				vis[v] = 1;
				q.push(v);
			}
		}
    }
}

int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int deep[SZ];
int anc[SZ][22];
int lg[SZ];

void dfsLca(int u,int f) {
    anc[u][0] = f;
    deep[u] = deep[f] + 1;
    for(int i = 1;i <= lg[deep[u]];i ++)
    	anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(v == f) continue;
        dfsLca(v,u);
    }
}

int askLca(int u,int v) {
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

LL ask_dist(int u,int v) {
	return deep[u] + deep[v] - 2 * deep[askLca(u,v)];
}

struct haha{
	int f,t;
}l[SZ];

bool use[SZ];

int main() {
	n = read(),m = read();
    for(int i = 1;i <= n;i ++) lg[i] = log2(i);
    for(int i = 1;i <= m;i ++)
        scanf("%d%d",&l[i].f,&l[i].t);
    
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        int x = find(l[i].f);
        int y = find(l[i].t);
    	if(x != y) {
            build(l[i].f,l[i].t);
        	build(l[i].t,l[i].f);
            fa[x] = y;
            use[i] = 1;
    	}
    }
    dfsLca(1,0);

    for(int i = 1;i <= m;i ++) {
        if(!use[i]) {
            build(l[i].f,l[i].t);
        	build(l[i].t,l[i].f);
    	}
    }
    
    int k = m - n + 1;
    for(int i = 1,x = 0;i <= m;i ++) {
       	if(!use[i]) {
       		bfs(l[i].f,dist[2 * x],vis[2 * x]);
        	bfs(l[i].t,dist[2 * x + 1],vis[2 * x + 1]);
    		x ++;
    	}
    }
    
    int q = read();
    while(q --) {
    	int u = read(),v = read();
        int ans = ask_dist(u,v);
        for(int i = 0;i < 2 * k;i ++) {
            ans = min(ans,dist[i][u] + dist[i][v]);
        }
        printf("%d\n",ans);
    }
	return 0;
}

