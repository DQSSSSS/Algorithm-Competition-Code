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

int head[SZ],nxt[SZ],tot = 1,n;

struct edge
{
	int f,t,d;
}l[SZ];

void build(int f,int t,int d)
{
	l[++ tot] = (edge){t,d};
	nxt[tot] = head[f];
	head[f] = tot;
}

void insert(int f,int t,int d)
{
	build(f,t,d); build(t,f,0);
}

int n,m,s,e;
int deep[SZ];
queue<int> q;
bool bfs()
{
    memset(deep,0,sizeof(deep));
    while(q.size()) q.pop();
    deep[s] = 1;
    q.push(s);
    while(q.size())
    {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(l[i].d && !deep[v])
            {
                deep[v] = deep[u] + 1;
                if(v == e) return true;
                q.push(v);
            }
        }
    }
    return false;
}
LL dfs(int u,LL flow)
{
    if(u == e || flow == 0) return flow;
    LL ans = flow;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(l[i].d && deep[v] == deep[u] + 1)
        {
            LL f = dfs(v,min(ans,l[i].d));
            if(f > 0)
            {
                l[i].d -= f;
                l[i ^ 1].d += f;
                ans -= f;
                if(ans == 0) break;
            }
            else deep[v] = 0;
        }
    }
    if(ans == flow) deep[u] = 0;
    return flow - ans;
}
LL dinic()
{
    LL ans = 0;
    while(bfs())
    {
        int tmp = dfs(s,INF);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

int main()
{
	n = read();
	for(int i = 1;i <= n;i ++)
		scanf("%s",mp[i] + 1);
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m
	}
	dfs(1);
	if(!ok) puts("No Solution");
	return 0;
}
