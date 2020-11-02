#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
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

int head[SZ],nxt[SZ << 1],tot = 1;
int n,m,a[SZ];

struct edge
{
    int t;
    LL d;
}l[SZ << 1];

void build(int f,int t,int d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,int d)
{
    build(f,t,d); build(t,f,0);
}

int deep[SZ];
queue<int> q;

bool bfs(int s,int e)
{
    while(q.size()) q.pop();
    for(int i = 1;i <= n + m + 2;i ++) deep[i] = 0;
    q.push(s);
    deep[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(l[i].d && !deep[v])
            {
                deep[v] = deep[u] + 1,q.push(v);
                if(v == e) return true;
            }
        }
    }
    return false;
}

LL dfs(int u,int t,LL flow)
{
    if(u == t || flow == 0) return flow;
    LL rst = flow;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(l[i].d && deep[v] == deep[u] + 1)
        {
            LL f = dfs(v,t,min(rst,l[i].d));
            if(f > 0)
            {
                rst -= f;
                l[i].d -= f;
                l[i ^ 1].d += f;
                if(rst == 0) break;
            }
            else deep[v] = 0;
        }
    }
    if(flow - rst == 0) deep[u] = 0;
    return flow - rst;
}

LL dinic(int s,int e)
{
    LL ans = 0;
    while(bfs(s,e))
    {
        LL tmp = dfs(s,e,INF);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

int main()
{
    n = read(),m = read();
    int s = n + m + 1,t = n + m + 2;
    LL sum = 0;
    for(int i = 1;i <= n;i ++) a[i] = read(),insert(i,t,a[i]);
    for(int i = 1;i <= m;i ++)
    {
        int x = read(),y = read(),z = read();
        insert(n + i,x,INF);
        insert(n + i,y,INF);
        insert(s,n + i,z);
        sum += z;
    }
    printf("%lld",sum - dinic(s,t));
    return 0;
}
