#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int head[SZ],nxt[SZ],tot = 1,to[SZ];

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

int deep[SZ],inseg[SZ],intre[SZ],fa[SZ],top[SZ];
int dfs_clock = 0,son[SZ],sz[SZ];
void dfs_1(int u,int f)
{
    fa[u] = f;
    deep[u] = deep[f] + 1;
    sz[u] = 1;
    son[u] = 0;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v == f) continue;
        dfs_1(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs_2(int u,int topu)
{
    top[u] = topu;
    inseg[u] = ++ dfs_clock;
    intre[dfs_clock] = u;
    if(!son[u]) return ;
    dfs_2(son[u],topu);
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v == son[u] || v == fa[u]) continue;
        dfs_2(v,v);
    }
}

LL val[SZ],n,m;

struct seg
{
    int l,r;
    LL sum,add;
}tree[SZ];

void update(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushc(int p,LL d)
{
    tree[p].add += d;
    tree[p].sum += (tree[p].r - tree[p].l + 1) * d;
}

void pushdown(int p)
{
    LL d = tree[p].add;
    if(d)
        pushc(p << 1,d),pushc(p << 1 | 1,d),tree[p].add = 0;
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].add = 0;
    if(l == r)
    {
        tree[p].sum = val[intre[l]];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int l,int r,LL d)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        pushc(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1 | 1,l,r,d);
    update(p);
}

LL ask(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].sum;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans += ask(p << 1,l,r);
    if(mid < r) ans += ask(p << 1 | 1,l,r);
    return ans;
}

LL find_sum(int x)
{
    int fx = top[x];
    LL ans = 0;
    while(x)
    {
        ans += ask(1,inseg[fx],inseg[x]);
        x = fa[fx]; fx = top[x];
    }
    return ans;
}

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) val[i] = read();
    for(int i = 1;i < n;i ++)
    {
        int x = read(),y = read();
        build(x,y); build(y,x);
    }
    dfs_1(1,0); dfs_2(1,1);
    build(1,1,n);
    while(m --)
    {
        int opt = read(),x = read();
        LL y;
        if(opt == 1)
            y = read(),change(1,inseg[x],inseg[x],y);
        else if(opt == 2)
            y = read(),change(1,inseg[x],inseg[x] + sz[x] - 1,y);
        else
            printf("%lld\n",find_sum(x));
    }
    return 0;
}
