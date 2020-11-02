#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,m,x;
int head[SZ],nxt[SZ],tot = 1;

struct edge
{
	int t;
	LL d;
}l[SZ];

void build(int f,int t,LL d)
{
	//cout <<f << " " << t << " " << d << "   FUCK " << endl;
	l[++ tot] = (edge){t,d};
	nxt[tot] = head[f];
	head[f] = tot;
}

bool use[SZ];
LL dist[SZ],t[SZ];
queue<int> q;

bool spfa(int s)
{
	for(int i = 0;i <= n + 1;i ++) dist[i] = 1e18,t[i] = 0,use[i] = 0;
	while(q.size()) q.pop();
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
				{
					use[v] = 1,q.push(v);
					if(++ t[v] == n) return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
		for(int i = 0;i <= n + 1;i ++) head[i] = 0;
		tot = 1;
		n = read(),m = read(),x = read();
		for(int i = 1;i <= m;i ++)
		{
			int a = read(),b = read(),c = read(),d = read();
			if(a == b && c == d)
				build(a,c,x),build(c,a,- x);
			else
				build(b,c,x - 1),build(d,a,- x - 1);
		}
		for(int i = 2;i <= n;i ++) build(i,i - 1,-1);
		int s = n + 1;
		for(int i = 0;i <= n;i ++) build(s,i,1);
		printf("Case #%d: ",++ cc);
		if(!spfa(s)) {puts("IMPOSSIBLE"); continue;}
		for(int i = 2;i <= n;i ++)
			printf("%lld%c",dist[i] - dist[i - 1],i == n ? '\n' : ' ');
	}
	return 0;
}
