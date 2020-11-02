#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int head[SZ],nxt[SZ],to[SZ],tot = 1,n,m;
int pr[SZ],nx[SZ];

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

void del(int x)
{
    nx[pr[x]] = nx[x];
    pr[nx[x]] = pr[x];
}

queue<int> q;
int dist[SZ],vis[SZ];
bool use[SZ];

void spfa(int s)
{
    for(int i = 1;i <= n;i ++) dist[i] = INF,use[i] = 0,vis[i] = 0;
    dist[s] = 0;
    use[s] = 1;
    q.push(s); del(s);
    int cnt = 0;
    while(q.size())
    {
        int u = q.front(); q.pop();
        cnt ++;
        for(int i = head[u];i;i = nxt[i]) vis[to[i]] = cnt;
        //for(int v = nx[0];v;v = nx[v]) cout << v << " "; puts("");
        for(int v = nx[0];v;v = nx[v])
        {
            if(vis[v] == cnt || use[v]) continue;
            //cout << v << endl;
            use[v] = 1;
            dist[v] = dist[u] + 1;
            del(v);
            q.push(v);
        }
    }
}

int main()
{
    int T = read();
    while(T --)
    {
        tot = 1; memset(head,0,sizeof(head));
        n = read(),m = read();
        for(int i = 1;i <= m;i ++)
        {
            int x = read(),y = read();
            build(x,y); build(y,x);
        }
        int s = read();
        for(int i = 0;i <= n;i ++) nx[i] = (i + 1) % (n + 1);
        for(int i = 0;i <= n;i ++) pr[nx[i]] = i;
        spfa(s);
        for(int i = 1,tot = 0;i <= n;i ++)
            if(i != s)
                printf("%d%c",dist[i] == INF ? -1 : dist[i],++ tot == n - 1 ? '\n' : ' ');
    }
    return 0;
}
/*
233
5
5 3 1 4 2
233

*/
