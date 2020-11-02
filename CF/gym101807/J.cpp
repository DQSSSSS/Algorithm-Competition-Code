#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
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
int dfn[SZ],sz[SZ],dfs_clock,fa[SZ];

void dfs(int u,int f) {
    sz[u] = 1;
    dfn[u] = ++ dfs_clock;
    fa[u] = f;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}

struct haha {
    int l,r;
    int mk;
}tree[SZ * 4];

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].mk = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushc(int p) {
    tree[p].mk ^= 1;
}

void pushdown(int p) {
    if(tree[p].mk) {
        pushc(p<<1);
        pushc(p<<1|1);
        tree[p].mk = 0;
    }
}

void change(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r);
    if(mid < r) change(p<<1|1,l,r);
}

int ask(int p,int x) {
    if(tree[p].l == tree[p].r) return tree[p].mk;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) return ask(p<<1,x);
    else return ask(p<<1|1,x);
}

int ff[SZ],tt[SZ],dd[SZ];

int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
        ff[i] = read();
        tt[i] = read();
        dd[i] = read()&1;
        g[ff[i]].push_back(tt[i]);
        g[tt[i]].push_back(ff[i]);
    }
    dfs(1,0);
    build(1,1,n);
    for(int i = 1;i < n;i ++) {
        if(fa[tt[i]] == ff[i]) swap(ff[i],tt[i]);
        int x = ff[i];
        if(dd[i] & 1) change(1,dfn[x],dfn[x]+sz[x]-1);
    }
    int q = read();
    while(q --) {
        int opt = read(),x = read(),y = read();
        if(opt == 1) {
            int ans = ask(1,dfn[x]) ^ ask(1,dfn[y]);
            if(ans) puts("WE NEED BLACK PANDA");
            else puts("JAKANDA FOREVER");
        }
        else {
            int d = dd[x]; y&=1;
            if(d == y) continue;
            dd[x] = y;
            int a = ff[x];
            change(1,dfn[a],dfn[a]+sz[a]-1);
        }
    }
}
