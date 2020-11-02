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

int sz[SZ],anc[SZ][22],son[SZ],deep[SZ],ed[SZ];
vector<int> g[SZ];

void dfs1(int u,int f) {
    sz[u] = 1;
    son[u] = 0;
    anc[u][0] = f;
    deep[u] = deep[f] + 1;
    for(int i = 1;anc[u][i-1];i ++)
        anc[u][i] = anc[anc[u][i-1]][i-1];
    for(int v : g[u]) {
        if(v == f) continue;
        dfs1(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2(int u,int f) {
    if(!son[u]) ed[u] = u;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs2(v,u);
    }
    if(son[u]) ed[u] = ed[son[u]];
}

void PUTS(int x) {
    printf("! %d\n",x); fflush(stdout);
}

int asks(int x) {
    printf("s %d\n",x); fflush(stdout);
    return read();
}

int askd(int x) {
    printf("d %d\n",x); fflush(stdout);
    return read();
}

int get(int x,int y) {
    for(int i = 0;i <= 20;i ++)
        if(y >> i & 1)
            x = anc[x][i];
    return x;
}

int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);

    int mbdeep = askd(1) + 1;
    int u = 1;
    while(1) {
        if(mbdeep == deep[u]) { PUTS(u); return 0; }
        if(sz[son[u]] < sz[u] / 2) {
            u = asks(u);
        }
        else {
            int yz = ed[u];
            int d = askd(yz);
            int lca;
            if(deep[yz] <= mbdeep) {
                int dd = mbdeep - deep[yz];
                lca = get(yz,(d - dd) / 2);
            }
            else {
                int dd = deep[yz] - mbdeep;
                lca = get(yz,dd + (d - dd) / 2);
            }
            if(mbdeep == deep[lca]) { PUTS(lca); return 0; }
            u = asks(lca);
        }
    }
}
