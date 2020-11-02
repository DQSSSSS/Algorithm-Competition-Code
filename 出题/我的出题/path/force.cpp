#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 500010;
const LL INF = 2e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

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

int n,m;

struct edge
{
	int t;
	LL d;
}l[SZ];

vector<edge> g[SZ];
LL dist[SZ];
bool use[SZ];

queue<int> q;

LL spfa(int s,int e)
{
	for(int i = 0;i <= n + 1;i ++) dist[i] = INF;
	dist[s] = 0;
    q.push(s);
    use[s] = 1;
    while(q.size())
	{
        int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = 0;i < g[u].size();i ++)
		{
			int v = g[u][i].t;
            if(dist[v] > dist[u] + g[u][i].d)
			{
				dist[v] = dist[u] + g[u][i].d;
                if(!use[v]) use[v] = 1,q.push(v);
			}
		}
	}
	return dist[e];
}

int s[SZ];

int main()
{
	freopen("haha.in","r",stdin);
	freopen("force.out","w",stdout);
	int T = read();
	while(T --)
	{
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= m;i ++)
        {
            int u = read(),v = read();
            LL w = read();
            g[u].push_back((edge){v,w});
            g[v].push_back((edge){u,w});
        }
        int k = read();
        for(int i = 1;i <= k;i ++) s[i] = read();
        LL ans = INF;
        for(int i = 1;i <= k;i ++)
			for(int j = i + 1;j <= k;j ++)
				ans = min(ans,spfa(s[i],s[j]));
        printf("%lld\n",ans);
	}
	return 0;
}
