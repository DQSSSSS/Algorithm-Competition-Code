#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 600010;
const int INF = 1e9 + 10;
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

int head[SZ],nxt[SZ],tot=0;

struct edge{
    int t;
    LL d;
}l[SZ];

void build(int f,int t,LL d)
{
    l[++tot].t=t;
    l[tot].d=d;
    nxt[tot]=head[f];
    head[f]=tot;
}

int deep[SZ],top[SZ],inseg[SZ];
int fa[SZ],son[SZ],sz[SZ];

void dfs_1(int u,int f)
{
    fa[u]=f;
    deep[u]=deep[f]+1;
    sz[u]=1;
    son[u] = 0;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=l[i].t;
        if(v==f) continue;
        dfs_1(v,u);
        sz[u]+=sz[v];
        if(!son[u]||sz[v]>sz[son[u]]) son[u]=v;
    }
}

int totp=0;
void dfs_2(int u,int topu)
{
    top[u]=topu;
    inseg[u]=++totp;
    if(!son[u]) return ;
    dfs_2(son[u],topu);
    for(int i=head[u];i;i=nxt[i])
    {
        int v=l[i].t;
        if(v==fa[u]||v==son[u]) continue;
        dfs_2(v,v);
    }
}

struct segment{
    int l,r;
    LL sum;
}tree[SZ*4];

void update(int p)
{
    tree[p].sum=tree[p<<1].sum + tree[p<<1|1].sum;
}

void build_tree(int p,int l,int r)
{
    tree[p].l=l;    tree[p].r=r;
    if(l==r)
    {
        tree[p].sum=0;
        return ;
    }
    int mid=(l+r)>>1;
    build_tree(p<<1,l,mid);
    build_tree(p<<1|1,mid+1,r);
    update(p);
}

void change(int p,int x,LL d)
{
    if(tree[p].l==tree[p].r)
    {
        tree[p].sum=d;
        return ;
    }
    int mid=(tree[p].l+tree[p].r)>>1;
    if(x<=mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(p);
}

LL ask_sum(int p,int l,int r)
{
    if(l<=tree[p].l&&tree[p].r<=r)
    {
        return tree[p].sum;
    }
    int mid=(tree[p].l+tree[p].r)>>1;
    LL ans=0;
    if(l<=mid) ans += ask_sum(p<<1,l,r);
    if(mid<r) ans += ask_sum(p<<1|1,l,r);
    return ans;
}

LL find_sum(int x,int y)
{
    int fx=top[x],fy=top[y];
    LL ans=0;
    while(fx!=fy)
    {
        if(deep[fx]<deep[fy]) swap(fx,fy),swap(x,y);
        ans+=ask_sum(1,inseg[fx],inseg[x]);
        x=fa[fx];fx=top[x];
    }
    if(x!=y)
    {
        if(deep[x]>deep[y]) swap(x,y);
        ans += ask_sum(1,inseg[x]+1,inseg[y]);
    }
    return ans;
}

int n,q;

int ff[SZ],tt[SZ];
LL dd[SZ];
void init()
{
	for(int i = 1;i <= n;i ++)
        head[i] = 0,top[i] = 0,inseg[i] = 0;
    tot=0;
    totp=0;
}

int main()
{
    int T = read();
    while(T --)
    {
        init();
        n = read(),q = read();
        for(int i=1;i<=n-1;i++)
        {
			ff[i] = read(),tt[i] = read(),dd[i] = read();
            build(ff[i],tt[i],dd[i]);
            build(tt[i],ff[i],dd[i]);
        }
        ff[n] = read(),tt[n] = read(),dd[n] = read();
        dfs_1(1,0);
        dfs_2(1,1);
        build_tree(1,1,n);

        for(int i=1;i<=n-1;i++)
        {
            if(deep[ff[i]]>deep[tt[i]]) swap(ff[i],tt[i]);
            change(1,inseg[tt[i]],dd[i]);
        }
        while(q --)
        {
            int opt = read(),a = read();
            LL b = read();
            if(opt == 0) {
            	if(a < n) change(1,inseg[tt[a]],b);
            	else dd[n] = b;
            }
            else {
            	LL ans1 = find_sum(a,b);
            	LL ans2 = find_sum(a,ff[n]) + dd[n] + find_sum(tt[n],b);
            	LL ans3 = find_sum(a,tt[n]) + dd[n] + find_sum(ff[n],b);
            	printf("%lld\n",min(ans1,min(ans2,ans3)));
            }
        }
    }
    return 0;
}
