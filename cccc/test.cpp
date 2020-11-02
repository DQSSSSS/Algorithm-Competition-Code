#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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

clock_t st,ed;

vector<int> g[233];

bool vis[SZ],ok = 0;
char mp[233][233];
int a[233],n,f[233][233];

void dfs(int u,int d)
{
	ed = clock();
	if((double)(ed - st)/ CLOCKS_PER_SEC > 1.9) { puts("No Solution"); exit(0); } 
	if(ok) return ;
	if(d == n + 1)
	{
		if(mp[a[n]][a[1]] == 'W')
		{
			ok = 1;
			for(int i = 1;i <= n;i ++)
				printf("%d%c",a[i],i == n ? '\n' : ' ');
		}
		return ;
	}
	if(vis[u]) return ;
	vis[u] = 1;
	for(int i = 0;i < g[u].size();i ++)
	{
		int v = g[u][i];
		a[d] = v;
		dfs(v,d + 1);
	}
	vis[u] = 0;
}

int main()
{
	st = clock();
	n = read();
	for(int i = 1;i <= n;i ++)
		scanf("%s",mp[i] + 1);
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
		{
			if(mp[i][j] == 'W')
				g[i].push_back(j);
		}
	a[1] = 1;
	dfs(1,2);
	if(!ok) puts("No Solution");
	return 0;
}

