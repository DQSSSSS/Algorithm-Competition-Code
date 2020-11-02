#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct edge {
    int t,id;
};
vector<edge> g[SZ];
int dfn[SZ],dfs_clock,low[SZ],bri[SZ];

void tarjan(int u,int fa) {
    dfn[u] = low[u] = ++ dfs_clock;
    for(edge e : g[u]) {
        int v = e.t;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]) bri[e.id]=1;
        }
        else if(dfn[v] < dfn[u]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
}

int c[SZ];
void dfs(int u,int col) {
    c[u] = col;
    for(edge e : g[u]) {
        int v = e.t;
        if(!bri[e.id] && !c[v]) {
            dfs(v,col);
        }
    }
}

int anc[SZ][22],deep[SZ];

void dfs_lca(int u,int fa) {
    deep[u] = deep[fa] + 1;
    anc[u][0] = fa;
    for(int i = 1;anc[u][i-1];i ++) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
    for(edge e : g[u]) {
        int v = e.t;
        if(v == fa) continue;
        dfs_lca(v,u);
    }
}

int ask_lca(int u,int v) {
    if(deep[u] < deep[v]) swap(u,v);
    int dd = deep[u] - deep[v];
    for(int i = 20;i >= 0;i --)
        if(dd >> i & 1)
            u = anc[u][i];
    if(u == v) return u;
    for(int i = 20;i >= 0;i --)
        if(anc[u][i] != anc[v][i])
            u = anc[u][i],v = anc[v][i];
    return anc[u][0];
}


int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int ff[SZ],tt[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read(),q = read();

        for(int i = 1;i <= n;i ++) {
            fa[i] = i;
            deep[i] = 0;
            g[i].clear();
            c[i] = 0;
            memset(anc[i],0,sizeof anc[i]);
            dfn[i] = low[i] = 0;
        }
        dfs_clock = 0;
        for(int i = 1;i <= m;i ++) {
            bri[i] = 0;
        }

        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            g[x].push_back((edge){y,i});
            g[y].push_back((edge){x,i});
            ff[i] = x; tt[i] = y;
            x = find(x); y = find(y);
            if(x!=y) fa[x] = y;
        }

        for(int i = 1;i <= n;i ++) {
            if(!dfn[i]) tarjan(i,0);
        }

        int ccnt = 0;
        for(int i = 1;i <= n;i ++) {
            if(!c[i]) dfs(i,++ccnt);
        }

        for(int i = 1;i <= n;i ++) {
            g[i].clear();
        }

        for(int i = 1;i <= m;i ++) {
            int x = ff[i],y = tt[i];
            if(c[x] != c[y]) {
                g[c[x]].push_back((edge){c[y],0});
                g[c[y]].push_back((edge){c[x],0});
            }
        }

        for(int i = 1;i <= ccnt;i ++) {
            if(!deep[i])
                dfs_lca(i,0);
        }

        while(q --) {
            int w = read(),u = read(),v = read();
            if(find(u) != find(w) || find(v) != find(w)) puts("No");
            else {
                if(c[u] == c[w] || c[v] == c[w]) puts("Yes");
                else if(c[u] == c[v]) puts("No");
                else {
                    u = c[u],v = c[v],w = c[w];
                    int uv = ask_lca(u,v),uw = ask_lca(u,w),vw = ask_lca(v,w);
                    //cout << u << " " << v << " " << w << endl;
                    //cout << uv << " " << uw << " " << vw << endl;
                    if((uw == w && vw == uv) || (vw == w && uw == uv)) puts("Yes");
                    else puts("No");
                }
            }
        }

    }
}

/**
233
19 23 5
1 2
1 3
2 4
2 5
4 5
3 6
3 7
6 7
1 8
8 10
9 10
8 9
11 12
12 13
13 11
5 14
5 15
14 15
7 17
7 16
16 17
15 18
17 19

*/
