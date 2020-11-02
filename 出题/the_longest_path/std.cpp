#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const LL INF = 1e9 + 10;
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

int n,len;
int head[SZ],nxt[SZ],to[SZ],tot = 1;

void build(int f,int t)
{
	to[++ tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}


int lsh[SZ],a[SZ];
vector<int> pri[SZ],id[SZ];

int f1[SZ],f2[SZ],use[SZ],now_p;

void dfs(int u,int fa,int tag)
{
	f1[u] = f2[u] = 1;
	int max1 = 0,max2 = 0;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(a[v] % now_p == 0 && v != fa && use[v] != tag)
		{
			use[v] = tag;
			dfs(v,u,tag);
			f1[u] = max(f1[u],f1[v]);
			f2[u] = max(f2[u],f2[v] + 1);
			if(f2[v] > max1) max2 = max1,max1 = f2[v];
			else if(f2[v] > max2) max2 = f2[v];
		}
	}
	f1[u] = max(f1[u],max1 + max2 + 1);
}

int pp[SZ],l;
bool vis[SZ];

void shai()
{
	int n = 1e5;
	l = 0;
	for(int i = 2;i <= n;i ++)
	{
		if(!vis[i]) pp[++ l] = i;
		for(int j = 1,m;j <= l && (m = i * pp[j]) <= n;j ++)
		{
			vis[m] = 1;
			if(i % pp[j] == 0) break;
		}
	}
}

int main()
{
    freopen("gtree.in","r",stdin);
    freopen("gtree.out","w",stdout);
	shai();
	while(~scanf("%d",&n))
	{
		for(int i = 1;i <= n;i ++) head[i] = 0,use[i] = 0,pri[i].clear();
		tot = 1;
		lsh[0] = 0;
		for(int i = 1;i <= len;i ++) id[i].clear();
		len = 0;

		for(int i = 1;i < n;i ++)
		{
			int u = read(),v = read();
			build(u,v); build(v,u);
		}
		for(int i = 1;i <= n;i ++)
		{
			int x = read();
			a[i] = x;
			for(int j = 1,k;j <= l && pp[j] * pp[j] <= x;j ++)
				if(x % (k = pp[j]) == 0)
				{
					pri[i].push_back(k);
					while(x % k == 0) x /= k;
					lsh[++ lsh[0]] = k;
				}
			if(x != 1)
			{
				pri[i].push_back(x);
				lsh[++ lsh[0]] = x;
			}
		}
		sort(lsh + 1,lsh + 1 + lsh[0]);
		len = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
		for(int i = 1;i <= n;i ++)
			for(int j = 0;j < pri[i].size();j ++)
			{
				int x = lower_bound(lsh + 1,lsh + 1 + len,pri[i][j]) - lsh;
				id[x].push_back(i);
			}
		int ans = 0;
		for(int i = 1;i <= len;i ++)
		{
			now_p = lsh[i];
			for(int j = 0;j < id[i].size();j ++)
			{
				int u = id[i][j];
				if(use[u] != i) use[u] = i,dfs(u,0,i),ans = max(ans,f1[u]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
