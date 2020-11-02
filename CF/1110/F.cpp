#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500100;
const LL INF = 1e18 + 10;
const int mod = 998244353;
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
LL a[SZ],ans[SZ];

struct edge {
    int t;
    LL d;
};

vector<edge> g[SZ];

struct seg {
    int l,r;
    LL minn,add;
}tree[SZ * 4];

void update(int p) {
    tree[p].minn = min(tree[p <<1].minn,tree[p <<1 | 1].minn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].minn = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid);
    build(p << 1|1,mid+1,r);
    update(p);
}

void pushc(int p,LL d) {
    tree[p].add += d;
    tree[p].minn += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushc(p<<1,tree[p].add);
        pushc(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,LL d) {
    if(l > r) return ;
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1|1,l,r,d);
    update(p);
}

LL Ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].minn;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = INF;
    if(l <= mid) ans = min(ans,Ask(p << 1,l,r));
    if(mid < r) ans = min(ans,Ask(p << 1|1,l,r));
    return ans;
}

int sz[SZ];

void dfs(int u,LL d) {
    sz[u] = 1;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].t;
        dfs(v,d + g[u][i].d);
        sz[u] += sz[v];
    }
    if(g[u].size() == 0) a[u] = d;
    else a[u] = INF;
}

struct haha {
    int l,r,id;
};

vector<haha> ask[SZ];

void dfs2(int u) {
    for(int i = 0;i < ask[u].size();i ++) {
        ans[ask[u][i].id] = Ask(1,ask[u][i].l,ask[u][i].r);
    }
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].t;
        LL d = g[u][i].d;
        change(1,v,v+sz[v]-1,-d);
        change(1,1,v-1,d);
        change(1,v+sz[v],n,d);
        dfs2(v);
        change(1,v,v+sz[v]-1,d);
        change(1,1,v-1,-d);
        change(1,v+sz[v],n,-d);
    }
}

int main() {
    n = read(),m = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back((edge){i+1,y});
    }
    dfs(1,0);
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        ask[x].push_back((haha){y,z,i});
    }
    build(1,1,n);
    dfs2(1);
    for(int i = 1;i <= m;i ++) printf("%lld\n",ans[i]);
    return 0;
}
