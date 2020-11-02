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

struct edge {
    int t,d;
};

vector<edge> g[SZ];

LL sum[SZ],up[SZ],down[SZ],sumup[SZ];
int fa[SZ];

void dfs1(int u,int f) {
    fa[u] = f;
    for(edge e : g[u]) {
        int v = e.t;
        if(v == f) continue;
        dfs1(v,u);
    }
}

void dfs2(int u,int f) {
    sumup[u] = up[u];
    for(edge e : g[u]) {
        int v = e.t;
        if(v == f) continue;
        dfs2(v,u);
        sumup[u] += up[v];
    }
}

int dfn[SZ],dfs_clock,sz[SZ];

void dfs3(int u,int f) {
    sum[u] = sum[f] + sumup[u] + down[u];

    dfn[u] = ++ dfs_clock;
    sz[u] = 1;
    for(edge e : g[u]) {
        int v = e.t;
        if(v == f) continue;
        dfs3(v,u);
        sz[u] += sz[v];
    }
}

struct seg {
    int l,r;
    LL add;
    pli minn;
}tree[SZ * 4];

void update(int p) {
    tree[p].minn.first = min(tree[p<<1].minn.first,tree[p<<1|1].minn.first);
    if(tree[p<<1].minn.first == tree[p].minn.first)
        tree[p].minn.second += tree[p<<1].minn.second;
    if(tree[p<<1|1].minn.first == tree[p].minn.first)
        tree[p].minn.second += tree[p<<1|1].minn.second;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].minn = make_pair(0,0);
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushadd(int p,LL d) {
    tree[p].add += d;
    tree[p].minn.first += d;
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

int ask(int p,int l,int r,LL s) {
    if(l <= tree[p].l && tree[p].r <= r) {
        if(tree[p].minn.first == s)
            return tree[p].minn.second;
        return 0;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans += ask(p<<1,l,r,s);
    if(mid < r) ans += ask(p<<1|1,l,r,s);
    return ans;
}

int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read(),z = read();
        g[x].push_back((edge){y,z});
        g[y].push_back((edge){x,z});
    }

    dfs1(1,0);
    for(int u = 1;u <= n;u ++) {
        map<int,int> mark;
        for(edge e : g[u]) {
            mark[e.d] ++;
        }
        for(edge e : g[u]) {
            if(mark[e.d] >= 2) {
                if(fa[u] == e.t) up[e.t] ++;
                else down[e.t] ++;
            }
        }
    }
    dfs2(1,0);
    dfs3(1,0);

    build(1,1,n);

    for(int i = 1;i <= n;i ++) cout << up[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) cout << sumup[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) cout << down[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) cout << sum[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) {
        change(1,dfn[i],dfn[i]+sz[i]-1,sum[i] - sumup[i]);
    }

    int q = read();
    while(q --) {
        int x = read();
        printf("%d\n",ask(1,dfn[x],dfn[x]+sz[x]-1,sum[x]));
    }
    return 0;
}
