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
	if(f == -1 || t == -1) return ;
	to[++ tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}

double num[SZ],s[SZ];
int id[SZ];

map<int,int> mp;
int p = 0;

int get(int x)
{
	if(x == -1) return -1;
	if(!mp[x]) mp[x] = ++ p,id[p] = x;
	return mp[x];
}

struct haha
{
	int id,t;
	double num,s;
}a[SZ];

bool cmp(haha a,haha b)
{
	if(abs(a.s - b.s) > 1e-6) return a.s > b.s;
	return a.id < b.id;
}

bool vis[SZ];

void dfs(int u,int fa,haha &a)
{
	if(vis[u]) return ;
	vis[u] = 1;
	a.t ++;
	a.id = min(id[u],a.id);
	a.num += num[u];
	a.s += s[u];
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		dfs(v,u,a);
	}
}


int main()
{
	int n = read();
	for(int i = 1;i <= n;i ++)
	{
		int idd = read(),ff = read(),mm = read();
		int id = get(idd),f = get(ff),m = get(mm);
		build(id,f); build(f,id); build(id,m); build(m,id);
		int k = read();
		while(k --)
		{
			int c = get(read());
			build(id,c); build(c,id);
		}
		cin >> num[id] >> s[id];
	}
	int ans = 0;
	for(int i = 1;i <= p;i ++)
	{
		if(!vis[i])
		{
			ans ++;
			a[ans].id = INF;
			dfs(i,0,a[ans]);
			a[ans].num /= a[ans].t;
			a[ans].s /= a[ans].t;
		}
	}
	sort(a + 1,a + 1 + ans,cmp);
	printf("%d\n",ans);
	for(int i = 1;i <= ans;i ++)
		printf("%04d %d %.3f %.3f\n",a[i].id,a[i].t,a[i].num,a[i].s);
	return 0;
}




