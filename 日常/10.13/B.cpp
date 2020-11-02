#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar();  }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}


int head[SZ],nxt[SZ],tot = 1,n,m,val[SZ];

struct edge
{
    int t,d;
}l[SZ];

void build(int f,int t,int d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

int deep[SZ],fa[SZ],sz[SZ];
int top[SZ],son[SZ],dfs_clock = 0,inseg[SZ],intre[SZ];

void dfs_1(int u,int f)
{
    fa[u] = f;
    sz[u] = 1;
    deep[u] = deep[f] + 1;
    son[u] = 0;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
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
        int v = l[i].t;
        if(v == fa[u] || v == son[u]) continue;
        dfs_2(v,v);
    }
}

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
    tree[p].c = d;
    tree[p].lx = tree[p].rx = d;
    tree[p].ans = 1;
}

void pushdown(int p)
{
    if(tree[p].c <= 100000)
        pushc(p << 1,tree[p].c),pushc(p << 1 | 1,tree[p].c),tree[p].c = 100001;
}

void build_seg(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].c = 100001;
    if(l == r)
    {
        tree[p].lx = tree[p].rx = val[intre[l]];
        tree[p].ans = 1;
        return ;
    }
    int mid = l + r >> 1;
    build_seg(p << 1,l,mid); build_seg(p << 1 | 1,mid + 1,r);
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

int ask(int p,int x)
{
    if(tree[p].l == tree[p].r)
        return tree[p].lx;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) return ask(p << 1,x);
    else return ask(p << 1 | 1,x);
}

int ask_ans(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].ans;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid && mid < r)
    {
        int d = 0;
        if(tree[p << 1].rx == tree[p << 1 | 1].lx) d = 1;
        return ask_ans(p << 1,l,r) + ask_ans(p << 1 | 1,l,r) - d;
    }
    else if(l <= mid) return ask_ans(p << 1,l,r);
    else if(mid < r) return ask_ans(p << 1 | 1,l,r);
}

int find_ans(int x,int y)
{
    int fx = top[x],fy = top[y],ans = 0,lstx = -1,lsty = -1;
    while(fx != fy)
    {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy),swap(lstx,lsty);
        int d = 0;
        if(ask(1,inseg[x]) == lstx) d = 1;
        ans += ask_ans(1,inseg[fx],inseg[x]) - d;
        lstx = ask(1,inseg[fx]);

        x = fa[fx]; fx = top[x];
    }
    if(x != y)
    {
        if(deep[x] > deep[y]) swap(x,y),swap(lstx,lsty);
        int d = 0;
        if(ask(1,inseg[y]) == lsty) d ++;
        if(ask(1,inseg[x] + 1) == lstx) d ++;
        ans += ask_ans(1,inseg[x] + 1,inseg[y]) - d;
    }
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
            build(x,y,d); build(y,x,d);
        }
        dfs_1(1,0); dfs_2(1,1); 
        for(int i = 1;i < n;i ++)
        {
            int x = deep[ff[i]] > deep[tt[i]] ? ff[i] : tt[i];
            val[x] = dd[i];
        }
        build_seg(1,1,n);
        for(int i = 1;i <= m;i ++)
        {
            char opt[10];
            scanf("%s",opt);
            int x = read(),y = read(),d,ans;
            if(opt[0] == 'Q') ans = find_ans(x,y),printf("%d\n",ans == 1 ? 0 : ans);
            else d = read(),find_change(x,y,d);
        }
    }
    return 0;
}
