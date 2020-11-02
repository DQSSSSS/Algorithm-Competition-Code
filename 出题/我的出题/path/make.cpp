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
	freopen("haha.in","w",stdout);

	int T;
	freopen("haha0.in","r",stdin);
	T = read();
	cout << 28 << endl;
	while(T --)
	{
        n = read(),m = read();
        printf("%d %d\n",n,m);
        for(int i = 1;i <= m;i ++)
        {
            int u = read(),v = read();
            LL w = read();
            printf("%d %d %lld\n",u,v,w);
        }
        int k = read();
        printf("%d\n",k);
        for(int i = 1;i <= k;i ++) s[i] = read(),printf("%d ",s[i]);
        puts("");
	}

	freopen("haha1.in","r",stdin);
	T = read();
	while(T --)
	{
        n = read(),m = read();
        printf("%d %d\n",n,m);
        for(int i = 1;i <= m;i ++)
        {
            int u = read(),v = read();
            LL w = read();
            printf("%d %d %lld\n",u,v,w);
        }
        int k = read();
        printf("%d\n",k);
        for(int i = 1;i <= k;i ++) s[i] = read(),printf("%d ",s[i]);
        puts("");
	}

	freopen("haha2.in","r",stdin);
	T = read();
	while(T --)
	{
        n = read(),m = read();
        printf("%d %d\n",n,m);
        for(int i = 1;i <= m;i ++)
        {
            int u = read(),v = read();
            LL w = read();
            printf("%d %d %lld\n",u,v,w);
        }
        int k = read();
        printf("%d\n",k);
        for(int i = 1;i <= k;i ++) s[i] = read(),printf("%d ",s[i]);
        puts("");
	}

	freopen("haha3.in","r",stdin);
	T = read();
	while(T --)
	{
        n = read(),m = read();
        printf("%d %d\n",n,m);
        for(int i = 1;i <= m;i ++)
        {
            int u = read(),v = read();
            LL w = read();
            printf("%d %d %lld\n",u,v,w);
        }
        int k = read();
        printf("%d\n",k);
        for(int i = 1;i <= k;i ++) s[i] = read(),printf("%d ",s[i]);
        puts("");
	}

	freopen("haha4.in","r",stdin);
	T = read();
	while(T --)
	{
        n = read(),m = read();
        printf("%d %d\n",n,m);
        for(int i = 1;i <= m;i ++)
        {
            int u = read(),v = read();
            LL w = read();
            printf("%d %d %lld\n",u,v,w);
        }
        int k = read();
        printf("%d\n",k);
        for(int i = 1;i <= k;i ++) s[i] = read(),printf("%d ",s[i]);
        puts("");
	}

	freopen("haha5.in","r",stdin);
	T = read();
	while(T --)
	{
        n = read(),m = read();
        printf("%d %d\n",n,m);
        for(int i = 1;i <= m;i ++)
        {
            int u = read(),v = read();
            LL w = read();
            printf("%d %d %lld\n",u,v,w);
        }
        int k = read();
        printf("%d\n",k);
        for(int i = 1;i <= k;i ++) s[i] = read(),printf("%d ",s[i]);
        puts("");
	}
	return 0;
}
