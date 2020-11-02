#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const int INF = 1e9 + 10;


LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;
int a[SZ],lsh[SZ],ans[SZ];

vector<int> g[SZ];

struct seg
{
    int lc,rc;
    int sz;
}tree[SZ];

int Segsz = 0;

void update(int p)
{
    tree[p].sz = tree[tree[p].lc].sz + tree[tree[p].rc].sz;
}

void insert(int &p,int l,int r,int x)
{
    if(!p) p = ++ Segsz;
    if(l == r) { tree[p].sz ++; return ; }
    int mid = l + r >> 1;
    if(x <= mid) insert(tree[p].lc,l,mid,x);
    else insert(tree[p].rc,mid + 1,r,x);
    update(p);
}

int ask(int p,int x)
{
    int ans = 0;
    int l = 1,r = m;
    while(l != r)
    {
        int mid = l + r >> 1;
        if(x <= mid) ans += tree[tree[p].rc].sz,p = tree[p].lc,r = mid;
        else p = tree[p].rc,l = mid + 1;
    }
    return ans;
}

int root[SZ];

int merge(int x,int y)
{
    if(!x) return y;
    if(!y) return x;
    tree[x].lc = merge(tree[x].lc,tree[y].lc);
    tree[x].rc = merge(tree[x].rc,tree[y].rc);
    tree[x].sz += tree[y].sz;
    update(x);
    return x;
}

void dfs(int u)
{
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        dfs(v);
        root[u] = merge(root[u],root[v]);
    }
    ans[u] = ask(root[u],a[u]);
    insert(root[u],1,m,a[u]);
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++) lsh[i] = a[i] = read();
    sort(lsh + 1,lsh + 1 + n);
    m = unique(lsh + 1,lsh + 1 + n) - lsh - 1;
    for(int i = 1;i <= n;i ++) a[i] = lower_bound(lsh + 1,lsh + 1 + m,a[i]) - lsh;
    for(int i = 2;i <= n;i ++) g[read()].push_back(i);
    dfs(1);
    for(int i = 1;i <= n;i ++) printf("%d\n",ans[i]);
    return 0;
}
