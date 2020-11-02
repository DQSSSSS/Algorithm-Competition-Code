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
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int n,m;

double g[550][550];

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a % b);
}

int D(int x)
{
	int ans = 0;
	for(int i = 1;i <= x;i ++)
		if(x % i == 0) ans ++;
	return ans;
}

double gauss(int n)
{
	int now = 1;
	for(int i = 1;i <= n;i ++)
	{
		now = i;
		for(int j = i + 1;j <= n;j ++)
			if(fabs(g[j][i]) > fabs(g[now][i])) now = j;
		if(now != i)
			for(int j = 1;j <= n;j ++)
				swap(g[now][j],g[i][j]);
		for(int j = i + 1;j <= n;j ++)
		{
			double tmp = g[j][i] / g[i][i];
			for(int k = i;k <= n;k ++) g[j][k] -= tmp * g[i][k];
		}
	}
	double ans = 1;
	for(int i = 1;i <= n;i ++) ans = ans * g[i][i];
	return ans;
}

int t[SZ];

int main()
{
	for(n = 2;n <= 500;n ++)
	{
		for(int i = 1;i < n;i ++)
			for(int j = 1;j < n;j ++)
				g[i][j] = D(gcd(i + 1,j + 1));
		int ans = gauss(n - 1);
		printf("%d %d\n",n,ans);
		t[abs(ans)] ++;
	}
	for(int i = 1;i <= 500;i ++) printf("%d %d\n",i,t[i]);
	return 0;
}


