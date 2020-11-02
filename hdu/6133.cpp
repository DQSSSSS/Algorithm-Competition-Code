#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 100001;
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


int val[SZ],lsh[SZ];

namespace Seg
{
    struct segment
    {
        int lc,rc,sz;
        LL sum,ans;
    }tree[1670000];

    int Segsz = 0;
    int newnode()
    {
        int p = ++ Segsz;
        tree[p].lc = tree[p].rc = 0;
        tree[p].sz = tree[p].sum = tree[p].ans = 0;
        return p;
    }

    void update(int p)
    {
        tree[p].sz = tree[tree[p].lc].sz + tree[tree[p].rc].sz;
        tree[p].sum = tree[tree[p].lc].sum + tree[tree[p].rc].sum;
        tree[p].ans = tree[tree[p].lc].ans + tree[tree[p].rc].ans;
    }

    void insert(int &p,int l,int r,int x)
    {
        if(!p) p = newnode();
        if(l == r) { tree[p].sz = 1; tree[p].ans = tree[p].sum = lsh[x]; return ;}
        int mid = l + r >> 1;
        if(x <= mid) insert(tree[p].lc,l,mid,x);
        else insert(tree[p].rc,mid + 1,r,x);
        update(p);
    }
}
using namespace Seg;

int n,m;
vector<int> g[SZ];

int root[SZ];

int merge(int x,int y)
{
    if(!x) return y;
    if(!y) return x;
    tree[x].lc = merge(tree[x].lc,tree[y].lc);
    tree[x].rc = merge(tree[x].rc,tree[y].rc);
    tree[x].sz += tree[y].sz; tree[x].sum += tree[y].sum;
    if(!tree[x].lc && !tree[x].rc) tree[x].ans = (tree[x].sz + 1) * tree[x].sum >> 1ll;
    else tree[x].ans = tree[tree[x].lc].ans + tree[tree[x].rc].ans + tree[tree[x].lc].sum * tree[tree[x].rc].sz;
    return x;
}

void dfs(int u,int f)
{
    int x = lower_bound(lsh + 1,lsh + 1 + m,val[u]) - lsh;
    insert(root[u],1,m,x);
    //cout << tree[root[u]].ans << endl;
    //for(int i = head[u];i;i = nxt[i])
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == f) continue;
        dfs(v,u);
        root[u] = merge(root[u],root[v]);
    }
}

void init()
{
    Segsz = 0;
    for(int i = 0;i < 100001;i ++) root[i] = 0,g[i].clear();
    memset(tree,0,sizeof(tree));
}

int main()
{
    //freopen("in.txt","r",stdin); freopen("sb.txt","w",stdout);
    int T = read();
    while(T --)
    {
        init();
        n = read();
        for(int i = 1;i <= n;i ++) val[i] = read(),lsh[i] = val[i];
        sort(lsh + 1,lsh + 1 + n);
        m = unique(lsh + 1,lsh + 1 + n) - lsh - 1;

        for(int i = 1;i < n;i ++)
        {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
        for(int i = 1;i <= n;i ++)
            printf("%lld ",tree[root[i]].ans);
        puts("");
    }
    return 0;
}
/*
1
5
1 2 3 4 5
1

*/
