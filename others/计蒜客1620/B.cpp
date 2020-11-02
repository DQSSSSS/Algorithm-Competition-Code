#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const LL INF = 1e18 + 10;
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

struct edge {
	int t,d;
};

vector<edge> g[SZ];

struct Heap{int u; LL d;};
bool operator <(Heap a,Heap b) { return a.d > b.d; }
priority_queue<Heap> q;

LL dist[SZ];
bool vis[SZ];
int n;

LL dij(int s,int e){
	for(int i = 1;i <= n;i ++) dist[i] = dist[i+n] = INF;
	dist[s] = 0;
	q.push((Heap){s,dist[s]});
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
	return min(dist[e],dist[e+n]);
}


int main() {
	n = read();
	int m = read(),f = read(),s = read() + 1,e = read() + 1;
	for(int i = 1;i <= m;i ++) {
		int x = read() + 1,y = read() + 1,d = read();
		g[x].push_back((edge){y,d});
		g[x+n].push_back((edge){y+n,d});
		g[y].push_back((edge){x,d});
		g[y+n].push_back((edge){x+n,d});
	}
	for(int i = 1;i <= f;i ++) {
		int x = read() + 1,y = read() + 1;
		g[x].push_back((edge){y+n,0});
	}
	cout << dij(s,e) << endl;
	return 0;
}
