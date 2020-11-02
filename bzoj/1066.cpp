#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const LL INF = 1e18;
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

int n,m,d,head[SZ],nxt[SZ],tot = 1,s,e;

struct edge
{
    int t;
    LL d;
}l[SZ];

void build(int f,int t,LL d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d) { build(f,t,d); build(t,f,0); }

int deep[SZ];
queue<int> q;

bool bfs()
{
    while(q.size()) q.pop();
    for(int i = 1;i <= n * m * 2 + 2;i ++) deep[i] = 0;
    deep[s] = 1; q.push(s);
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

LL dfs(int u,LL flow)
{
    if(flow == 0 || u == e) return flow;
    LL rst = flow;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(l[i].d && deep[v] == deep[u] + 1)
        {
            LL f = dfs(v,min(rst,l[i].d));
            if(f > 0)
            {
                l[i].d -= f;
                l[i ^ 1].d += f;
                rst -= f;
                if(rst == 0) break;
            }
            else deep[v] = 0;
        }
    }
    if(flow - rst == 0) deep[u] = 0;
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

int getnode(int x,int y,int d)
{
    return (x - 1) * m + y + d * n * m;
}

int D[50][50];

void build_edge(int x,int y)
{
    if(x <= d || n - x + 1 <= d || y <= d || m - y + 1 <= d)
        insert(getnode(x,y,1),e,INF);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(D[i][j] && sqrt(abs(i - x) * abs(i - x) + abs(j - y) * abs(j - y)) <= d)
                insert(getnode(x,y,1),getnode(i,j,0),INF);
}

char maps[50][50];

int main()
{
    n = read(),m = read(),d = read();
    for(int i = 1;i <= n;i ++)
        scanf("%s",maps[i] + 1);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            D[i][j] = maps[i][j] - '0';
            if(D[i][j])
                insert(getnode(i,j,0),getnode(i,j,1),D[i][j]);
        }
    s = n * m * 2 + 1,e = s + 1;
    for(int i = 1;i <= n;i ++)
        scanf("%s",maps[i] + 1);
    int sum = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(maps[i][j] == 'L')
                insert(s,getnode(i,j,0),1),sum ++;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(D[i][j])
                build_edge(i,j);
    printf("%lld\n",sum - dinic());
    return 0;
}
