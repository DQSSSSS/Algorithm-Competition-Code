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

char mp[1010][1010],s[1010];
int n,m,len,pos;

void work()
{
	memset(mp,0,sizeof(mp));
	for(int i = 1;i <= m;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			mp[j][i] = s[pos ++];
			if(pos== len) return ;
		}
		if(pos == len) return;
	}
}

int main()
{
	scanf("%d\n",&n);
	scanf("%[^\n]",s);
	len = strlen(s);
	m = len / n + (len % n == 0 ? 0 : 1),pos = 0;
	work();
	for(int i = 1;i <= n;i ++)
	{
		for(int j = m;j >= 1;j --)
			printf("%c",mp[i][j]);
		puts("");
	}
	return 0;
}
