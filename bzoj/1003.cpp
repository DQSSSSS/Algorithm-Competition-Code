#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 2010;
const LL INF = 1000000010;
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


int head[SZ],nxt[1000010],tot = 1,n,m,k,e;

struct edge
{
    int t;
    LL d;
}l[1000010];

void build(int f,int t,LL d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

LL dist[SZ];
queue<int> q;
bool use[SZ];
int can[SZ][SZ];
LL f[SZ],val[SZ][SZ];

LL spfa(int l,int r)
{
    for(int i = 1;i <= m;i ++) dist[i] = INF;
    dist[1] = 0;
    q.push(1);
    use[1] = 1;
    if(can[1][r] - can[1][l - 1]) return INF;
    while(q.size())
    {
        int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = ::l[i].t;
            if(dist[v] > dist[u] + ::l[i].d && can[v][r] - can[v][l - 1] == 0)
            {
                dist[v] = dist[u] + ::l[i].d;
                if(!use[v])
                    use[v] = 1,q.push(v);
            }
        }
    }
    return dist[m];
}


int main()
{
    n = read(),m = read(),k = read(),e = read();
    for(int i = 1;i <= e;i ++)
    {
        int u = read(),v = read(),d = read();
        build(u,v,d); build(v,u,d);
    }
    int q = read();
    while(q --)
    {
        int p = read(),l = read(),r = read();
        can[p][l] ++; can[p][r + 1] --;
    }
    for(int p = 1;p <= m;p ++)
        for(int i = 1;i <= n;i ++)
            can[p][i] += can[p][i - 1];
    for(int p = 1;p <= m;p ++)
        for(int i = 1;i <= n;i ++)
            can[p][i] += can[p][i - 1];
    for(int i = 1;i <= n;i ++)
        for(int j = i;j <= n;j ++)
            val[i][j] = spfa(i,j);
/*
    for(int i = 1;i <= m;i ++,puts(""))
        for(int j = 1;j <= n;j ++)
            printf("%d ",can[i][j]);

    for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= n;j ++)
            printf("%d ",val[i][j]);
*/
    for(int i = 1;i <= n;i ++) f[i] = INF;
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j < i;j ++)
            f[i] = min(f[i],f[j] + val[j + 1][i] * (i - j) + k);

/*    for(int i = 1;i <= n;i ++)
        printf("%d ",f[i]); puts("");
*/
    printf("%d\n",f[n] - k);
    return 0;
}
