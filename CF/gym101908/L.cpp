#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
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

int deep[SZ],top[SZ],dfs_clock,dfn[SZ],son[SZ],sz[SZ],fa[SZ];

void dfs_1(int u,int f) {
    sz[u] = 1;
    son[u] = 0;
    fa[u] = f;
    deep[u] = deep[f] + 1;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs_1(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs_2(int u,int tu) {
    dfn[u] = ++ dfs_clock;
    top[u] = tu;
    if(son[u]) dfs_2(son[u],tu);
    for(int v : g[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs_2(v,v);
    }
}

struct seg {
    int l,r;
    int add,sum;
}tree[SZ * 4];

void update(int p) {
    tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].sum = 0;
    tree[p].add = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushadd(int p,int d) {
    tree[p].add += d;
    tree[p].sum += d * (tree[p].r - tree[p].l + 1);
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,int d) {
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

int ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans += ask(p<<1,l,r);
    if(mid < r) ans += ask(p<<1|1,l,r);
    return ans;
}

void add(int x,int y,int d) {
    int fx = top[x],fy = top[y];
    while(fx != fy) {
        if(deep[fx] < deep[fy]) swap(fx,fy),swap(x,y);
        change(1,dfn[fx],dfn[x],d);
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    change(1,dfn[x],dfn[y],d);
}

int ask(int x,int y) {
    int fx = top[x],fy = top[y],ans = 0;
    while(fx != fy) {
        if(deep[fx] < deep[fy]) swap(fx,fy),swap(x,y);
        ans += ask(1,dfn[fx],dfn[x]);
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    ans += ask(1,dfn[x],dfn[y]);
    return ans;
}

int main() {
    int n = read(),m = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs_1(1,0);
    dfs_2(1,1);
    build(1,1,n);
  //  for(int i = 1;i <= n;i ++) cout << dfn[i] << " "; puts("");
    //for(int i = 1;i <= n;i ++) cout << top[i] << " "; puts("");
    while(m --) {
        int a = read(),b = read(),c = read(),d = read();
        add(a,b,1);
        printf("%d\n",ask(c,d));
        add(a,b,-1);
    }
}
