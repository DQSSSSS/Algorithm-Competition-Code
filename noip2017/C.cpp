#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1e9 + 10;
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

int head[SZ],nxt[SZ << 1],tot = 1,n,m,p,k;

struct edge
{
    int t,d;
}l[SZ << 1];

void build(int f,int t,int d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

int D[SZ];
namespace pre
{
    struct node
    {
        int u,d;
    };

    bool operator <(node a,node b) { return a.d > b.d; }
    priority_queue<node> q;
    bool vis[SZ];

    void dij(int s,int dist[])
    {
        for(int i = 1;i <= n;i ++) vis[i] = 0,dist[i] = 2e9 + 10;
        dist[s] = 0;
        q.push((node){s,0});
        while(q.size())
        {
            int u = q.top().u; q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = head[u];i;i = nxt[i])
            {
                int v = l[i].t;
                if(dist[v] > dist[u] + l[i].d)
                {
                    dist[v] = dist[u] + l[i].d;
                    q.push((node){v,dist[v]});
                }
            }
        }
    }
}

struct node
{
    int u,t;
};

bool operator <(node a,node b) { return D[a.u] + a.t > D[b.u] + b.t; }

int cnt[SZ][55];
priority_queue<node> q;
bool vis[SZ][55];

void dij(int s)
{
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j <= k;j ++)
            vis[i][j] = 0,cnt[i][j] = 0;
    cnt[s][0] = 1;
    q.push((node){s,0});
    while(q.size())
    {
        int u = q.top().u,t = q.top().t; q.pop();
        if(vis[u][t]) continue;
        vis[u][t] = 1;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            int d = D[u] + t + l[i].d - D[v];
            if(d > k) continue;
            (cnt[v][d] += cnt[u][t]) %= p;
            q.push((node){v,d});
        }
    }
}

/*
bool dfs(int u,int t)
{
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        int d = D[u] + t + l[i].d - D[v];
        if(d > k) continue;
        if(!use[v][d])
        {
            use[v][d] = 1;
            if(dfs(v,d)) return true;
            use[v][d] = 0;
        }
        else return true;
    }
    return false;
}
bool find()
{
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j <= k;j ++)
            use[i][j] = 0;
    use[1][0] = 1;
    return dfs(1,0);
}
*/
void init()
{
    tot = 1;
    memset(head,0,sizeof(head));
}

int main()
{
    freopen("in.txt","r",stdin);
    int T = read();
    while(T --)
    {
        init();
        n = read(),m = read(),k = read(),p = read();
        for(int i = 1;i <= m;i ++)
        {
            int x = read(),y = read(),z = read();
            build(x,y,z);
        }
        pre :: dij(1,D);
        //if(find()) { puts("-1"); continue; }
        dij(1);
        int ans = 0;
        for(int i = 0;i <= k;i ++)
            (ans += cnt[n][i]) %= p;
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
4 10 2 2333
1 2 1
1 2 0
1 2 2
2 3 0
2 3 0
2 3 3
3 4 0
3 4 1
3 4 3
1 4 50
*/
