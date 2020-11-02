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

int head[SZ],nxt[SZ],tot = 1,to[SZ],n,m;


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
    son[u] = 0;
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
    int ans,lx,rx,c;
}tree[SZ * 4];

void update(int p)
{
    int d = 0;
    if(tree[p << 1].rx == tree[p << 1 | 1].lx) d = 1;
    tree[p].ans = tree[p << 1].ans + tree[p << 1 | 1].ans - d;
    tree[p].lx = tree[p << 1].lx;
    tree[p].rx = tree[p << 1 | 1].rx;
}

void pushc(int p,int d)
{
    tree[p].ans = 1;
    tree[p].lx = tree[p].rx = d;
    tree[p].c = d;
}

void pushdown(int p)
{
    if(tree[p].c <= 100000)
        pushc(p << 1,tree[p].c),pushc(p << 1 | 1,tree[p].c),tree[p].c = 100001;
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].c = 100001;
    if(l == r)
    {
        tree[p].ans = 1;
        tree[p].lx = tree[p].rx = val[intre[l]];
        return ;
    }
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

int ask_ans(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].ans;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if(l <= mid && mid < r)
    {
        int d = 0;
        if(tree[p << 1].rx == tree[p << 1 | 1].lx) d = 1;
        ans = ask_ans(p << 1,l,r) + ask_ans(p << 1 | 1,l,r) - d;
    }
    else if(l <= mid) ans = ask_ans(p << 1,l,r);
    else if(mid < r) ans = ask_ans(p << 1 | 1,l,r);
    return ans;
}

int ask_c(int p,int x)
{
    if(tree[p].l == tree[p].r)
        return tree[p].lx;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans;
    if(x <= mid) ans = ask_c(p << 1,x);
    else ans = ask_c(p << 1 | 1,x);
    return ans;
}

int find_ans(int x,int y)
{
    int fx = top[x],fy = top[y],ans = 0,cx = 100001,cy = 100001;
    while(fx != fy)
    {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy),swap(cx,cy);
        int d = 0;
        if(cx == ask_c(1,inseg[x])) d = 1;
        ans += ask_ans(1,inseg[fx],inseg[x]) - d;

        cx = ask_c(1,inseg[fx]); x = fa[fx]; fx = top[x];
    }
    if(x != y)
    {
        if(deep[x] > deep[y]) swap(x,y),swap(cx,cy);
        ans += ask_ans(1,inseg[x] + 1,inseg[y]);
        int d = 0;
        if(cx == ask_c(1,inseg[x] + 1)) d ++;
        if(cy == ask_c(1,inseg[y])) d ++;
        ans -= d;
    }
    else
        if(cx == cy) ans --;
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
    if(x != y)
    {
        if(deep[x] > deep[y]) swap(x,y);
        change(1,inseg[x] + 1,inseg[y],d);
    }
}

int ff[SZ],tt[SZ],dd[SZ];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        tot = 1; memset(head,0,sizeof(head)); dfs_clock = 0;

        for(int i = 1;i < n;i ++)
        {
            int x = read(),y = read(),d = read();
            ff[i] = x; tt[i] = y; dd[i] = d;
            build(x,y); build(y,x);
        }
        dfs_1(1,0); dfs_2(1,1);
        for(int i = 1;i < n;i ++) if(deep[ff[i]] > deep[tt[i]]) swap(ff[i],tt[i]);
        for(int i = 1;i < n;i ++) val[tt[i]] = dd[i];
        val[1] = -INF;
        build(1,1,n);
        while(m --)
        {
            char opt[12];
            scanf("%s",opt);
            int x = read(),y = read(),d;
            if(opt[0] == 'Q')
                printf("%d\n",find_ans(x,y));
            else
                d = read(),find_change(x,y,d);
        }
    }
   return 0;
}
/*
9 233
1 2 2
2 3 1
1 7 2
1 4 2
3 5 2
3 6 1
5 8 2
5 9 3
Query 1 8
Change 2 6 3
Query 7 6

*/
