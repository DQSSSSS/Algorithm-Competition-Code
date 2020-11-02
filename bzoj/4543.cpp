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

vector<int> g[SZ];
int maxn,rt,n,m;
LL dist[SZ],ans = 0;
bool root[SZ];

int dfs_sz(int u,int fa)
{
    int ans = 1;
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == fa || root[v]) continue;
        ans += dfs_sz(v,u);
    }
    return ans;
}


int find_rt(int u,int fa,int n)
{
    int ans = 1,tmp = 0;
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == fa || root[v]) continue;
        int sz = find_rt(v,u,n);
        tmp = max(tmp,sz);
        ans += sz;
    }
    tmp = max(tmp,n - ans);
    if(tmp < maxn) maxn = tmp,rt = u;
    return ans;
}

void calc_ans(int u,int fa,int d)
{
    if(d != 0)
        ans += dist[d] * (dist[d] - 1) / 2;
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == fa || root[v]) continue;
        calc_ans(v,u,d + 1);
    }
}

void dfs_ans(int u,int fa,int d)
{
    dist[d] ++;
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == fa || root[v]) continue;
        dfs_ans(v,u,d + 1);
    }
}

void dfs(int x)
{
    int sz = dfs_sz(x,0);
    maxn = INF; rt = -1;
    find_rt(x,0,sz);
    int u = rt;

    root[u] = 1;
    for(int i = 1;i <= n;i ++) dist[i] = 0;
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(root[v]) continue;
        calc_ans(v,u,1);
        dfs_ans(v,u,1);
    }
    printf("%d\n",u);
    for(int i = 1;i <= n;i ++) printf("%lld ",dist[i]); puts("");

    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(root[v]) continue;
        dfs(v);
    }
}

int main()
{
    /*WA*/
    n = read();
    for(int i = 1;i < n;i ++)
    {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
