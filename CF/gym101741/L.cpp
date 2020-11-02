#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,int> pli;
typedef pair<int,int> pii;
const int SZ = 4e5 + 10;
const int mod = 1e9 + 7;
const LL INF = 1e18;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha {
    int n;
    vector<pii> g[SZ];
    int val[SZ];

    LL dist[SZ];
    bool vis[SZ];

    void dij(int s) {
        for(int i = 1;i <= n;i ++) dist[i] = INF,vis[i] = 0;
        dist[s] = 0;
        priority_queue<pli> q;
        q.push(make_pair(0,s));
        while(q.size()) {
            int u = q.top().second; q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(pii e : g[u]) {
                int v = e.first;
                if(dist[v] > dist[u] + val[e.second]) {
                    dist[v] = dist[u] + val[e.second];
                    q.push(make_pair(-dist[v],v));
                }
            }
        }
    }
}da;

vector<int> g[SZ],g2[SZ];
int anc[22][SZ],rd[SZ],deep[SZ];

int ask_lca(int u,int v) {
    if(deep[u] < deep[v]) swap(u,v);
    int dd = deep[u] - deep[v];
    for(int i = 20;i >= 0;i --) if(dd>>i&1) u = anc[i][u];
    if(u == v) return u;
    for(int i = 20;i >= 0;i --) if(anc[i][u] != anc[i][v]) u = anc[i][u],v = anc[i][v];
    return anc[0][u];
}

int sz[SZ],n,m;

void dfs(int u) {
    sz[u] = u <= n;
    for(int v : g2[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

int ff[SZ],tt[SZ],dd[SZ];

int main() {
    n = read(),m = read();
    da.n = n;
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        da.val[i] = z;
        da.g[x].push_back(make_pair(y,i));
        da.g[y].push_back(make_pair(x,i));
        ff[i] = x;
        tt[i] = y;
        dd[i] = z;
    }
    da.dij(1);
    for(int i = 1;i <= m;i ++) {
        int x = ff[i],y = tt[i];
        if(da.dist[x] == da.dist[y] + dd[i]) {
            g[y].push_back(i+n); g[i+n].push_back(x);
            rd[i+n] ++; rd[x] ++;
         //   printf("%d %d\n",y,x);
        }
        if(da.dist[y] == da.dist[x] + dd[i]) {
            g[x].push_back(i+n); g[i+n].push_back(y);
            rd[i+n] ++; rd[y] ++;
         //   printf("%d %d\n",x,y);
        }
    }

    anc[0][1] = 0;
    queue<int> q;
    q.push(1);
    while(q.size()) {
        int u = q.front(); q.pop();
       // printf("- %d %d\n",anc[0][u],u);
        g2[anc[0][u]].push_back(u);
        deep[u] = deep[anc[0][u]] + 1;
        for(int i = 1;anc[i-1][u];i ++) anc[i][u] = anc[i-1][anc[i-1][u]];
        for(int v : g[u]) {
            rd[v] --;
            if(!anc[0][v]) anc[0][v] = u;
            else anc[0][v] = ask_lca(anc[0][v],u);
            if(!rd[v]) q.push(v);
        }
    }

    dfs(1);

    for(int i = 1;i <= m;i ++) {
        printf("%d\n",sz[i+n]);
    }
}
