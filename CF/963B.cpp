#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 400010;
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

int head[SZ],nxt[SZ],tot = 1,to[SZ];

void build(int f,int t)
{
	to[++ tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}

int a[SZ],d[SZ];
bool vis[SZ];

void del(int u,int f)
{
	vis[u] = 1;
	a[++ a[0]] = u;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v]) continue;
		d[v] --;
		if(d[v] % 2 == 0 && v != f) del(v,u);
	}
}

void dfs(int u,int f)
{
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == f) continue;
		dfs(v,u);
	}
	if(d[u] % 2 == 0) del(u,f);
}

int main()
{
	int n = read();
	if(n % 2)
	{
		puts("YES");
		int root = 1;
		for(int i = 1;i <= n;i ++)
		{
			int x = read();
			if(x == 0) root = i;
			else build(i,x),build(x,i),d[x] ++,d[i] ++;
		}
		dfs(root,0);
		for(int i = 1;i <= n;i ++)
			printf("%d\n",a[i]);
	}
	else puts("NO");
	return 0;
}

