#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500100;
const LL INF = 1e18 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

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
    int t;
    LL d;
};

vector<edge> g[SZ];

struct Heap {
    int u;
    LL d;
};

bool operator <(Heap a,Heap b) { return a.d > b.d; }

priority_queue<Heap> q;

LL dist[SZ];
bool vis[SZ];
int path[SZ],pre[SZ],n,m;

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
                pre[v] = u;
                q.push((Heap){v,dist[v]});
            }
        }
    }
    if(dist[n] == INF) puts("-1"),exit(0);
    int u = n,t = 0;
    while(u) path[++ t] = u,u = pre[u];
    for(int i = t;i >= 1;i --) printf("%d ",path[i]);
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        g[x].push_back((edge){y,z});
        g[y].push_back((edge){x,z});
    }
    dij(1);
    return 0;
}
