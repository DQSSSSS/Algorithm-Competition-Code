#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1000000010;

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

LL max(const LL &x,const LL &y) { return (x) > (y) ? (x) : (y); }
LL min(const LL &x,const LL &y) { return (x) < (y) ? (x) : (y); }

int head[SZ],nxt[SZ << 1],n,k,tot = 1;

struct edge{
    int t,d;
}l[SZ << 1];

void build(int f,int t,int d)
{
    l[++ tot].t = t;
    l[tot].d = d;
    nxt[tot] = head[f];
    head[f] = tot;
}

int ans,val[SZ],dp1[SZ],dp2[SZ];
//1 : max{val - d}
//2 : min{val + d}
void dfs(int u,int fa)
{
    int maxn = -INF,minn = INF;
    dp1[u] = val[u],dp2[u] = val[u];
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa) continue;
        dfs(v,u);
        dp1[u] = max(dp1[u],dp1[v] - l[i].d);
        dp2[u] = min(dp2[u],dp2[v] + l[i].d);
        ans = max(ans,dp1[v] - l[i].d - minn);
        ans = max(ans,maxn - dp2[v] - l[i].d);

        maxn = max(maxn,dp1[v] - l[i].d);
        minn = min(minn,dp2[v] + l[i].d);
    }
    ans = max(ans,val[u] - minn);
    ans = max(ans,maxn - val[u]);
}

void init()
{
    memset(head,0,sizeof(head));
    tot = 1;
    ans = -INF;
}

int main()
{
    int T = read();
    while(T --)
    {
        init();
        n = read();
        for(int i = 1;i <= n;i ++) val[i] = read();
        for(int i = 1;i <= n - 1;i ++)
        {
            int x = read(),y = read(),z = read();
            build(x,y,z); build(y,x,z);
        }
        dfs(1,0);
        //for(int i = 1;i <= n;i ++) cout << dp1[i] << " "; puts("");
        //for(int i = 1;i <= n;i ++) cout << dp2[i] << " "; puts("");
        printf("%d\n",ans);
    }
    return 0;
}
