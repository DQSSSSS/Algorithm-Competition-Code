#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const LL INF = 100000000000000010ll;
const LL mod = 1000000007;

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

int head[SZ],nxt[SZ * 2],tot = 1;

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

int fa[SZ],sz[SZ];

void dfs_pre(int u,int f)
{
    fa[u] = f;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == f) continue;
        dfs_pre(v,u);
    }
}

LL f[SZ][15][5]; //u j个k now
int ch[SZ][2],k,x,n,m;

void dfs_sz(int u)
{
    if(u == 0) return ;
    sz[u] = 1;
    dfs_sz(ch[u][0]); dfs_sz(ch[u][1]);
    sz[u] += sz[ch[u][0]] + sz[ch[u][1]];
}

LL dfs(int u,int d,int p)
{
    if(d > sz[u]) return 0;
    if(d == 0 && p == 1) return 0;
    if(u == 0) return d == 0 && p == 0 ? 1 : 0;
    if(f[u][d][p]) return f[u][d][p];

    if(ch[u][0] == 0 && ch[u][1] == 0) //  d == 1 && p != 1
        return 0;

    if(p == 0)
    {
        for(int i = 0;i <= d;i ++)
            (f[u][d][0] += dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,0) +
                           dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,1) +
                           dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,2) +
                           dfs(ch[u][0],i,1) * dfs(ch[u][1],d - i,0) +
                           dfs(ch[u][0],i,1) * dfs(ch[u][1],d - i,1) +
                           dfs(ch[u][0],i,1) * dfs(ch[u][1],d - i,2) +
                           dfs(ch[u][0],i,2) * dfs(ch[u][1],d - i,0) +
                           dfs(ch[u][0],i,2) * dfs(ch[u][1],d - i,1) +
                           dfs(ch[u][0],i,2) * dfs(ch[u][1],d - i,2)) %= mod;
    }
    if(p == 1)
    {
        for(int i = 0;i <= d;i ++)
            (f[u][d][1] += dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,0) +
                           dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,2) +
                           dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,1)) %= mod;
    }
    if(p == 2)
    {
        for(int i = 0;i <= d;i ++)
            (f[u][d][2] += dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,0) +
                           dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,1) +
                           dfs(ch[u][0],i,0) * dfs(ch[u][1],d - i,2) +
                           dfs(ch[u][0],i,2) * dfs(ch[u][1],d - i,0) +
                           dfs(ch[u][0],i,2) * dfs(ch[u][1],d - i,1) +
                           dfs(ch[u][0],i,2) * dfs(ch[u][1],d - i,2)) %= mod;
    }
    return f[u][d][p];
}

LL ksm(int a,int b)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n - 1;i ++)
    {
        int u = read(),v = read();
        build(u,v); build(v,u);
    }
    dfs_pre(1,0);
    for(int i = 2;i <= n;i ++)
    {
        int f = fa[i];
        if(ch[f][0])
            ch[i][1] = ch[f][0];
        ch[f][0] = i;
    }
    k = read(); x = read();
    for(int i = 1;i <= n;i ++) cout << i << " " << ch[i][0] << " " << ch[i][1] << endl;
    dfs_sz(1);
    for(int i = 1;i <= n;i ++)
    {
        f[i][0][0] = (LL)(k - 1) * ksm(m - 1,sz[i] - 1) % mod;
        f[i][0][2] = (LL)(m - k) * ksm(m - 1,sz[i] - 1) % mod;
        if(sz[i] == 1)
        {
            f[i][1][1] = 1;
        }
    }
    for(int i = 0;i <= x;i ++)
        dfs(1,i,0),dfs(1,i,1),dfs(1,i,2);
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j <= x;j ++)
            for(int y = 0;y <= 2;y ++)
                printf("f[%d][%d][%d] = %d\n",i,j,y,f[i][j][y]);
    LL ans = 0;
    for(int i = 0;i <= x;i ++)
        (ans += f[1][i][0] + f[1][i][1] + f[1][i][2]) %= mod;
    printf("%I64d",ans);
    return 0;
}
