#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long LL;
const int SZ = 30010;
const LL INF = 1000000010ll;
const int mod = 1000000007;
LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') {n = n * 10 + a - '0'; a = getchar(); }
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
    while(~scanf("%d",&n))
    {
        tot = 1; memset(head,0,sizeof(head));
        n ++;
        for(int i = 1;i <= n - 1;i ++)
        {
            int x = read() + 1,y = read() + 1;
            insert(x + n,y,INF); insert(y + n,x,INF);
        }
        int m = read();
        s = 2 * n + 1,e = 2 * n + 2;
        for(int i = 1;i <= m;i ++)
        {
            int x = read() + 1,y = read() + 1;
            if(x > y) swap(x,y);
            insert(s,x,INF); insert(y + n,e,INF);
        }
        for(int i = 1;i <= n;i ++)
            insert(i,i + n,1);
        printf("%d\n",dinic());
    }
    return 0;
}
