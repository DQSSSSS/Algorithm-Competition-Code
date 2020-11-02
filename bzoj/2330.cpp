#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int head[SZ],nxt[SZ],tot = 1,n,m;

struct edge
{
    int t,d;
}l[SZ];

void build(int f,int t,int d)
{
    if(f == t && d) { puts("-1"); exit(0); }
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

LL dist[SZ];
bool use[SZ];
deque<int> q;

void spfa(int s)
{
    for(int i = 0;i <= n;i ++) dist[i] = 0,use[i] = 0;
    q.push_front(s);
    dist[s] = 1;
    use[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop_front();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(dist[v] < dist[u] + l[i].d)
            {
                dist[v] = dist[u] + l[i].d;
                if(!use[v])
                {
                    use[v] = 1;
                    if(q.empty() || dist[q.front()] < dist[v]) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
}

bool dfs(int u)
{
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(dist[v] < dist[u] + l[i].d)
        {
            dist[v] = dist[u] + l[i].d;
            if(!use[v])
            {
                use[v] = 1;
                if(dfs(v)) return true;
                use[v] = 0;
            }
            else return true;
        }
    }
    return false;
}


int main()
{
    n = read(),m = read();
    for(int i = 1;i <= m;i ++)
    {
        int opt = read(),a = read(),b = read();
        if(opt == 1) build(a,b,0),build(b,a,0);
        else if(opt == 2) build(a,b,1);//build(b,a,-1);
        else if(opt == 3) build(b,a,0);//build(a,b,0);
        else if(opt == 4) build(b,a,1);//build(a,b,1);
        else build(a,b,0);//build(b,a,0);
    }
    for(int i = n;i >= 1;i --)
        build(0,i,0);
    dist[0] = 1;
    if(dfs(0)) { puts("-1"); return 0; }
    spfa(0);
    LL ans = 0,minn = INF;
    for(int i = 1;i <= n;i ++) ans += dist[i],minn = min(minn,dist[i]);
    //for(int i = 1;i <= n;i ++) printf("%d ",dist[i]); puts("");
    printf("%lld\n",ans);
    return 0;
}
