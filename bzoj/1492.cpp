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
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int head[SZ],nxt[SZ],to[SZ],tot = 1;

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

int n,m;
int dfn[SZ],low[SZ],dfs_clock = 0;
int scc_num[SZ],scc_cnt = 0;
int val[SZ],scc_val[SZ],c[SZ],scc_c[SZ];
stack<int> S;

void tarjan(int u)
{
    dfn[u] = low[u] = ++ dfs_clock;
    S.push(u);
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(!scc_num[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        scc_cnt ++;
        while(233)
        {
            int x = S.top(); S.pop();
            scc_num[x] = scc_cnt;
            scc_val[scc_cnt] += val[x];
            scc_c[scc_cnt] |= c[x];
            if(x == u) break;
        }
    }
}
int f[SZ],rd[SZ];
/*
bool vis[SZ];
queue<int> q;
void topsort(int s)
{
    for(int i = 1;i <= scc_cnt;i ++) f[i] = scc_val[i];
    q.push(scc_num[s]);
    while(q.size())
    {
        int u = q.front(); q.pop();
        vis[u] = 1;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = to[i];
            f[v] = max(f[v],f[u] + scc_val[v]);
            if(-- rd[v] == 0) q.push(v);
        }
    }
}
*/

queue<int> q;
int dist[SZ];
bool use[SZ];
void spfa(int s)
{
    memset(dist,-1,sizeof(dist));
    dist[s] = scc_val[s];
    use[s] = 1;
    q.push(s);
    while(q.size())
    {
        int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = to[i];
            if(dist[v] < dist[u] + scc_val[v])
            {
                dist[v] = dist[u] + scc_val[v];
                if(!use[v])
                    use[v] = 1,q.push(v);
            }
        }
    }
}

int ff[SZ],tt[SZ];

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= m;i ++)
    {
        ff[i] = read(),tt[i] = read();
        build(ff[i],tt[i]);
    }
    for(int i = 1;i <= n;i ++) val[i] = read();
    int s = read(),p = read();
    for(int i = 1;i <= p;i ++)
    {
        int x = read();
        c[x] = 1;
    }
    for(int i = 1;i <= n;i ++)
        if(!dfn[i])
            tarjan(i);
    memset(head,0,sizeof(head)); tot = 1;
    for(int i = 1;i <= m;i ++)
    {
        if(scc_num[ff[i]] != scc_num[tt[i]])
            build(scc_num[ff[i]],scc_num[tt[i]]),rd[scc_num[tt[i]]] ++;
    }
    /*topsort(s);
    int ans = 0;
    for(int i = 1;i <= scc_cnt;i ++)
        if(scc_c[i] && vis[i])
            ans = max(ans,f[i]);*/
    spfa(scc_num[s]);
    int ans = 0;
    for(int i = 1;i <= scc_cnt;i ++)
        if(scc_c[i])
            ans = max(ans,dist[i]);
    printf("%d\n",ans);
    return 0;
}
