#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e7 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n;

struct edge
{
    int t,d;
}l[SZ];

int head[SZ],nxt[SZ],tot = 1;

void build(int f,int t)
{
    l[++ tot] = (edge){t,0};
    nxt[tot] = head[f];
    head[f] = tot;
}

LL val[SZ];
int cnt = 0,vis[SZ];

void dfs_vis(int u,int c)
{
    vis[u] = c;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(vis[v]) continue;
        dfs_vis(v,c);
    }
}

int s,t;
bool ins[SZ];

bool find_ring(int u,int fa)
{
    ins[u] = 1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(i == fa || (i ^ 1) == fa) continue;
        if(ins[v]) { s = u,t = v; l[i].d = l[i ^ 1].d = -1; return true; }
        if(find_ring(v,i)) return true;
    }
    ins[u] = 0;
    return false;
}

LL f[SZ][2];

void dfs_mem(int u,int fa)
{
    f[u][0] = f[u][1] = -1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa || l[i].d == -1) continue;
        dfs_mem(v,u);
    }
}

void dfs(int u,int fa)
{
    f[u][1] = val[u]; f[u][0] = 0;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa || l[i].d == -1) continue;
        dfs(v,u);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0],f[v][1]);
    }
}

LL work(int u)
{
    dfs_vis(u,++ cnt);
    s = t = 0;
    find_ring(u,0);
    //cout << s << " " << t << endl;
    LL ans = 0;
    dfs_mem(s,0); dfs(s,0); ans = max(ans,f[s][0]);
    dfs_mem(t,0); dfs(t,0); ans = max(ans,f[t][0]);
    return ans;
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
    {
        LL x = read(),v = read();
        build(i,v); build(v,i);
        val[i] = x;
    }
    LL ans = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(vis[i]) continue;
        LL tmp = work(i);
        //cout << tmp << endl;
        ans += tmp;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
5
10 2
20 3
30 1
10 5
20 4

*/
