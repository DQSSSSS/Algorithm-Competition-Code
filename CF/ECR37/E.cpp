#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') { n = n *10 +a - '0'; a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,m;

int head[SZ],nxt[SZ],tot = 1,to[SZ];

void build(int f,int t)
{
	to[++ tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}

int nx[SZ],pr[SZ];

void del(int x)
{
	nx[pr[x]] = nx[x];
	pr[nx[x]] = pr[x];
}

int vis[SZ],sum = 0,d = 1;
queue<int> q;

void bfs(int u)
{
	del(u);
	q.push(u);
	sum = 0;
	while(q.size())
	{
		int u = q.front(); q.pop();
		d ++; sum ++;
		for(int i = head[u];i;i = nxt[i]) vis[to[i]] = d;
		for(int v = nx[0];v;v = nx[v])
		{
			if(vis[v] == d) continue;
			q.push(v);
			del(v);
		}
	}
}
int ans[SZ],t = 0;

int main()
{
	n = read(),m = read();
	for(int i = 1;i <= m;i ++)
	{
		int x = read(),y = read();
		build(x,y); build(y,x);
	}
	
	for(int i = 0;i <= n;i ++) nx[i] = (i + 1) % (n + 1);
	for(int i = 0;i <= n;i ++) pr[nx[i]] = i;
	
	while(nx[0]) bfs(nx[0]),ans[++ t] = sum;
	sort(ans + 1,ans + 1 + t);
	printf("%d\n",t);
	for(int i = 1;i <= t;i ++)
		printf("%d ",ans[i]);
	return 0;
}


