#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 4e5 + 10;

LL read()
{
	LL n = 0;
	scanf("%lld",&n);
	return n;
}

int head[SZ],nxt[SZ],to[SZ],tot = 1,n,m;

void build(int f,int t)
{
	to[++ tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}

int sccnum[SZ],scccnt = 0,low[SZ],dfn[SZ],dfs_clock = 0,sccsz[SZ];
stack<int> S;
void tarjan(int u)
{
	S.push(u);
	low[u] = dfn[u] = ++ dfs_clock;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(!sccnum[v])
			low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u])
	{
		scccnt ++;
		while(233)
		{
			int x = S.top(); S.pop();
			sccnum[x] = scccnt;
			sccsz[scccnt] ++;
			if(x == u) break;
		}
	}
}

int ff[SZ],tt[SZ];

int f[SZ];

void dfs(int u)
{
	f[u] += sccsz[u];
	int ans = 0;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(!f[v]) dfs(v);
		ans = max(ans,f[v]);
	}
	f[u] += ans;
}

int main()
{
	n = read(),m = read();
	for(int i = 1;i <= m;i ++)
	{
		int u = read(),v = read();
		build(u,v);
		ff[i] = u,tt[i] = v;
	}
	for(int i = 1;i <= n;i ++)
		if(!dfn[i])
			tarjan(i);
			
	memset(head,0,sizeof(head));
	tot = 1;
	
	for(int i = 1;i <= m;i ++)
		if(sccnum[ff[i]] != sccnum[tt[i]])
			build(sccnum[ff[i]],sccnum[tt[i]]);

	for(int i = 1;i <= n;i ++)
		if(!f[i])
			dfs(i);
	int ans = 0;
	for(int i = 1;i <= n;i ++) ans = max(ans,f[i]);
	//for(int i = 1;i <= n;i ++) cout << f[i] << " "; puts("");
	cout << ans << endl;
	return 0;
}



