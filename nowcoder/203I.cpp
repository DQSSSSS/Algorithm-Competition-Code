#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = acos(-1);
const int SZ = 510010;
const LL INF = 1e18;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL Ans[SZ];
int List[SZ];

struct edge{ int t,d; }; 
vector<edge> g[SZ];

int c[SZ],key[SZ],n,m,p;

struct Heap{ int u; LL d; };
bool operator <(Heap a,Heap b) { return a.d > b.d; }
priority_queue<Heap> q;

LL dist[SZ];
bool vis[SZ];

void dij(int s) {
	for(int i = 1;i <= n;i ++) dist[i] = INF;
	dist[s] = 0;
	q.push((Heap){s,0});
	while(q.size()) {
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i].t;
			if(dist[v] > dist[u] + g[u][i].d) {
				dist[v] = dist[u] + g[u][i].d;
				q.push((Heap){v,dist[v]});
				if(u == s) continue;
				if(key[v]) continue;
				c[v] = c[u];
			}
		}
	}
}

int ff[SZ],tt[SZ],ww[SZ];

int main() {
	n = read(),m = read(),p = read();
	for(int i = 1;i <= p;i ++) {
		List[i] = read();
		Ans[List[i]] = INF;
		c[List[i]] = List[i]; key[List[i]] = 1;
		g[0].push_back((edge){List[i],0});
	}
	for(int i = 1;i <= m;i ++) {
		int x = read(),y = read(),z = read();
		g[x].push_back((edge){y,z});
		g[y].push_back((edge){x,z});
		ff[i] = x; tt[i] = y; ww[i] = z;
	}
	dij(0);
	for(int i = 1;i <= m;i ++) {
		int x = ff[i],y = tt[i];
		if(c[x] == c[y]) continue;
		LL d = dist[x] + dist[y] + ww[i];
		Ans[c[x]] = min(Ans[c[x]],d);
		Ans[c[y]] = min(Ans[c[y]],d);
	}
	for(int i = 1;i <= p;i ++)
		printf("%lld%c",Ans[List[i]],i == p ? '\n' : ' ');
	return 0;
}
