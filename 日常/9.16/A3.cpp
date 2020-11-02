#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<bitset>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 3010;
const int INF = 1000000010;
const LL mod = 19260817;

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

LL m19[70],m26[70];

struct matrix
{
    ULL r[65];
    matrix()
    {
        for(int i = 0;i < 64;i ++)
            r[i] = (1llu << i);
    }
    void print()
    {
        for(int i = 0;i < 64;i ++,puts(""))
            for(int j = 0;j < 64;j ++)
                cout << ((r[i] >> j) & 1);
    }
}g[SZ],up[SZ],down[SZ];

matrix operator *(const matrix &a,const matrix &b)
{
    matrix ans;
    for(int i = 0;i < 64;i ++) ans.r[i] = 0;
    for(int i = 0;i < 64;i ++)
        for(int j = 0;j < 64;j ++)
            if(a.r[i] >> j & 1)
                ans.r[i] ^= b.r[j];
    return ans;
}

LL get(const matrix &a)
{
    LL ans = 0;
    for(int i = 0;i < 64;i ++)
        for(int j = 0;j < 64;j ++)
            ans = (ans + ((a.r[i] >> j) & 1) * m19[i + 1] * m26[j + 1] % mod) % mod;
    return ans;
}

int n,m,head[SZ],nxt[SZ * 2],tot = 1;

struct edge
{
    int t;
}l[SZ * 2];

void build(int f,int t)
{
    l[++ tot] = (edge){t};
    nxt[tot] = head[f];
    head[f] = tot;
}

matrix U[SZ][15],D[SZ][15];
int anc[SZ][15],deep[SZ];
void dfs_lca(int u,int fa)
{
    deep[u] = deep[fa] + 1;
    anc[u][0] = fa;
    D[u][0] = U[u][0] = g[u];
    for(int i = 1;anc[u][i - 1];i ++)
    {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
        U[u][i] = U[u][i - 1] * U[anc[u][i - 1]][i - 1];
        D[u][i] = D[anc[u][i - 1]][i - 1] * D[u][i - 1];
    }
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa) continue;
        dfs_lca(v,u);
    }
}

int ask_lca(int u,int v)
{
    if(deep[u] < deep[v]) swap(u,v);
    if(deep[u] > deep[v])
    {
        int dd = deep[u] - deep[v];
        for(int i = 0;i <= 12;i ++)
            if(dd & (1 << i))
                u = anc[u][i];
    }
    if(u == v) return u;
    for(int i = 12;i >= 0;i --)
        if(anc[u][i] != anc[v][i])
            u = anc[u][i],v = anc[v][i];
    return anc[u][0];
}

matrix S[100];
matrix get_ans(int u,int v)
{
    matrix ans;
    if(deep[u] > deep[v])
    {
        int dd = deep[u] - deep[v];
        for(int i = 0;i <= 12;i ++)
            if(dd & (1 << i))
                ans = ans * U[u][i],u = anc[u][i];
    }
    else
    {
        int top = 0,dd = deep[v] - deep[u];
        for(int i = 0;i <= 12;i ++)
            if(dd & (1 << i))
                S[++ top] = D[v][i],v = anc[v][i];
        for(int i = top;i >= 1;i --) ans = ans * S[i];
    }
    return ans;
}

matrix ask_ans(int x,int y)
{
    int lca = ask_lca(x,y);
    return get_ans(x,lca) * g[lca] * get_ans(lca,y);
}


int main()
{
    m19[0] = m26[0] = 1;
    for(int i = 1;i <= 64;i ++)
        m19[i] = m19[i - 1] * 19 % mod,
        m26[i] = m26[i - 1] * 26 % mod;
    while(~scanf("%d%d",&n,&m))
    {
        tot = 1;
        memset(head,0,sizeof(head));
        memset(anc,0,sizeof(anc));
        for(int i = 1;i <= n - 1;i ++)
        {
            int u = read(),v = read();
            build(u,v); build(v,u);
        }
        ULL seed;
        scanf("%llu",&seed);
        for(int i = 1;i <= n;i ++)
            for(int j = 0;j < 64;j ++)
                g[i].r[j] = 0;

        for(int i = 1;i <= n;i ++)
            for(int p = 1;p <= 64;p ++)
            {
                seed ^= seed * seed + 15;
                for(int q = 1;q <= 64;q ++)
                {
                    ULL x = (seed >> (q - 1)) & 1;
                    g[i].r[p - 1] |= x << (q - 1);
                }
            }
        dfs_lca(1,0);
        while(m --)
        {
            int u = read(),v = read();
            printf("%lld\n",get(ask_ans(u,v)));
        }
    }
    return 0;
}
