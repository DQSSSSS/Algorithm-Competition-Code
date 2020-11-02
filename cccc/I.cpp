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

long double a[SZ],p[SZ],d;
bool b[SZ];
int n;

void dfs(int u)
{
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(b[v]) a[v] = a[u] * p[v] * d;
		else a[v] = a[u] * d;
		dfs(v);
	}
}

int main()
{
	n = read();
	cin >> a[0] >> d;
	d = 100 - d; d /= 100;
	for(int i = 0;i < n;i ++)
	{
		int k = read();
		if(k == 0)
		{
			b[i] = 1;
			cin >> p[i];
		}
		else
		{
			while(k --)
			{
				int x = read();
				build(i,x);
			}
		}
	}
	dfs(0);
	long double ans = 0;
	for(int i = 0;i < n;i ++) 
		ans += a[i] * b[i];
	printf("%d",(int)ans);
	return 0;
}


