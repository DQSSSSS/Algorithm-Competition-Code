#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

namespace kpath {
	int n,m;
	
	struct edge {
		int t; LL d;
	};
	vector<edge> g[SZ],g2[SZ];
	
	LL dist[SZ];
	int pre[SZ];	
	struct Heap{ int u; LL d; };
	bool operator <(Heap a,Heap b) { return a.d > b.d; }
	priority_queue<Heap> q;

	int rd[SZ];
	stack<int> S;
	void topo(int s) {
		for(int i = 1;i <= n;i ++) dist[i] = INF,pre[i] = 0;
		S.push(s); dist[s] = 0;
		while(S.size()) {
			int u = S.top(); S.pop();
			for(int i = 0;i < g2[u].size();i ++) {
				int v = g2[u][i].t;
				if(dist[v] > dist[u] + g2[u][i].d)
					dist[v] = dist[u] + g2[u][i].d,pre[v] = u;
				if(!-- rd[v]) S.push(v);
			}
		}
	}
	
	struct node{ int lc,rc,dis,id; LL v; }tree[SZ * 12];
	int tot,rt[SZ];
	int merge(int x,int y) {
		if(!x||!y) return x + y;
		if(tree[x].v > tree[y].v) swap(x,y);
		int o = ++ tot; tree[o] = tree[x];
		tree[o].rc = merge(tree[o].rc,y);
		if(tree[tree[o].lc].dis < tree[tree[o].rc].dis) swap(tree[o].lc,tree[o].rc);
		tree[o].dis = tree[tree[o].rc].dis + 1;
		return o;
	}	
	void dfs(int u) {
		if(pre[u]) rt[u] = rt[pre[u]];
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i].t;
			if(dist[v] == INF || pre[u] == v) continue;
			tree[++ tot] = (node){0,0,1,v,dist[v]+g[u][i].d-dist[u]};
			rt[u] = merge(rt[u],tot);
		}
		for(int i = 0;i < g2[u].size();i ++)
			if(pre[g2[u][i].t] == u) dfs(g2[u][i].t);
	}
	
	int ff[SZ],tt[SZ],dd[SZ];
	LL work(int s,int e,int k) {
		for(int i = 1;i <= m;i ++) {
			g[ff[i]].push_back((edge){tt[i],dd[i]});
			g2[tt[i]].push_back((edge){ff[i],dd[i]});
			rd[ff[i]] ++;
		}
		topo(e); 
		tot = rt[e] = 0; dfs(e);
		if(k == 1) return -dist[s];
		while(q.size()) q.pop();
		q.push((Heap){rt[s],dist[s] + tree[rt[s]].v});
		while(k --) {
			Heap p = q.top(); q.pop();
			if(k == 1) return -p.d;
			int u = p.u,v = tree[u].id;
			if(rt[v]) q.push((Heap){rt[v],p.d + tree[rt[v]].v});
			if(tree[u].lc) q.push((Heap){tree[u].lc,p.d - tree[u].v + tree[tree[u].lc].v});
			if(tree[u].rc) q.push((Heap){tree[u].rc,p.d - tree[u].v + tree[tree[u].rc].v});
		}
	}
	void init(int nn){ 
		n = nn; m = 0;
		for(int i = 1;i <= n;i ++) g[i].clear(),g2[i].clear();
	}
}

void Addedge(int f,int t,int d) {
	int k = ++ kpath::m;
	kpath::ff[k] = f; kpath::tt[k] = t; kpath::dd[k] = d;
}

int c0[SZ],c1[SZ],col[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read(),k = read();
		int s = n + 1,e = 3*n+1;
		kpath::init(3*n+1);
		for(int i = 1;i <= n;i ++) {
			int c0 = read(),c1 = read(),col = read();
			Addedge(n+i,i,-c0); Addedge(n+n+i,i,-c1);
			if(i < n) {
				Addedge(n+i,n+i+1,0); Addedge(n+n+i,n+n+i+1,0);
				if(col == 0) Addedge(i,n+i+1,0);
				else Addedge(i,n+n+i+1,0);
			}
			else Addedge(i,e,0),Addedge(n+i,e,0),Addedge(n+n+i,e,0);
		}
		printf("%lld\n",kpath::work(s,e,k));
	}
	return 0;
}	
/**
8 6
2 1 0
1 3 1
3 1 1
5 8 1
5 0 0
1 9 0
5 3 1
10 3 0

*/
