#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

vector<int> G[SZ];

int ans[SZ],w1[SZ],w2[SZ],deep[SZ];
int dfn[SZ],dfs_clock,anc[SZ][22];
vector<int> depNodes[SZ];

void dfs_lca(int u,int fa) {
    deep[u] = deep[fa] + 1;
    depNodes[deep[u]].push_back(u);
    dfn[u] = ++ dfs_clock;
    anc[u][0] = fa;
    for(int i = 1;anc[u][i-1];i ++) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
    for(int v : G[u]) {
        dfs_lca(v,u);
    }
}

void ask_lca(int u,int v) {
    if(deep[u]<deep[v]) swap(u,v);
    if(deep[u]>deep[v]) {
        int dd = deep[u] - deep[v];
        for(int i = 21;i >= 0;i --) {
            if(dd >> i & 1) {
                u = anc[u][i];
            }
        }
    }
    if(u == v) return u;
    for(int i = 21;i >= 0;i --) {
        if(anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
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

int main() {
    int n = read(),x = read();
    for(int i = 2;i <= n;i ++) {
        int p = read();
        G[p].push_back(i);
    }
    for(int i = 1;i <= n;i ++) {
        w1[i] = read();
        w2[i] = w1[i] ^ x;
    }
    dfs_lca(1);


    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        (ans += i ^ (n-ans[i])) %= mod;
    }
    cout << ans << endl;
}

