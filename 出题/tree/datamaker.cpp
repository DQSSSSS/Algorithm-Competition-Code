#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;

namespace data{
		
	int randint()
	{
		return rand() << 16 | rand();
	}
	
	LL randLL()
	{
		return (LL)randint() << 32ll | (LL)randint();
	}
	
	const int mod = 100000;
	const int MOD = 1000000000;
	
	void work()
	{
		int n = randint() % mod + 1;
		printf("%d\n",n);
		for(int i = 2;i <= n;i ++)
		{
			int u = i,v = randint() % (i - 1) + 1,c = randint() % MOD;
			printf("%d %d %d\n",u,v,c);
		}
		int m = randint() % mod + 1;
		printf("%d\n",m);
		for(int i = 1;i <= m;i ++)
		{
			int a = randint() % n + 1;
			int b = randint() % n + 1;
			int c = randint() % n + 1;
			printf("%d %d %d\n",a,b,c);
		}	
	}
}


namespace work{
	
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
	
	void init()
	{
		memset(anc,0,sizeof(anc));
		memset(dist,0,sizeof(dist));
		memset(head,0,sizeof(head));
		tot = 1;
	}
	
	void work()
	{
		init();
		int n;
		scanf("%d",&n);
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
}

string hz(int n)
{
	string s;
	while(n) s += (char)(n % 10 + '0'),n /= 10;
	string ans;
	for(int i = s.length() - 1;i >= 0;i --)
		ans += s[i];
	return ans;
}

const string name = "tree";

int main()
{
	srand(time(0));
	for(int t = 8;t <= 9;t ++)
	{
		string s = name + hz(t);
		freopen((s + ".in").c_str(),"w",stdout);
		data :: work();
		fclose(stdout);
		freopen((s + ".in").c_str(),"r",stdin);
		freopen((s + ".out").c_str(),"w",stdout);
		work :: work();
		fclose(stdin);	fclose(stdout);
	}

	return 0;
}




