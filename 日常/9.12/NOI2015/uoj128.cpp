#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int head[SZ],nxt[SZ],tot = 1,n;

struct edge
{
    int t;
}l[SZ];

void build(int f,int t)
{
    l[++ tot] = (edge){t};
    nxt[tot] = head[f];
    head[f] = tot;
}

int deep[SZ],inseg[SZ],intre[SZ];
int sz[SZ],top[SZ],son[SZ],fa[SZ];
void dfs_1(int u,int f)
{
    fa[u] = f;
    deep[u] = deep[f] + 1;
    sz[u] = 1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == f) continue;
        dfs_1(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}
int dfs_clock = 0;
void dfs_2(int u,int topu)
{
    top[u] = topu;
    inseg[u] = ++ dfs_clock;
    intre[dfs_clock] = u;
    if(!son[u]) return ;
    dfs_2(son[u],topu);
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa[u] || v == son[u]) continue;
        dfs_2(v,v);
    }
}

struct segment
{
    int l,r;
    int sum,c;
}tree[SZ];

void update(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushc(int p,int v)
{
    tree[p].c = v;
    tree[p].sum = v * (tree[p].r - tree[p].l + 1);
}

void pushdown(int p)
{
    if(tree[p].c != -1)
    {
        pushc(p << 1,tree[p].c);
        pushc(p << 1 | 1,tree[p].c);
        tree[p].c = -1;
    }
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].c = -1; tree[p].sum = 0;
    if(l == r)
        return ;
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int l,int r,int d)
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

int ask_sum(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].sum;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans += ask_sum(p << 1,l,r);
    if(mid < r) ans += ask_sum(p << 1 | 1,l,r);
    return ans;
}

int find_sum(int x,int y)
{
    int fx = top[x],fy = top[y],ans = 0;
    while(fx != fy)
    {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        ans += ask_sum(1,inseg[fx],inseg[x]);
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    ans += ask_sum(1,inseg[x],inseg[y]);
    return ans;
}

void find_change(int x,int y,int d)
{
    int fx = top[x],fy = top[y];
    while(fx != fy)
    {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        change(1,inseg[fx],inseg[x],d);
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    change(1,inseg[x],inseg[y],d);
}

int main()
{
    n = read();
    for(int i = 2;i <= n;i ++)
    {
        int x = read() + 1;
        build(x,i);
    }
    dfs_1(1,0); dfs_2(1,0);
    build(1,1,n);
    int m = read();
    while(m --)
    {
        char opt[20];
        scanf("%s",opt); int x = read() + 1;
        if(opt[0] == 'i')
            printf("%d\n",deep[x] - find_sum(1,x)),find_change(1,x,1);
        else
            printf("%d\n",ask_sum(1,inseg[x],inseg[x] + sz[x] - 1)),change(1,inseg[x],inseg[x] + sz[x] - 1,0);
    }
    return 0;
}
