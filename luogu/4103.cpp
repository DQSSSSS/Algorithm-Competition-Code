#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
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

vector<int> g[SZ];
vector<int> g2[SZ];

int anc[22][SZ],mark[SZ],deep[SZ];
int dfn[SZ],dfs_clock;

void dfs(int u,int fa) {
    dfn[u] = ++ dfs_clock;
    deep[u] = deep[fa] + 1;
    anc[0][u] = fa;
    for(int i = 1;anc[i-1][u];i ++) {
        anc[i][u] = anc[i-1][anc[i-1][u]];
    }
    for(int v : g[u]) {
        if(v == fa) continue;
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

int sz[SZ];
int ans1,ans2;

pii dfs2(int u,int fa) {
    if(mark[u]) {
        sz[u] = 1;
        int maxd = 0;
        for(int v : g2[u]) {
            pii p = dfs2(v,u);
            sz[u] += sz[v];
            ans1 = max(ans1,p.first + maxd);
            ans2 = min(ans2,p.second);
            maxd = max(maxd,p.first);
        }
        int d = deep[u] - deep[fa];
        return make_pair(d + maxd,d);
    }
    else {
        sz[u] = 0;
        int maxd = -INF,mind = INF;
        for(int v : g2[u]) {
            pii p = dfs2(v,u);
            sz[u] += sz[v];
            ans1 = max(ans1,maxd + p.first);
            ans2 = min(ans2,mind + p.second);
            maxd = max(maxd,p.first);
            mind = min(mind,p.second);
        }
        int d = deep[u] - deep[fa];
        return make_pair(maxd + d,mind + d);
    }
}

vector<int> build_vt(vector<int> &nodes) {
    auto cmp = [](int x,int y) { return dfn[x] < dfn[y]; };
    sort(nodes.begin(),nodes.end(),cmp);
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
    nodeList.push_back(S.top());
    sort(nodeList.begin(),nodeList.end(),cmp);
    nodeList.resize(unique(nodeList.begin(),nodeList.end()) - nodeList.begin());
    return nodeList;
}

void work(vector<int> &nodes) {
    int sum = nodes.size();
    vector<int> tmp = build_vt(nodes);
    int rt = 0;
 //   for(int u : tmp) cout << u << " "; puts("");
    for(int u : tmp) {
        if(!rt || deep[u] < deep[rt]) rt = u;
    }
  //  cout << rt << endl;
    ans1 = -INF,ans2 = INF;
    dfs2(rt,0);
    LL ans3 = 0;
    for(int u : tmp) {
        for(int v : g2[u]) {
            int d = deep[v] - deep[u];
            ans3 += 1ll * d * sz[v] * (sum - sz[v]);
        }
    }
    printf("%lld %d %d\n",ans3,ans2,ans1);
    for(int x : tmp) mark[x] = 0,g2[x].clear();
}

int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    int m = read();
    while(m --) {
        int k = read();
        vector<int> nodes;
        while(k --) {
            int x;
            nodes.push_back(x = read());
            mark[x] = 1;
        }
        work(nodes);
    }
}

/*
10
2 1
3 2
4 1
5 2
6 4
7 5
8 6
9 7
10 7
5
6
5 4 8 3 9 10
*/
