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

int head[SZ],nxt[SZ],to[SZ],tot = 1;

void build(int f,int t)
{
	to[++ tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}

bool vis[SZ];
int a[SZ],n;

void dfs(int u,int fa,int &x)
{
	if(vis[u]) return ;
	vis[u] = 1;
	if(u <= n) x ++;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		dfs(v,u,x);
	}
}

int main()
{
	n = read();
	for(int i = 1;i <= n;i ++)
	{
		int k;
		scanf("%d:",&k);
		while(k --)
		{
			int x = read();
			build(i,x + n); build(x + n,i);
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(!vis[i])
		{
			ans ++;
			dfs(i,0,a[ans]);
		}
	}
	sort(a + 1,a + 1 + ans);
	printf("%d\n",ans);
	for(int i = ans;i >= 1;i --) printf("%d%c",a[i],i == 1 ? '\n' : ' ');
	return 0;
}






