#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1073741823 + 10;
const int mod = 998244353;
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

int top[SZ],fa[SZ],sz[SZ],son[SZ],dfn[SZ],dfs_clock,deep[SZ];

void dfs1(int u,int f) {
    sz[u] = 1;
    deep[u] = deep[f] + 1;
    fa[u] = f;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs1(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2(int u,int topu) {
    top[u] = topu;
    dfn[u] = ++ dfs_clock;
    if(son[u]) dfs2(son[u],topu);
    for(int v : g[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v);
    }
}

struct seg{
    int l,r,mx,mn,add;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
    tree[p].mn = min(tree[p<<1].mn,tree[p<<1|1].mn);
}

void pushadd(int p,int d) {
    tree[p].mx += d;
    tree[p].mn += d;
    tree[p].add += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void change(int p,int l,int r,int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushadd(p,d); return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

int ask_max(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans = max(ans,ask_max(p<<1,l,r));
    if(mid < r) ans = max(ans,ask_max(p<<1|1,l,r));
    return ans;
}

int ask_min(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mn;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = INF;
    if(l <= mid) ans = min(ans,ask_min(p<<1,l,r));
    if(mid < r) ans = min(ans,ask_min(p<<1|1,l,r));
    return ans;
}

void change(int x,int y,int d) {
    int fx = top[x],fy = top[y];
    while(fx != fy) {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        change(1,dfn[fx],dfn[x],d);
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    change(1,dfn[x],dfn[y],d);
}

int ask_max(int x,int y) {
    int fx = top[x],fy = top[y],ans = 0;
    while(fx != fy) {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        ans = max(ans,ask_max(1,dfn[fx],dfn[x]));
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    ans = max(ans,ask_max(1,dfn[x],dfn[y]));
    return ans;
}

int ask_min(int x,int y) {
    int fx = top[x],fy = top[y],ans = INF;
    while(fx != fy) {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        ans = min(ans,ask_min(1,dfn[fx],dfn[x]));
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    ans = min(ans,ask_min(1,dfn[x],dfn[y]));
    return ans;
}

int ask_len(int x,int y) {
    int fx = top[x],fy = top[y],ans = 0;
    while(fx != fy) {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        ans += deep[x] - deep[fx];
        x = fa[fx]; fx = top[x]; ans ++;
    }
    if(deep[x] > deep[y]) swap(x,y);
    ans += deep[y] - deep[x];
    return ans;
}


struct haha {
    int x,y,len,k;
}a[SZ];

bool cmp(haha a,haha b) { return a.len > b.len; }

int main(){
    int n = read(),m = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    for(int i = 1;i <= m;i ++) {
        a[i].x = read(),a[i].y = read();
        a[i].len = ask_len(a[i].x,a[i].y);
    }
    sort(a+1,a+1+m,cmp);
   /* for(int i = 1;i <= n;i ++) printf("%d ",deep[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",son[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",top[i]); puts("");
    for(int i = 1;i <= m;i ++) cout << a[i].x << " " << a[i].y << " " << a[i].len << endl;*/
    for(int i = 1;i <= m;i ++) a[i].k = (rand()<<16|rand()) & 1073741823;
    for(int i = 1;i <= m;i ++) {
        int x = a[i].x,y = a[i].y;
        if(ask_max(x,y) == 0) change(x,y,a[i].k);
        else {
       //    cout << i << " " << ask_max(x,y) << " " << ask_min(x,y) << endl;
            if(ask_max(x,y) == ask_min(x,y)) {
                int d = ask_max(x,y);
                change(x,y,-d);
                change(x,y,d^a[i].k);
                continue;
            }
            return puts("No"),0;
        }
    }
    puts("Yes");
    return 0;
}

/**
3 3
1 2
2 3
1 2
2 3
1 3
*/
