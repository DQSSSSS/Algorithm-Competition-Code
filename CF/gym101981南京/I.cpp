#include<bits/stdc++.h>
using namespace std;

typedef int LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
const LD eps = 1e-8;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0')
    {
        if(a == '-')
            flag = 1;
        a = getchar();
    }
    while(a <= '9' && a >= '0')
    {
        n = n * 10 + a - '0',a = getchar();
    }
    if(flag)
        n = -n;
    return n;
}

struct edge
{
    int t;
    LL d;
} l[SZ];

int tot = 1,head[SZ],nxt[SZ],s,e;

void build(int f,int t,LL d)
{
    l[++ tot] = (edge)
    {
        t,d
    };
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d)
{
    build(f,t,d);
    build(t,f,0);
}

int deep[SZ];
queue<int> q;
bool bfs()
{
    for(int i = 1;i <= e;i ++) deep[i] = 0;
    while(q.size())
        q.pop();
    deep[s] = 1;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = nxt[i])
        {
            int v = l[i].t;
            if(l[i].d && !deep[v])
            {
                deep[v] = deep[u] + 1;
                if(v == e)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}
LL dfs(int u,LL flow)
{
    if(u == e || flow == 0)
        return flow;
    LL ans = flow;
    for(int i = head[u]; i; i = nxt[i])
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
                if(ans == 0)
                    break;
            }
            else deep[v] = 0;
        }
    }
    if(ans == flow)
        deep[u] = 0;
    return flow - ans;
}
LL dinic()
{
    LL ans = 0;
    while(bfs())
    {
        int tmp = dfs(s,INF);
        if(tmp == 0)
            break;
        ans += tmp;
    }
    return ans;
}

int main()
{
    int n = read(),m = read(),k = read();
    int ss = n + m + 1;
    s = n + m + 2;
    e = n + m + 3;
    for(int i = 1; i <= n; i ++)
    {
        int x = read();
        while(x --)
        {
            int y = read();
            insert(i,y+n,1);
        }
        insert(s,i,1);
        insert(ss,i,1);
    }
    insert(s,ss,k);
    for(int i = 1; i <= m; i ++)
    {
        insert(i+n,e,1);
    }
    int ans = dinic();
    cout << ans << endl;
    return 0;
}
