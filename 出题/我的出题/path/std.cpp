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
    scanf("%lld",&n);
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

LL spfa(int s)
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
	return dist[n + 1];
}

int s[SZ];

int main()
{
	int T = read();
	while(T --)
	{
        n = read(),m = read();
        for(int i = 0;i <= n + 1;i ++) g[i].clear();
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
        for(int d = 0;d <= 20;d ++)
		{
			for(int i = 1;i <= k;i ++)
				if(s[i] >> d & 1) g[0].push_back((edge){s[i],0});
				else g[s[i]].push_back((edge){n + 1,0});
            ans = min(ans,spfa(0));
            g[0].clear();
            for(int i = 1;i <= k;i ++)
				if(!(s[i] >> d & 1))
					g[s[i]].erase(g[s[i]].begin() + g[s[i]].size() - 1);
		}
        printf("%lld\n",ans);
	}
	return 0;
}
