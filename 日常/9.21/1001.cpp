#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;
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

int n,m;

int get_id(int x,int y)
{
    return (x - 1) * m + y;
}

int head[SZ],nxt[SZ * 8],tot = 1,s,e;

struct haha
{
    int t;
    LL d;
}l[SZ * 8];

void build(int f,int t,LL d)
{
    l[++ tot] = (haha){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d)
{
    build(f,t,d); build(t,f,d);
}

int deep[SZ];
queue<int> q;

bool bfs()
{
    while(q.size()) q.pop();
    for(int i = 1;i <= n * m;i ++) deep[i] = 0;
    deep[s] = 1;
    q.push(s);
    while(q.size())
    {
        int u = q.front(); q.pop();
        if(u == e) return true;
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

LL dfs(int u,LL flow)
{
    if(flow == 0 || e == u) return flow;
    LL rst = flow;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(deep[v] == deep[u] + 1 && l[i].d)
        {
            LL f = dfs(v,min(rst,l[i].d));
            if(f > 0)
            {
                l[i].d -= f;
                l[i ^ 1].d += f;
                rst -= f;
                if(rst == 0) break;
            }
            else deep[v] = INF;
        }
    }
    if(flow == rst) deep[u] = INF;
    return flow - rst;
}

LL dinic()
{
    LL ans = 0;
    while(bfs())
    {
        LL tmp = dfs(s,INF);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

int main()
{
    n = read(),m = read();
    s = 1; e = n * m;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j < m;j ++)
        {
            int x = read();
            insert(get_id(i,j),get_id(i,j + 1),x);
        }
    for(int i = 1;i < n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            int x = read();
            insert(get_id(i,j),get_id(i + 1,j),x);
        }
    for(int i = 1;i < n;i ++)
        for(int j = 1;j < m;j ++)
        {
            int x = read();
            insert(get_id(i,j),get_id(i + 1,j + 1),x);
        }
    printf("%lld\n",dinic());
    return 0;
}
