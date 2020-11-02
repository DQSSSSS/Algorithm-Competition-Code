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
int head[SZ],nxt[SZ],tot = 1;

struct edge
{
	int t,d;
}l[SZ];

void build(int f,int t,int d)
{
	l[++ tot] = (edge){t,d};
	nxt[tot] = head[f];
	head[f] = tot;
}

bool ins[SZ],vis[SZ];
int pre[SZ];
map<int,int> is[SZ];
stack<int> S;

bool find_r(int u)
{
	S.push(u);
	ins[u] = 1;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = l[i].t;
		if(vis[i] || vis[i ^ 1]) continue;
		vis[i] = vis[i ^ 1] = 1;
		if(ins[v])
		{
			is[v][u] = is[u][v] = 1;
			while(233)
			{
				int x = S.top(); S.pop();
				ins[x] = 0;
				if(x == v) break;
				is[pre[x]][x] = is[x][pre[x]] = 1;
			}
			return true;
		}
		else if(pre[v] = u,find_r(v)) return true;
		vis[i] = vis[i ^ 1] = 0;
	}
	S.pop();
	ins[u] = 0;
	return false;
}

multiset<int> c[SZ];
int rc[SZ],sum;

int ans = 0;
void calc()
{
	for(int u = 1;u <= n;u ++)
	{
		for(int i = head[u];i;i = nxt[i])
		{
			int d = l[i].d;
			if(c[u].find(d) == c[u].end()) ans ++;
			c[u].insert(d);
			if(is[u][l[i].t]) if(rc[d] ++ == 0) sum ++;
		}
	}
}

void change(int u,int d,int pre,bool flag)
{
	multiset<int> :: iterator it = c[u].find(pre);
	c[u].erase(it);
	if(c[u].find(pre) == c[u].end()) ans --;
	
	if(c[u].find(d) == c[u].end()) ans ++;
	c[u].insert(d);
	if(flag)
	{
		if(-- rc[pre] == 0) sum --;
		if(rc[d] ++ == 0) sum ++;
	}
}

map<int,int> mp[SZ];

void init()
{
	for(int i = 1;i <= tot;i ++)
		pre[i] = rc[i] = head[i] = ins[i] = vis[i] = 0,c[i].clear(),mp[i].clear(),is[i].clear();
	while(S.size()) S.pop();
	tot = 1; ans = 0;
	sum = 0;
}

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
		init();		
		n = read(),m = read();
		for(int i = 1;i <= n;i ++)
		{
			int x = read(),y = read(),z = read();
			build(x,y,z); build(y,x,z);
			mp[x][y] = mp[y][x] = z;
		}
		find_r(1);
		calc(); /// 统计每个点连的颜色数
		printf("Case #%d:\n",++ cc);
		for(int i = 1;i <= m;i ++)
		{
			int x = read(),y = read(),z = read(),pre = mp[x][y];
			mp[x][y] = mp[y][x] = z;
			bool flag = is[x][y];
			change(x,z,pre,flag); change(y,z,pre,flag);
			int d = 0;
			if(sum == 1) d = 1;
			printf("%d\n",ans + d - n);
		}
	}
	return 0;
}
