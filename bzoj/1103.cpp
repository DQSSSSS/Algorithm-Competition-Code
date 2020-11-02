#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int sz[SZ],deep[SZ],n,m;
vector<int> g[SZ];
int dfn[SZ],dfs_clock = 0;

void dfs(int u,int fa)
{
    dfn[u] = ++ dfs_clock;
    deep[u] = deep[fa] + 1;
    sz[u] = 1;
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}

int bits[SZ];

void add(int x,int d)
{
    for(int i = x;i <= n;i += i & -i)
        bits[i] += d;
}

int ask(int x)
{
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += bits[i];
    return ans;
}

int main()
{
    n = read();
    for(int i = 1;i < n;i ++)
    {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    m = read();
    for(int i = 1;i <= m + n - 1;i ++)
    {
        char opt[3];
        scanf("%s",opt);
        int x,y;
        if(opt[0] == 'A')
        {
            x = read(),y = read();
            if(deep[x] < deep[y]) swap(x,y);
            add(dfn[x],-1); add(dfn[x] + sz[x],1);
        }
        else
            x = read(),printf("%d\n",ask(dfn[x]) + deep[x] - 1);
    }
    return 0;
}
