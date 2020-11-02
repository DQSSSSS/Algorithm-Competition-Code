#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double,double> pii;
const int SZ = 1000010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};
const double eps = 1e-6;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
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

int f[SZ],t = 0,a[SZ],sum[SZ];

void dfs(int p,bool c)
{
	if(p == n + 1) return ;
	if(a[p] == 1) { int id = sum[p]; f[id] = id - 1; dfs(p + 1,c); }
	else
	{			

		//	cout << p << " " << c << " " << fa << " " << fa2 << endl;
		if(c == 0) 
		{
			int l = sum[p - 1] + 1,r = sum[p];
			for(int i = l;i <= r;i ++)
				f[i] = l - 1;
			dfs(p + 1,c);
		}
		else
		{
			int l = sum[p - 1] + 1,r = sum[p];
			//cout << p << " " << l << " " << r << endl;
			for(int i = l + 1;i <= r;i ++)
				f[i] = l - 1;
			f[l] = a[p - 1] == 1 ? l - 1 : l - 2;
			dfs(p + 1,c);
		}
	}
}

bool check()
{
	for(int i = 1;i <= n;i ++)
	{
		int x = a[i - 1],y = a[i];
		if(x == 1 || y == 1) continue;
		return false; 
	}
	return true;
}

int main()
{
	n = read();
	int x = 0;
	for(int i = 0;i <= n;i ++) x += a[i] = read();
	sum[0] = 1;
	for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + a[i];
	if(check()) { puts("perfect"); }
	else
	{
		puts("ambiguous");
		t = 0; dfs(0,0);
		for(int i = 1;i <= x;i ++) printf("%d ",f[i]); puts("");
		for(int i = 1;i <= x;i ++) f[i] = 0;
		t = 0; dfs(0,1);
		for(int i = 1;i <= x;i ++) printf("%d ",f[i]); puts("");
	}
	return 0;
}


