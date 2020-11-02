#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100100;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int n,m;
vector<int> g[SZ];

int deep[SZ],anc[SZ][22],suf[SZ],pre[SZ],tree[SZ*2],dfs_clock = 0;

void dfs(int u,int f) {
    pre[u] = ++ dfs_clock;
    deep[u] = deep[f] + 1;
    anc[u][0] = f;
    for(int i = 1;anc[u][i-1];i ++) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == f) continue;
        dfs(v,u);
    }
    suf[u] = ++ dfs_clock;
}

int ask_lca(int u,int v) {
    if(deep[u] < deep[v]) swap(u,v);
    if(deep[u] > deep[v]) {
        int dd = deep[u] - deep[v];
        for(int i = 20;i >= 0;i --)
            if(dd >> i & 1)
                u = anc[u][i];
    }
    if(u == v) return u;
    for(int i = 20;i >= 0;i --)
        if(anc[u][i] != anc[v][i])
            u = anc[u][i],v = anc[v][i];
    return anc[u][0];
}

void add(int x,int d) {
    for(int i = x;i <= 2*n;i += i & -i) tree[i] += d;
}

int ask(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += tree[i];
    return ans;
}

int node[SZ],h[SZ];
bool use[SZ];
bool cmp(int a,int b) { return h[a] < h[b]; }

int f[SZ][310];

int main() {
    n = read(),m = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    while(m --) {
        int k = read(),m = read(),r = read();
        for(int i = 1;i <= k;i ++) {
            int x = read();
            add(pre[x],1);
            add(suf[x],-1);
            node[i] = x;
            use[x] = 1;
        }
        int rd = ask(pre[r]);
        for(int i = 1;i <= k;i ++) {
            int x = node[i],lca = ask_lca(x,r);
            int nd = ask(pre[x]),lcad = ask(pre[lca]);
            h[x] = nd + rd - 2 * lcad + use[lca] - 1;
        }
        sort(node + 1,node + 1 + k,cmp);

        for(int i = 0;i <= k;i ++)
            for(int j = 0;j <= m;j ++) {
                f[i][j] = 0;
            }

        f[0][0] = 1;
        for(int i = 1;i <= k;i ++)
            for(int j = 1;j <= m;j ++) {
                if(j>h[node[i]]) f[i][j] += 1ll*f[i-1][j] * (j-h[node[i]]) % mod;
                if(j) (f[i][j] += f[i-1][j-1]) %= mod;
            }
        LL ans = 0;
        for(int i = 1;i <= m;i ++) (ans += f[k][i]) %= mod;
        ans += mod; ans %= mod;
        printf("%lld\n",ans);

        for(int i = 1;i <= k;i ++) {
            int x = node[i];
            use[x] = 0;
            add(pre[x],-1);
            add(suf[x],1);
        }
    }
    return 0;
}
