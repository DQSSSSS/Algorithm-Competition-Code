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

struct edge {
	int t,w;
};

vector<edge> g[SZ];

void build(int f,int t,int w) {
	g[f].push_back((edge){t,w});
}

LL dist[44][SZ];
bool vis[44][SZ];

struct Heap { int u; LL d; };
bool operator <(Heap a,Heap b) { return a.d > b.d; }
priority_queue<Heap> q;

void dij(int s,LL dist[],bool vis[]) {
    for(int i = 1;i <= n;i ++) dist[i] = INF;
    dist[s] = 0;
    q.push((Heap){s,0});
    while(q.size()) {
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i].t;
			if(dist[v] > dist[u] + g[u][i].w) {	
				dist[v] = dist[u] + g[u][i].w;
				q.push((Heap){v,dist[v]});
			}
		}
    }
   // cout <<s << endl;
   // for(int i = 1;i <= n;i ++) cout << dist[i] << " "; puts("");
}

int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int deep[SZ];
int anc[SZ][22];
LL dis[SZ];
int lg[SZ];

void dfsLca(int u,int f) {
    anc[u][0] = f;
    deep[u] = deep[f] + 1;
    for(int i = 1;i <= lg[deep[u]];i ++)
    	anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i].t;
    	if(v == f) continue;
    	dis[v] = dis[u] + g[u][i].w;
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
	return dis[u] + dis[v] - 2 * dis[askLca(u,v)];
}

struct haha{
	int f,t,w;
}l[SZ];

bool use[SZ];

int main() {
	n = read(),m = read();
    for(int i = 1;i <= n;i ++) lg[i] = log2(i);
    for(int i = 1;i <= m;i ++)
        scanf("%d%d%d",&l[i].f,&l[i].t,&l[i].w);
    
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        int x = find(l[i].f);
        int y = find(l[i].t);
    	if(x != y) {
            build(l[i].f,l[i].t,l[i].w);
        	build(l[i].t,l[i].f,l[i].w);
            fa[x] = y;
            use[i] = 1;
    	}
    }
    dfsLca(1,0);
    
    for(int i = 1;i <= m;i ++) {
        if(!use[i]) {
            build(l[i].f,l[i].t,l[i].w);
        	build(l[i].t,l[i].f,l[i].w);
    	}
    }
    
    int k = m - n + 1;
    for(int i = 1,x = 0;i <= m;i ++) {
       	if(!use[i]) {
       		dij(l[i].f,dist[2 * x],vis[2 * x]);
        	dij(l[i].t,dist[2 * x + 1],vis[2 * x + 1]);
    		x ++;
    	}
    }
    
    int q = read();
    while(q --) {
    	int u = read(),v = read();
        LL ans = ask_dist(u,v);
        for(int i = 0;i < 2 * k;i ++) {
            ans = min(ans,dist[i][u] + dist[i][v]);
        }
        printf("%lld\n",ans);
    }
	return 0;
}

