#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const LL INF = 1e18 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,k,a[SZ];
vector<int> g[SZ];

void build_graph() {
    stack<int> S;
    for(int i = n;i >= 1;i --) {
        while(S.size() && a[S.top()] <= a[i]) S.pop();
        if(S.size()) g[S.top()].push_back(i);
        S.push(i);
    }
}

struct seg {
    int l,r;
    int add,maxn;
}tree[SZ * 4];

void update(int p) {
    tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushadd(int p,int d) {
    tree[p].add += d;
    tree[p].maxn += d;
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

int dfn[SZ],sz[SZ],dfs_clock;
void dfs(int u) {
    dfn[u] = ++ dfs_clock;
    sz[u] = 1;
    for(int v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

int main() {
    n = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    build_graph();
    for(int i = n;i >= 1;i --)
        if(!dfn[i])
            dfs(i);
    build(1,1,n);
    for(int i = 1;i <= k;i ++) change(1,dfn[i],dfn[i]+sz[i]-1,1);
    for(int i = k;i <= n;i ++) {
        printf("%d ",tree[1].maxn);
        if(i<n) change(1,dfn[i+1],dfn[i+1]+sz[i+1]-1,1);
        change(1,dfn[i-k+1],dfn[i-k+1]+sz[i-k+1]-1,-1);
    }
}
