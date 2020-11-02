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

/// 每个子树也满足支配树性质，即从子树根节点到子树内节点的链上点为必经点。
/// 在支配树上的每个点u的祖先是从s走到u的必经点。本题是求支配树的子树大小。
struct DomTree {
    int n;
    struct node {
        vector<int> g[SZ];
        inline void add(int u,int v) { g[u].push_back(v); }
    }a,b,c,d;
    int dfn[SZ],id[SZ],fa[SZ],dfs_clock;
    int semi[SZ],idom[SZ],bel[SZ],val[SZ];
    void dfs(int u) {
        dfn[u] = ++ dfs_clock; id[dfs_clock] = u;
        for(int v : a.g[u]) {
            if(dfn[v])continue;
            fa[v] = u;
            dfs(v);
        }
    }
    inline int find(int x) {
        if(x == bel[x]) return x;
        int tmp = find(bel[x]);
        if(dfn[semi[val[bel[x]]]] < dfn[semi[val[x]]]) val[x] = val[bel[x]];
        return bel[x]=tmp;
    }
    inline void tarjan() {
        for(int i = dfs_clock;i > 1;i --) {
            int u=id[i];
            for(int v : b.g[u]) {
                if(!dfn[v])continue;
                find(v);
                if(dfn[semi[val[v]]]<dfn[semi[u]]) semi[u]=semi[val[v]];
            }
            c.add(semi[u],u);
            bel[u] = fa[u]; u = fa[u];
            for(int v : c.g[u]) {
                find(v);
                if(semi[val[v]] == u) idom[v] = u;
                else idom[v] = val[v];
            }
        }
        for(int i = 2;i <= dfs_clock;i ++) {
            int u = id[i];
            if(idom[u] != semi[u]) idom[u] = idom[idom[u]];
        }
    }
    int ans[SZ];
    void dfs_ans(int u) {
        ans[u] = 1;
        for(int v : d.g[u]) {
            dfs_ans(v);
            ans[u] += ans[v];
        }
    }

    void addEdge(int u,int v) {
        a.add(u,v); b.add(v,u);
    }

    void init(int nn) {
        n = nn;
        dfs_clock = 0;
        for(int i = 1;i <= n;i ++) {
            semi[i] = bel[i] = val[i] = i;
            idom[i] = fa[i] = 0;
        }
    }

    void work(int s) {
        dfs(s);
        tarjan();
        for(int i = 1;i <= n;i ++) if(i != s) d.add(idom[i],i); /// 建立支配树
        dfs_ans(s);
    }
}dt;

int main() {
    int n = read(),m = read();
    dt.init(n);
    for(int i = 1;i <= m;i ++) {
        int u=read(),v=read();
        dt.addEdge(u,v);
    }
    dt.work(1);
    for(int i = 1;i <= n;i ++) printf("%d ",dt.ans[i]);
}
