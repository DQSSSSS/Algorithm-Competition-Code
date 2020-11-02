#include<unordered_map>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}


/*
int ch[SZ][26],ptot = 0,val[SZ],fail[SZ];
char s[SZ];

void insert(char s[],int id)
{
	int len = strlen(s);
	int p = 0;
	for(int i = 0;i < len;i ++)
	{
		int c = s[i] - 'a';
		if(!ch[p][c]) ch[p][c] = ++ ptot;
		p = ch[p][c];
	}
	val[p] = id;
}

queue<int> q;

void build()
{
	fail[0] = 0;
	for(int i = 0;i < 26;i ++)
	{
		int u = ch[0][i];
		if(u == 0) continue;
		fail[u] = 0; q.push(u);
	}
	while(q.size())
	{
		int f = q.front(); q.pop();
		for(int i = 0;i < 26;i ++)
		{
			int u = ch[f][i];
			if(u == 0) continue;
			q.push(u);
			int v = fail[f];
			while(v && !ch[v][i]) v = fail[v];
			fail[u] = ch[v][i];
		}
	}
}

vector<int> pp[SZ];

void work()
{
	int len = strlen(s + 1),p = 0;
	for(int i = 1;i <= len;i ++)
	{
		int c = s[i] - 'a';
		while(p && ch[p][c] == 0) p = fail[p];
		p = ch[p][c];
		pp[p].push_back(i);
	}
}

vector<int> g[SZ],goal[SZ];
int a[SZ],ans[SZ],ask[SZ],Len[SZ];

void get_ans()
{
	for(int i = 1;i <= ptot;i ++)
		g[fail[i]].push_back(i);
	q.push(0);
	while(q.size())
	{
		int u = q.front(); q.pop();
		a[++ a[0]] = u;
		for(int i = 0;i < g[u].size();i ++) q.push(g[u][i]);
	}
	for(int i = 1;i <= ptot;i ++) g[fail[i]].clear();
	for(int i = a[0];i >= 2;i --)
	{
		int u = a[i];
		for(int i = 0;i < pp[u].size();i ++)
			goal[u].push_back(pp[u][i]);
		if(val[u])
		{
			sort(goal[u].begin(),goal[u].end());
			int id = val[u];
			ans[id] = INF;
			for(int l = 0,r = ask[id] - 1;r < goal[u].size();l ++,r ++)
				ans[id] = min(ans[id],goal[u][r] - goal[u][l] + Len[id]);
			if(ans[id] == INF) ans[id] = -1;
		}
		if(fail[u])
			for(int i = 0;i < goal[u].size();i ++)
				goal[fail[u]].push_back(goal[u][i]);
		cout << sizeof(goal) << endl;
		goal[u].clear();
	}
}

char ss[SZ];

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("my.out","w",stdout);
	scanf("%s",s + 1);
	int n = read();
	for(int i = 1;i <= n;i ++)
	{
		ask[i] = read();
		scanf("%s",ss);
		Len[i] = strlen(ss);
		insert(ss,i);
	}
	build();
	work();
	get_ans();
	for(int i = 1;i <= n;i ++) printf("%d\n",ans[i]);
	return 0;
}
*/

ULL mi[SZ],h[SZ];
char s[SZ],ss[SZ];

struct haha
{
	int k,len;
	ULL h;
}ask[SZ];

int id[SZ];

vector<int> ans[SZ];
unordered_map<ULL,int> mp;

bool cmp(int a,int b) { return ask[a].len < ask[b].len; } 

ULL get_h(int l,int r)
{
	//ULL ans = 0;
	//for(int i = l;i <= r;i ++) ans += mi[i - l] * (s[i] - 'a' + 1);
	return h[r] - h[l - 1] * mi[r - l + 1];
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("my.out","w",stdout);
	scanf("%s",s + 1);
	int len = strlen(s + 1);
	mi[0] = 1;
	for(int i = 1;i <= len;i ++) mi[i] = mi[i - 1] * 131;
	for(int i = 1;i <= len;i ++) h[i] = h[i - 1] * 131 + s[i];
	
	int n = read();
	for(int i = 1;i <= n;i ++)
	{
		ask[i].k = read();
		scanf("%s",ss);
		ask[i].len = strlen(ss);
		for(int j = 0;j < ask[i].len;j ++)
			ask[i].h = ask[i].h * 131 + ss[j];
		mp[ask[i].h] = i;
		id[i] = i;
	}
	sort(id + 1,id + 1 + n,cmp);
	//for(int i = 1;i <= n;i ++) cout << ask[i].k << " " << ask[i].s << endl;
	for(int o = 1,l = 1,dd = 1;o <= n;o += dd)
	{
		dd = 1;
		while(ask[id[o + dd]].len == ask[id[o]].len) dd ++;
		int d = ask[id[o]].len,m = len - d + 1;
		for(int i = 1;i <= m;i ++)
		{
			ULL now = get_h(i,i + d - 1);
			if(mp[now]) ans[mp[now]].push_back(i);
		}
	}
	
	for(int i = 1;i <= n;i ++)
	{
		if(ask[i].k > ans[i].size()) {puts("-1"); continue;}
		int Ans = INF;
		//for(int l = 0;l < ask[i].ans.size();l ++) cout << ask[i].ans[l] << " "; puts("");
		for(int l = 0,r = ask[i].k - 1;r < ans[i].size();l ++,r ++)
			Ans = min(Ans,ans[i][r] - ans[i][l] + ask[i].len);
		printf("%d\n",Ans);
	}
	return 0;
}

/*

*/
