#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
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
	LL d,b;
};

vector<edge> g[SZ];

struct Heap
{
	int u;LL d;
};

bool operator <(Heap a,Heap b) { return a.d > b.d; }

priority_queue<Heap> q;

LL dist[SZ];
bool vis[SZ];

void dij(int s)
{
	for(int i = 1;i <= n;i ++) dist[i] = INF,vis[i] = 0;
	dist[s] = 1;
    q.push((Heap){s,1});
	while(q.size())
	{
		int u = q.top().u; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0;i < g[u].size();i ++)
		{
			int v = g[u][i].t;
			if(1 + (1.0 * g[u][i].d / dist[u]) >= g[u][i].b && dist[v] > dist[u] + g[u][i].d)
			{
				dist[v] = dist[u] + g[u][i].d;
                q.push((Heap){v,dist[v]});
			}
		}
	}
}

int get(LL n)
{
    int t = 0;
    LL ans = 1;
    while(ans * 2 <= n) ans *= 2,t ++;
	return t;
}

int main()
{
    int T = read();
    while(T --)
	{
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= m;i ++)
		{
            LL u = read(),v = read(),a = read(),b = read();
            g[u].push_back((edge){v,a,1ll << b});
		}
        dij(1);
        if(dist[n] == INF) puts("-1");
        else printf("%d\n",get(dist[n]));
	}
	return 0;
}
