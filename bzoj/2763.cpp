#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,m,k;

int head[SZ],nxt[SZ],tot = 1;

struct edge
{
    int t,d;
}l[SZ];

void build(int f,int t,int d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

deque<int> q;
bool use[SZ];
int dist[SZ];

void spfa(int s)
{
    memset(dist,63,sizeof(dist));
    dist[s] = 0;
    q.push_front(s);
    use[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop_front();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(dist[v] > dist[u] + l[i].d)
            {
                dist[v] = dist[u] + l[i].d;
                if(!use[v])
                {
                    use[v] = 1;
                    if(q.empty() || dist[q.front()] > dist[v]) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
}

int get_id(int x,int d)
{
    return x + d * n;
}

int main()
{
    n = read(),m = read(),k = read();
    int s = read(),t = read();
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        for(int d = 0;d <= k;d ++)
            build(get_id(a,d),get_id(b,d),c),build(get_id(b,d),get_id(a,d),c);
        for(int d = 1;d <= k;d ++)
            build(get_id(a,d - 1),get_id(b,d),0),build(get_id(b,d - 1),get_id(a,d),0);
    }
    spfa(s);
    int ans = INF;
    for(int i = 0;i <= k;i ++)
        ans = min(ans,dist[get_id(t,i)]);
    printf("%d\n",ans);
    return 0;
}
