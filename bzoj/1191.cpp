#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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

int head[SZ],nxt[SZ],to[SZ],tot = 1,match[SZ];
bool vis[SZ];

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

bool dfs(int u)
{
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(!vis[v])
        {
            vis[v] = 1;
            if(!match[v] || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++)
    {
        int x = read() + 1,y = read() + 1;
        build(i,x); build(i,y);
    }
    for(int i = 1;i <= n;i ++)
    {
        memset(vis,0,sizeof(vis));
        if(!dfs(i))
        {
            printf("%d\n",i - 1);
            return 0;
        }
    }
    printf("%d\n",n);
    return 0;
}
