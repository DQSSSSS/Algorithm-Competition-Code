#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const LL INF = 1e18 + 10;
const int SZ = 1e6 + 10;
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

vector<pii> g[SZ];
vector<int> g2[SZ];

int anc[22][SZ],mark[SZ],deep[SZ];
LL mn[22][SZ];
int dfn[SZ],dfs_clock;

void dfs(int u,int fa) {
    dfn[u] = ++ dfs_clock;
    deep[u] = deep[fa] + 1;
    anc[0][u] = fa;
    for(int i = 1;anc[i-1][u];i ++) {
        anc[i][u] = anc[i-1][anc[i-1][u]];
        mn[i][u] = min(mn[i-1][u],mn[i-1][anc[i-1][u]]);
    }
    for(pii p : g[u]) {
        int v = p.first;
        if(v == fa) continue;
        mn[0][v] = p.second;
        dfs(v,u);
    }
}

int ask_lca(int u,int v) {
    if(deep[u] < deep[v]) swap(u,v);
    int dd = deep[u] - deep[v];
    for(int i = 20;i >= 0;i --) if(dd>>i&1) u = anc[i][u];
    if(u == v) return u;
    for(int i = 20;i >= 0;i --) if(anc[i][u] != anc[i][v]) u = anc[i][u],v = anc[i][v];
    return anc[0][u];
}

LL ask_min(int u,int v) {
    if(u == 1) return INF;
    int dd = deep[u] - deep[v];
    LL ans = INF;
    for(int i = 20;i >= 0;i --) if(dd>>i&1) ans = min(ans,mn[i][u]),u = anc[i][u];
    return ans;
}

LL dfs2(int u,int fa) {
    LL ans = 0;
    for(int v : g2[u]) {
        ans += dfs2(v,u);
    }
    if(mark[u]) ans = ask_min(u,fa);
    else ans = min(ans,ask_min(u,fa));
    return ans;
}

vector<int> build_vt(vector<int> &nodes) {
    sort(nodes.begin(),nodes.end(),[](int x,int y) { return dfn[x] < dfn[y]; });
    stack<int> S; S.push(nodes[0]);
    vector<int> nodeList; nodeList.push_back(nodes[0]);
    for(int i = 1;i < nodes.size();i ++) {
        int x = nodes[i];
        int lca = ask_lca(S.top(),x);
        if(lca != S.top()) {
            int u = S.top(); nodeList.push_back(u); S.pop();
            while(S.size() && dfn[S.top()] >= dfn[lca]) {
                g2[S.top()].push_back(u); u = S.top();
                nodeList.push_back(u); S.pop();
            }
            if(lca != u) {
                g2[lca].push_back(u);
            }
            S.push(lca);
        }
        S.push(x);
    }
    while(S.size() > 1) {
        int u = S.top(); nodeList.push_back(u); S.pop();
        g2[S.top()].push_back(u);
    }
    return nodeList;
}

int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read(),z = read();
        g[x].push_back(make_pair(y,z));
        g[y].push_back(make_pair(x,z));
    }
    dfs(1,0);
    int m = read();
    while(m --) {
        int k = read();
        vector<int> nodes; nodes.push_back(1);
        while(k --) {
            int x;
            nodes.push_back(x = read());
            mark[x] = 1;
        }
        vector<int> tmp = build_vt(nodes);
        printf("%lld\n",dfs2(1,0));
        for(int x : tmp) mark[x] = 0,g2[x].clear();
    }
}
