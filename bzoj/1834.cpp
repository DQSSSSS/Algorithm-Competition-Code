#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 20010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar();  }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int head[SZ],nxt[SZ],tot = 1,n,m,k;

struct edge
{
    int f,t;
    LL d,c;
}l[SZ];

void build(int f,int t,LL d,LL c)
{
    l[++ tot] = (edge){f,t,d,c};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d,LL c)
{
    build(f,t,d,c); build(t,f,0,-c);
}

bool use[SZ];
LL dist[SZ];
int pre[SZ];
deque<int> q;

bool spfa(int s,int t)
{
    for(int i = 1;i <= n + 1;i ++) dist[i] = INF,use[i] = 0,pre[i] = 0;
    while(q.size()) q.pop_front();
    q.push_front(s);
    dist[s] = 0;
    use[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop_front();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(l[i].d && dist[v] > dist[u] + l[i].c)
            {
                dist[v] = dist[u] + l[i].c;
                pre[v] = i;
                if(!use[v])
                {
                    use[v] = 1;
                    if(q.empty() || dist[q.front()] > dist[v]) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
    if(dist[t] != INF) return true;
    return false;
}


pii EK(int s,int t)
{
    LL flow = 0,cost = 0;
    while(spfa(s,t))
    {
        LL mf = INF;
        for(int i = pre[t];i;i = pre[l[i].f])
            mf = min(mf,l[i].d);
        flow += mf;
        for(int i = pre[t];i;i = pre[l[i].f])
            l[i].d -= mf,l[i ^ 1].d += mf,cost += mf * l[i].c;
    }
    return make_pair(flow,cost);
}

int ff[SZ],tt[SZ];
LL dd[SZ],cc[SZ];

void build_graph(bool flag)
{
    memset(head,0,sizeof(head)); tot = 1;
    for(int i = 1;i <= m;i ++)
    {
        insert(ff[i],tt[i],dd[i],0);
        if(flag) insert(ff[i],tt[i],INF,cc[i]);
    }
}


int main()
{
    n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++)
        ff[i] = read(),tt[i] = read(),dd[i] = read(),cc[i] = read();
    build_graph(0);
    LL ans1 = EK(1,n).first,ans2;

    build_graph(1); insert(n + 1,1,ans1 + k,0);
    ans2 = EK(n + 1,n).second;
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}
