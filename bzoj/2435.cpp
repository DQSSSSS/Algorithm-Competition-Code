#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;

int head[SZ],nxt[SZ << 1],tot = 0;

struct edge
{
    int t;
    LL d;
}l[SZ << 1];

void build(int f,int t,LL d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

LL ans = 0;
int n,sz[SZ];

LL Abs(LL x) { return x < 0 ? -x : x; }

void dfs(int u,int fa)
{
    sz[u] = 1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa) continue;
        dfs(v,u);
        ans += (LL)l[i].d * Abs(n - 2 * sz[v]);
        sz[u] += sz[v];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i < n;i ++)
    {
        int x,y; LL z;
        scanf("%d%d%lld",&x,&y,&z);
        build(x,y,z); build(y,x,z);
    }
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}
