#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 500010;
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

int rk[SZ],sz[SZ],fa[SZ],n,m;

int find(int x)
{
	return x == fa[x] ? x : find(fa[x]);
}

bool can[SZ];
LL sum[SZ],ans[SZ];

struct edge
{
	int f,t,d;
}l[SZ];
int tot = 0;

void Union(int x,int y,LL d)
{
	x = find(x),y = find(y);
	l[++ tot] = (edge){x,y,d};
	can[tot] = can[tot - 1]; sum[tot] = sum[tot - 1];
	if(x == y) { ans[d] = ans[d - 1];  return ; }
	if(rk[x] > rk[y]) swap(x,y);
	if(rk[x] == rk[y]) rk[y] ++;
	fa[x] = y;
	sz[y] += sz[x];
	sum[tot] += d;
	can[tot] = sz[y] == n ? 1 : 0;
	ans[d] = can[tot] ? sum[tot] : 0;
}

void del(int tot)
{
	int x = l[tot].f,y = l[tot].t;
	if(x == y) return ;
	if(rk[x] > rk[y]) swap(x,y);
	sz[y] -= sz[x];
	fa[x] = x; fa[y] = y;
	return ;
}

struct Ask
{
	char s[10];
	int x,y;
}ask[SZ];

int main()
{
	n = read(),m = read();
	for(int i = 1;i <= n;i ++) fa[i] = i,rk[i] = 0,sz[i] = 1;
	for(int i = 1;i <= m;i ++)
	{
		scanf("%s",ask[i].s);
		if(ask[i].s[0] == 'A') ask[i].x = read(),ask[i].y = read();
		else if(ask[i].s[0] == 'D') ask[i].x = read();
	}
	for(int i = 1;i <= m;i ++)
	{
		if(ask[i].s[0] == 'R') continue;
		if(ask[i].s[0] == 'A')
		{
			Union(ask[i].x,ask[i].y,i);
			if(i < m && ask[i + 1].s[0] == 'R')
				del(tot),tot --,ans[i + 1] = can[tot] ? sum[tot] : 0;
		}
		else
		{
			int k = ask[i].x;
			ans[i] = can[tot - k] ? sum[tot - k] : 0;
			if(i < m && ask[i + 1].s[0] == 'R')
				ans[i + 1] = ans[i - 1];
			else
			{	
				for(int j = tot;j >= tot - k + 1;j --)
					del(j);	
				tot -= k;
			}
		}
	}
	for(int i = 1;i <= m;i ++) printf("%lld\n",ans[i]);
	return 0;
}
