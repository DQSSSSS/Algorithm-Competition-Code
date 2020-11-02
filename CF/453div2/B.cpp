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

int c[SZ];

LL dfs(int u,int fa)
{
	LL ans = 1;
	LL sz = 0;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		ans += dfs(v,u);
		if(c[v] == c[u]) sz ++;
	}
	return ans - sz;
}

int main()
{
	n = read();
	for(int i = 2;i <= n;i ++)
	{
		int x = read();
		build(i,x); build(x,i);
	}
	for(int i = 1;i <= n;i ++) c[i] = read();
	cout << dfs(1,0) << endl;
	return 0;
}

