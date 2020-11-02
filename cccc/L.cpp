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

struct lb
{
	int now,x,nx;
}l[SZ];

bool b[SZ];
lb S[2][SZ];
int len[2];

void dfs(int u)
{
	if(u == -1) return ;
	int ax = abs(l[u].x);
	int d = 0;
	if(b[ax]) d = 1;
	else b[ax] = 1;
	len[d] ++;
	S[d][len[d]] = l[u];
	dfs(l[u].nx);
}

int main()
{
	int fst = read(),n = read();
	for(int i = 1;i <= n;i ++)
	{
		int now = read();
		l[now].x = read();
		l[now].nx = read();
		l[now].now = now;
	}
	dfs(fst);
	for(int i = 0;i <= 1;i ++)
	{
		for(int j = 1;j <= len[i];j ++)
		{
			printf("%05d %d ",S[i][j].now,S[i][j].x);
			if(j == len[i]) puts("-1");
			else printf("%05d\n",S[i][j + 1].now);
		}
	}
	return 0;
}





