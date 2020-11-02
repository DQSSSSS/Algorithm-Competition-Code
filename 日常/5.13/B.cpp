#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

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

int n,m,fa[10010][510],Fa[510];

vector<int> g[10010];

int find(int *fa,int x)
{
	return x == fa[x] ? x : fa[x] = find(fa,fa[x]);
}

void Union(int *f,int x,int y)
{
	x = find(f,x); y = find(f,y);
	f[x] = y;
}

int ff[SZ],tt[SZ];

int dfs_tree(int u,int f)
{
	for(int i = 1;i <= n;i ++) fa[u][i] = fa[f][i];
	Union(fa[u],ff[u],tt[u]);
	//if(u == 1) find(1,1);
	//cout << u << endl;
	//for(int i = 1;i <= n;i ++) cout << find(u,i) << " "; puts("");
	
	for(int i = 0;i < g[u].size();i ++)
	{
		int v = g[u][i];
		dfs_tree(v,u);
	}
}

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
		n = read(),m = read();
		for(int i = 1;i <= m;i ++) g[i].clear();
		for(int i = 2;i <= m;i ++)
			g[read()].push_back(i);
		for(int i = 1;i <= n;i ++) fa[0][i] = i;
		for(int i = 1;i <= m;i ++)
		{
			int x = read(),y = read();
			ff[i] = x; tt[i] = y;
		}
		dfs_tree(1,0);
		int q = read();
		printf("Case #%d:\n",++ cc);
		for(int i = 1;i <= q;i ++)
		{
			int k = read();
			for(int j = 1;j <= n;j ++) Fa[j] = j;
			while(k --)
			{
				int x = read();
				for(int j = 1;j <= n;j ++)
				{
					Union(Fa,j,find(fa[x],j));
				}
				//for(int j = 1;j <= n;j ++) cout << find(j) << " "; puts("");
			}
			int ans = 0;
			for(int j = 1;j <= n;j ++) if(find(Fa,j) == j) ans ++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
