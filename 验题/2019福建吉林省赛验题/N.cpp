#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

vector<int> g[SZ];

int a[SZ],del[SZ],fa[SZ],dfs_clock,dy[SZ],sz[SZ],dfn[SZ];
LL b[SZ];

void dfs(int u,int f) {
    dfn[u] = ++ dfs_clock;
    fa[u] = f;
    dy[dfs_clock] = u;
    sz[u] = 1;
    b[u] = a[u] + b[f];
    for(int v : g[u]) {
        if(v == f) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}

struct seg {
    int l,r;
    LL add;
    pli maxn;
}tree[SZ * 4];

void update(int p) {
    tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        if(g[dy[l]].size() == 1)
            tree[p].maxn = make_pair(b[dy[l]],dy[l]);
        else
            tree[p].maxn = make_pair(-1e18,0);
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushadd(int p,LL d) {
    tree[p].add += d;
    tree[p].maxn.first += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,LL d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushadd(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

int main() {
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    build(1,1,n);
    LL ans = 0;
    while(k --) {
        pli x = tree[1].maxn;
        if(x.first<0) break;
        ans += x.first;
        int now = x.second;
        while(now && !del[now]) {
            change(1,dfn[now],dfn[now]+sz[now]-1,-a[now]);
            del[now] = 1;
            now = fa[now];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
