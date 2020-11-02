#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 7000010;
const LL INF = 1e17 + 10;

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

int head[SZ],nxt[SZ],tot = 1;
int n,m;
LL mina;

struct edge
{
	int t;
	LL d;
}l[SZ];

void build(int f,int t,LL d)
{
	l[++ tot] = (edge){t,d};
	nxt[tot] = head[f];
	head[f] = tot;
}

struct Heap
{
	int u;
	LL d;
};

priority_queue<Heap> q;

bool operator <(Heap a,Heap b) { return a.d > b.d; } 

LL dist[SZ];
bool vis[SZ];

void dij(int s)
{
	for(int i = 0;i < mina;i ++) dist[i] = INF;
	dist[s] = 0;
	q.push((Heap){s,0});
	while(q.size())
	{
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = l[i].t;
			if(dist[v] > dist[u] + l[i].d)
			{
				dist[v] = dist[u] + l[i].d;
				q.push((Heap){v,dist[v]});
			}
		}
	}
}

LL work(LL x)
{
	LL ans = 0;
	for(int i = 0;i < mina;i ++)
	{
		if(x >= dist[i])
			ans += (x - dist[i]) / mina + 1;
	}
	return ans;
}

LL a[15];

int main()
{
	n = read();
	LL bl = read(),br = read();
	mina = INF;
	for(int i = 1;i <= n;i ++)
		a[i] = read(),mina = min(mina,a[i] == 0 ? INF : a[i]);
	for(int i = 0;i < mina;i ++)
		for(int j = 1;j <= n;j ++)
			build(i,(i + a[j]) % mina,a[j]);
	dij(0);
	printf("%lld",work(br) - work(bl - 1));
	return 0;
}

