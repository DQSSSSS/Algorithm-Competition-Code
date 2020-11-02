#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int INF = 1000000010;
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

int head[SZ],nxt[6000010],tot = 1;

struct edge
{
    int t,d;
}l[6000010];

void build(int f,int t,int d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

int dist[SZ];
queue<int> q;
bool use[SZ];
void spfa(int s)
{
    memset(dist,63,sizeof(dist));
    dist[s] = 0;
    q.push(s);
    use[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(dist[v] > dist[u] + l[i].d)
            {
                dist[v] = dist[u] + l[i].d;
                if(!use[v]) use[v] = 1,q.push(v);
            }
        }
    }
}

int n;
int num[20],vis[20],fac[20];

LL get_id()
{
    int ans = 0;
//    for(int i = 1;i <= n;i ++) cout << num[i] << " "; puts("");
    for(int i = 1;i <= n;i ++)
    {
        int t = 0;
        for(int j = i + 1;j <= n;j ++)
            if(num[j] < num[i]) t ++;
        ans += t * fac[n - i];
    }
//    printf("%d\n",ans);
    return ans;
}


void dfs(int d)
{
    if(d == n + 1)
    {
        int u = get_id();
        for(int i = 2;i <= n;i ++)
        {
            swap(num[i],num[1]);
            int v = get_id();
            swap(num[i],num[1]);
            build(u,v,1);
            build(v,u,1);
        }
        return ;
    }
    for(int i = 1;i <= n;i ++)
        if(!vis[i])
        {
            vis[i] = 1;
            num[d] = i;
            dfs(d + 1);
            vis[i] = 0;
        }
}

bool check(int x)
{
    for(int i = 2;i <= sqrt(x);i ++)
        if(x % i == 0) return false;
    return true;
}

int main()
{
    fac[0] = 1;
    for(int i = 1;i <= 9;i ++) fac[i] = fac[i - 1] * i;
    n = read();
    dfs(1);
    for(int cc = 1;cc <= 5;cc ++)
    {
        char ss[20],ee[20];
        scanf("%s%s",ss,ee);
        int s,e;
        for(int i = 0;i < n;i ++) num[i + 1] = ss[i] - '0'; s = get_id();
        for(int i = 0;i < n;i ++) num[i + 1] = ee[i] - '0'; e = get_id();
    //    cout << s << " " << e << endl;
        spfa(s);
        printf("%d\n",dist[e]);
    }
    return 0;
}
/*
9
123456789 213456789
123456789 213456789
123456789 213456789
123456789 213456789
123456789 213456789
*/
