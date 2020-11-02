#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 8e6 + 10;
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

vector<pii> g[SZ];

LL dist[SZ];
bool vis[SZ];
int n,m;

void dij(int s) {
    for(int i = 1;i <= n;i ++) dist[i] = 1e18,vis[i] = 0;
    dist[s] = 0;
    priority_queue<pli> q; q.push(make_pair(0,s));
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(pii e : g[u]) {
            int v = e.first;
            if(dist[v] > dist[u] + e.second) {
                dist[v] = dist[u] + e.second;
                q.push(make_pair(-dist[v],v));
            }
        }
    }
}


struct edge {
    int f,t;
    LL d;
}l[SZ];

int head[SZ],nxt[SZ],tot = 1;

void build(int f,int t,LL d) {
    l[++ tot] = (edge){f,t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d) {
    build(f,t,d); build(t,f,0);
}

int deep[SZ];

bool bfs(int s,int e) {
    for(int i = 1;i <= n;i ++) deep[i] = 0;
    deep[s] = 1;
    queue<int> q; q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = nxt[i]) {
            int v = l[i].t;
            if(l[i].d && !deep[v]) {
                deep[v] = deep[u] + 1;
                q.push(v);
                if(v == e) return true;
            }
        }
    }
    return false;
}

LL dfs(int u,LL flow,int e) {
    if(u == e || flow == 0) return flow;
    LL ans = flow;
    for(int i = head[u];i;i = nxt[i]) {
        int v = l[i].t;
        if(l[i].d && deep[v] == deep[u] + 1) {
            LL f = dfs(v,min(ans,l[i].d),e);
            if(f > 0) {
                l[i].d -= f; l[i^1].d += f;
                ans -= f;
                if(ans == 0) break;
            }
            else deep[v] = 0;
        }
    }
    if(ans == flow) deep[u] = 0;
    return flow - ans;
}

LL dinic(int s,int e) {
    LL ans = 0;
    while(bfs(s,e)) {
        LL tmp = dfs(s,1e18,e);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

int ff[SZ],tt[SZ],dd[SZ];

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) g[i].clear(),head[i] = 0; tot = 1;
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read(),z = read();
            g[x].push_back(make_pair(y,z));
            ff[i] = x; tt[i] = y; dd[i] = z;
        }
        dij(1);
        if(dist[n] == 1e18) { puts("0"); continue; }
        for(int i = 1;i <= m;i ++) {
            if(dist[tt[i]] == dist[ff[i]] + dd[i]) {
                insert(ff[i],tt[i],dd[i]);
            }
        }
        printf("%lld\n",dinic(1,n));
    }
}
