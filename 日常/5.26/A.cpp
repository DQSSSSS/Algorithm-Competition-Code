#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha
{
	int x,y,d;
}l[1000010];

bool cmp(haha a,haha b) { return a.d < b.d; }

struct edge
{
	int t;
	LL d;
};

vector<edge> g[SZ];
int fa[SZ],n,m;

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

LL sz[SZ];

void dfs(int u,int fa)
{
	sz[u] = 1;
    for(int i = 0;i < g[u].size();i ++)
	{
        int v = g[u][i].t;
        if(v == fa) continue;
        dfs(v,u);
        sz[u] += sz[v];
	}
}

LL me;

void dfs2(int u,int fa)
{
    for(int i = 0;i < g[u].size();i ++)
	{
        int v = g[u][i].t;
        if(v == fa) continue;
        me += g[u][i].d * sz[v] * (n - sz[v]);
        dfs2(v,u);
	}
}

int main()
{
    int T = read();
    while(T --)
	{
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) g[i].clear(),fa[i] = i;
        for(int i = 1;i <= m;i ++)
			l[i].x = read(),l[i].y = read(),l[i].d = read();
		sort(l + 1,l + 1 + m,cmp);
		LL mc = 0;
        for(int i = 1;i <= m;i ++)
		{
            int x = find(l[i].x),y = find(l[i].y);
            if(x != y)
			{
				fa[x] = y,mc += l[i].d;
				g[l[i].x].push_back((edge){l[i].y,l[i].d});
				g[l[i].y].push_back((edge){l[i].x,l[i].d});
			}
		}
		dfs(1,0);
		me = 0;
		dfs2(1,0);
        printf("%lld %.2f\n",mc,2.0 * me / ((double)n * (n - 1)));
	}
	return 0;
}


