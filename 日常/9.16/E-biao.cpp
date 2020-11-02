#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 200010;
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
int head[SZ],nxt[SZ * 8],tot = 1;

struct edge
{
    int t;
    LL d;
}l[SZ * 8];

void build(int f,int t,LL d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d)
{
    build(f,t,d); build(t,f,0);
}

int n,m,s,e;

int deep[SZ];
queue<int> q;

bool bfs()
{
    memset(deep,0,sizeof(deep));
    while(q.size()) q.pop();
    deep[s] = 1;
    q.push(s);
    while(q.size())
    {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(l[i].d && !deep[v])
            {
                deep[v] = deep[u] + 1;
                if(v == e) return true;
                q.push(v);
            }
        }
    }
    return false;
}


LL dfs(int u,LL flow)
{
    if(u == e || flow == 0) return flow;
    LL ans = flow;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(l[i].d && deep[v] == deep[u] + 1)
        {
            LL f = dfs(v,min(ans,l[i].d));
            if(f > 0)
            {
                l[i].d -= f;
                l[i ^ 1].d += f;
                ans -= f;
                if(ans == 0) break;
            }
            else deep[v] = 0;
        }
    }
    if(ans == flow) deep[u] = 0;
    return flow - ans;
}

LL dinic()
{
    LL ans = 0;
    while(bfs())
    {
        int tmp = dfs(s,INF);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

int main()
{
    int last = 0;
    for(n = 2;n <= 1000;n ++)
    {
        tot = 1; memset(head,0,sizeof(head));
        for(int i = 0;i <= n - 1;i ++)
            for(int j = i + 1;j <= n - 1;j ++)
                insert(i,j,i ^ j);
        s = 0; e = n - 1;
        int ans = dinic();
        printf("%d %d\n",n,ans - last);
        last = ans;
    }
    return 0;
}
//17 17 65 17 257 17 65 17 257 17 65 17 1025 17 65 17 257 17 65 17
//4  4  6  4  
