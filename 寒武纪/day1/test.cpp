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
int head[SZ],nxt[SZ],tot = 1;


struct edge
{
	int t;
	LL d;
}l[SZ];

void build(int f,int t,LL d)
{
	l[++ tot] = (edge){t,d};
	nxt[tot] = head[f];
	head[f] = tot;
}

int dist[SZ];
bool use[SZ];

void spfa(int s)
{
	for(int i = 1;i <= n;i ++) dist[i] = INF,use[i] = 0;
	dist[s] = 0;
	q.push(s);
	use[s] = 1;
	while(q.size())
	{
		int u = q.front(); q.pop();
		use[u] = 0;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = l[i].t;
			if(dist[v] > dist[u] + l[i].d)
			{
				dist[v] = dist[u] + l[i].d;
				if(!use[v])
					use[v] = 1,q.push(v);
			}
		}
	}
}


int main()
{
	
	return 0;
}

