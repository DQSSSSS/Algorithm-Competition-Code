#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

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

int head[SZ],nxt[SZ],tot = 1,to[SZ],use[SZ];

void build(int f,int t)
{
	to[++ tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}


int main()
{
	int n = read();
	for(int i = 2,u;i <= n;i ++)
		build(u = read(),i),use[u] = 1;
	int ans = 0,ans1 = 0;
	for(int u = 1;u <= n;u ++)
	{
		if(use[u]) ans1 ++;
		int t = 0;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = to[i];
			if(!use[v]) t ++;
			
		}
		if(t >= 3) ans ++;
	}
	if(ans == ans1) puts("Yes");
	else puts("No");
	return 0;
}

