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

int anc[SZ][22],deep[SZ],n,m;
vector<int> g[SZ];

void dfs(int u,int fa)
{
    deep[u] = deep[fa] + 1;
    anc[u][0] = fa;
    for(int i = 1;anc[u][i - 1];i ++)
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v,u);
    }
}

int ask_lca(int x,int y)
{
    if(deep[x] < deep[y]) swap(x,y);
    if(deep[x] > deep[y])
    {
        int dd = deep[x] - deep[y];
        for(int i = 0;i <= 20;i ++)
            if(dd & (1 << i))
                x = anc[x][i];
    }
    if(x == y) return x;
    for(int i = 20;i >= 0;i --)
        if(anc[x][i] != anc[y][i])
            x = anc[x][i],y = anc[y][i];
    return anc[x][0];
}

int ask(int x,int y)
{
    int z = ask_lca(x,y);
    return deep[x] + deep[y] - 2 * deep[z];
}

int main()
{
    n = read(),m = read();
    for(int i = 1;i < n;i ++)
    {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i = 1;i <= m;i ++)
    {
        int x = read(),y = read(),z = read();
        int xy = ask_lca(x,y); LL d1 = ask(x,xy) + ask(y,xy) + ask(z,xy);
        int yz = ask_lca(y,z); LL d2 = ask(x,yz) + ask(y,yz) + ask(z,yz);
        int xz = ask_lca(x,z); LL d3 = ask(x,xz) + ask(y,xz) + ask(z,xz);
        int ans1 = -1,ans2 = INF;
        if(ans2 > d1) ans2 = d1,ans1 = xy;
        if(ans2 > d2) ans2 = d2,ans1 = yz;
        if(ans2 > d3) ans2 = d3,ans1 = xz;
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
