#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 500010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};


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

int head[SZ],nxt[SZ],tot = 1,to[SZ],n;


void build(int u,int v)
{
    to[++ tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

int deep[SZ],sz[SZ],top[SZ],fa[SZ];
int son[SZ],inseg[SZ],intre[SZ];

void dfs_1(int u,int f)
{
    sz[u] = 1;
    deep[u] = deep[f] + 1;
    fa[u] = f;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v == f) continue;
        dfs_1(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v])
            son[u] = v;
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
        int v = to[i];
        if(v == fa[u] || v == son[u]) continue;
        dfs_2(v,v);
    }
}

int val[SZ];

struct segment
{
    int l,r;
    int sum,maxn;
}tree[SZ * 4];

void update(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].maxn = max(tree[p << 1].maxn,tree[p << 1 | 1].maxn);
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    if(l == r)
    {
        tree[p].sum = tree[p].maxn = val[intre[l]];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int x,int d)
{
    if(tree[p].l == tree[p].r)
    {
        tree[p].maxn = tree[p].sum = d;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p << 1,x,d);
    else change(p << 1 | 1,x,d);
    update(p);
}

int ask_max(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].maxn;
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = -INF;
    if(l <= mid) ans = max(ans,ask_max(p << 1,l,r));
    if(mid < r) ans = max(ans,ask_max(p << 1 | 1,l,r));
    return ans;
}

int ask_sum(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].sum;
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if(l <= mid) ans += ask_sum(p << 1,l,r);
    if(mid < r) ans += ask_sum(p << 1 | 1,l,r);
    return ans;
}

int find_max(int x,int y)
{
    int fx = top[x],fy = top[y],ans = -INF;
    while(fx != fy)
    {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        ans = max(ans,ask_max(1,inseg[fx],inseg[x]));
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    ans = max(ans,ask_max(1,inseg[x],inseg[y]));
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

int main()
{
    n = read();
    for(int i = 1;i < n;i ++)
    {
        int x = read(),y = read();
        build(x,y); build(y,x);
    }
    for(int i = 1;i <= n;i ++) val[i] = read();
    dfs_1(1,0); dfs_2(1,1);
    build(1,1,n);
    int q = read();
    while(q --)
    {
        char opt[12];
        scanf("%s",opt);
        int x = read(),y = read();
        if(opt[1] == 'H') change(1,inseg[x],y);
        else if(opt[1] == 'M') printf("%d\n",find_max(x,y));
        else printf("%d\n",find_sum(x,y));
    }
    return 0;
}
