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
#include<set>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 5000010;
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

namespace Seg
{
    struct segment
    {
        int lc,rc;
        int sz;
    }tree[SZ];

    int Segsz = 0;
    int newnode() { return ++ Segsz; }

    void update(int p)
    {
        tree[p].sz = tree[tree[p].lc].sz + tree[tree[p].rc].sz;
    }

    void insert(int &p,int l,int r,int x)
    {
        if(!p) p = newnode();
        if(l == r) { tree[p].sz = 1; return ; }
        int mid = l + r >> 1;
        if(x <= mid) insert(tree[p].lc,l,mid,x);
        else insert(tree[p].rc,mid + 1,r,x);
        update(p);
    }

    void init() { Segsz = 0; }
}

using namespace Seg;

int n,m,totp;
int val[SZ],root[SZ],L[SZ],R[SZ];

void read_tree(int &p)
{
    if(!p) p = ++ totp;
    val[p] = read();
    if(!val[p])
        read_tree(L[p]),read_tree(R[p]);
}

LL cnt1,cnt2,ans = 0;

int merge(int x,int y)
{
    if(!x) return y;
    if(!y) return x;
    cnt1 += (LL)tree[tree[x].lc].sz * tree[tree[y].rc].sz;
    cnt2 += (LL)tree[tree[x].rc].sz * tree[tree[y].lc].sz;
    tree[x].lc = merge(tree[x].lc,tree[y].lc);
    tree[x].rc = merge(tree[x].rc,tree[y].rc);
    update(x);
    return x;
}

void dfs(int u)
{
    if(!u) return ;
    dfs(L[u]); dfs(R[u]);
    if(!val[u])
    {
        cnt1 = 0,cnt2 = 0;
        root[u] = merge(root[L[u]],root[R[u]]);
        ans += min(cnt1,cnt2);
    }
}

int main()
{
    n = read();
    int rt = 0;
    read_tree(rt);
    for(int i = 1;i <= totp;i ++)
        if(val[i]) insert(root[i],1,n,val[i]);
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
