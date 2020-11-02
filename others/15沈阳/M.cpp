#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const LL INF = 1e18;

struct edge { int t; LL d; };

vector<edge> g[SZ];

struct Heap{ int u; LL d; };
bool operator <(Heap a,Heap b) { return a.d > b.d; }
priority_queue<Heap> q;

int n,m;
LL dist[2][SZ];
bool vis[2][SZ];

void dij(int s,LL dist[],bool vis[]) { 
	for(int i = 1;i <= n + m;i ++) dist[i] = INF,vis[i] = 0;
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
			}
		}
	}
}

LL t[SZ];

int main() {
	int T,cc = 0;
	scanf("%d",&T);
	while(T --) {
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n + m;i ++) g[i].clear();
		for(int i = 1;i <= m;i ++) {
			int k,x;
			scanf("%lld%d",&t[i],&k);
			while(k --) {
				scanf("%d",&x);
				g[i + n].push_back((edge){x,0});
				g[x].push_back((edge){i + n,t[i]});
			}
		}
		dij(1,dist[0],vis[0]);
		dij(n,dist[1],vis[1]);
		printf("Case #%d: ",++ cc);
		if(dist[0][n] == INF) {
			puts("Evil John");
		}
		else {
			LL Ans = INF;
		/*	puts("");
			for(int i = 1;i <= m + n;i ++) cout <<i << " "; puts("");
			for(int i = 1;i <= m + n;i ++) cout << dist[0][i] << " "; puts("");
			for(int i = 1;i <= m + n;i ++) cout << dist[1][i] << " "; puts("");
			*/for(int i = 1;i <= n;i ++)
				Ans = min(Ans,max(dist[0][i],dist[1][i]));
			printf("%lld\n",Ans);
			int t = 0;
			for(int i = 1;i <= n;i ++)
				if(Ans == max(dist[0][i],dist[1][i]))
					t ++;
			for(int i = 1;i <= n;i ++)
				if(Ans == max(dist[0][i],dist[1][i]))
					printf("%d%c",i,-- t == 0 ? '\n' : ' ');
		}
	}
	return 0;
}
