#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;

int head[SZ],nxt[SZ],tot = 1;

struct edge{
	int t,d;
}l[SZ];

void build(int f,int t,int d)
{
	l[++ tot] = (edge) {t,d};
	nxt[tot] = head[f]; head[f] = tot;
}

int anc[SZ][30],dist[SZ][30],deep[SZ];

void dfs(int u,int fa)
{
	anc[u][0] = fa;
	deep[u] = deep[fa] + 1;
	for(int i = 1;anc[u][i - 1];i ++)
	{
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
		dist[u][i] = max(dist[u][i - 1],dist[anc[u][i - 1]][i - 1]);
	}
	for(int i = head[u];i;i = nxt[i])
	{
		int v = l[i].t;
		if(v == fa) continue;
		dist[v][0] = l[i].d;
		dfs(v,u);
	}
}

int ask_lca(int x,int y)
{
	if(deep[x] < deep[y]) swap(x,y);
	if(deep[x] > deep[y])
	{
		int dd = deep[x] - deep[y];
		for(int i = 20;i >= 0;i --)
			if(dd >> i & 1)
				x = anc[x][i];
	}
	if(x != y)
	{
		for(int i = 20;i >= 0;i --)
			if(anc[x][i] != anc[y][i])
				x = anc[x][i],y = anc[y][i];		
	}
	if(x == y) return x;
	return anc[x][0];
}


int ask_dist(int x,int y)
{
	int ans = 0;
	if(deep[x] < deep[y]) swap(x,y);
	if(deep[x] > deep[y])
	{
		int dd = deep[x] - deep[y];
		for(int i = 20;i >= 0;i --)
			if(dd >> i & 1)
				ans = max(ans,dist[x][i]),x = anc[x][i];
	}
	if(x != y)
	{
		for(int i = 20;i >= 0;i --)
			if(anc[x][i] != anc[y][i])
			{
				ans = max(ans,max(dist[x][i],dist[y][i]));
				x = anc[x][i],y = anc[y][i];		
			}
	}
	if(x == y) return ans;
	return max(ans,max(dist[x][0],dist[y][0]));
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	while(~scanf("%d",&n))
	{
		for(int i = 1;i <= n;i ++) head[i] = 0,anc[i][0] = dist[i][0] = 0;
		tot = 1;
		
		for(int i = 1;i < n;i ++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			build(a,b,c); build(b,a,c);
		}
		dfs(1,0);
		int m;
		scanf("%d",&m);	
		while(m --)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			int ab = ask_lca(a,b),ac = ask_lca(a,c),bc = ask_lca(b,c);
			if(ac == bc)
				printf("%d\n",ask_dist(ab,c));
			else if(ac == ab)
				printf("%d\n",ask_dist(bc,c));
			else
				printf("%d\n",ask_dist(ac,c));
		}
	}
	return 0;
}

/*
8
1 2 3
1 3 4
3 8 1
7 2 5
5 7 7
4 6 10
2 4 2
233
1 6 5

*/

