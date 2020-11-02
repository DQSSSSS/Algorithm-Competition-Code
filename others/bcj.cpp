#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
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

int rk[SZ],fa[SZ];

int find(int x)
{
	return x == fa[x] ? x : find(fa[x]);
}

void Union(int x,int y)
{
	x = find(x),y = find(y);
	if(x == y) return ;
	if(rk[x] == rk[y]) { fa[x] = y; rk[y] ++; return ; }
	if(rk[x] > rk[y]) fa[y] = x;
	else fa[x] = y;
}



int main()
{
	int T = read();
	while(T --)
	{
		int n = read(),m = read();
		for(int i = 1;i <= n;i ++) rk[i] = 0,fa[i] = i;
		for(int i = 1;i <= m;i ++)
		{
			int x = read(),y = read();
			Union(x,y);
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++) if(find(i) == i) ans ++;
		printf("%d\n",ans);
	}
	return 0;
}
