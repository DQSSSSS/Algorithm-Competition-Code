#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
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
    int t;
    LL d;
    int id;
};

vector<edge> g[SZ];

int low[SZ],dfn[SZ],dfs_clock;
bool bri[SZ];

void dfs(int u,int fa) {
    low[u] = dfn[u] = ++ dfs_clock;
    for(edge e : g[u]) {
        int v = e.t;
        if(v == fa) continue;
        if(!dfn[v]) {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]) bri[e.id] = 1;
        }
        else if(dfn[v] < dfn[u]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
}

bool multi[SZ];

struct Heap{
    int u; LL d;
};

bool operator <(Heap a,Heap b) { return a.d > b.d; }

priority_queue<Heap> q;

bool vis[2][SZ];
LL dist[2][SZ];

void dij(int s,LL dist[],bool vis[]) {
    for(int i = 1;i <= n;i ++) dist[i] = 1e18,vis[i] = 0;
    dist[s] = 0;
    q.push((Heap){s,0});
    while(!q.empty()) {
        int u = q.top().u; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(edge e : g[u]) {
            if(dist[e.t] > dist[u] + e.d) {
                dist[e.t] = dist[u] + e.d;
                q.push((Heap){e.t,dist[e.t]});
            }
        }
    }
}

int ff[SZ],tt[SZ],dd[SZ];

void build_graph(int d) {
    for(int i = 1;i <= m;i ++) {
        int x = ff[i],y = tt[i],z = dd[i];
        if(d == 0) g[x].push_back((edge){y,z,i});
        else g[y].push_back((edge){x,z,i});
    }
}

void clear_graph() {
    for(int i = 1;i <= n;i ++) g[i].clear();
}

queue<int> que;
bool fuck[SZ];

map<int,map<int,int> > mp;

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        ff[i] = x; tt[i] = y; dd[i] = z;
    }

    build_graph(0);
    dij(1,dist[0],vis[0]);
    clear_graph();

    build_graph(1);
    dij(2,dist[1],vis[1]);

   // for(int i = 1;i <= n;i ++) cout << dist[0][i] << " "; puts("");
   // for(int i = 1;i <= n;i ++) cout << dist[1][i] << " "; puts("");

    que.push(2);
    while(que.size()) {
        int v = que.front(); que.pop();
        //cout << v << endl;
        for(edge e : g[v]) {
            int u = e.t;
            if(!fuck[e.id] && dist[0][u] + e.d == dist[0][v]) {
                fuck[e.id] = 1;
                que.push(u);
            }
        }
    }

    clear_graph();

    for(int i = 1;i <= m;i ++) {
        if(fuck[i]) {
            int x = ff[i],y = tt[i],z = dd[i];
            g[x].push_back((edge){y,z,i});
            g[y].push_back((edge){x,z,i});
            mp[x][y] ++;
        }
    }

    dfs(1,0);

    for(int i = 1;i <= m;i ++) {
        if(fuck[i]) {
            int x = ff[i],y = tt[i],z = dd[i];
            if(mp[x][y] != 1) bri[i] = 0;
        }
    }

    LL mindist = dist[0][2];

  //  for(int i = 1;i <= m;i ++) cout << bri[i] <<" "; puts("");
 //   for(int i = 1;i <= m;i ++) cout << multi[i] <<" "; puts("");

    for(int i = 1;i <= m;i ++)  {
        int x = ff[i],y = tt[i],z = dd[i];
        LL ndist = dist[0][y] + z + dist[1][x];
        if(mindist > ndist) puts("HAPPY");
        else {
            if(mindist == ndist) puts("SOSO");
            else {
                if(bri[i]) puts("SAD");
                else puts("SOSO");
            }
        }
    }

    return 0;
}

/**
4 4
1 3 1
3 2 1
4 3 1
3 4 1
*/
