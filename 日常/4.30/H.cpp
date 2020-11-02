#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;

int tot = 0;

vector<int> g[SZ];
string name[SZ];
map<string,int> maps;
int fa[SZ],m,val[SZ];
bool wj[SZ],dr[SZ],is[SZ],isk[SZ];

bool cmp(int a,int b) { return name[a] < name[b]; }

int dfs_pre(int u)
{
	int sz = 1,t = 1;
	for(int i = 0;i < g[u].size();i ++)
	{
		int v = g[u][i];
		sz += dfs_pre(v);
		t ++;
		if(val[v] >= m) is[u] = 1;
	}
	//cout << name[u] << " " << u << " " << sz << " "<< t << endl;
	if(sz == t) isk[u] = 1;
	return sz;
}	

void dfs(int u,string now)
{
	if(g[u].size() == 0) return ;
	now += "/";
	//cout << u << " " << name[u] << " " << wj[u] << " " << val[u] << endl;
	//cout << is[u] << endl;
	string ss;
	if(isk[u]) ss = " ";
	else
	{
		if(is[u]) ss = "-";
		else ss = "+";
	}
	if(val[u] >= m)
	{
		cout << ss << " " << now << " " << val[u] << endl;
		if(ss == "-")
		{
			sort(g[u].begin(),g[u].end(),cmp);
			for(int i = 0;i < g[u].size();i ++)
			{
				int v = g[u][i];
				string tmp = now;
				tmp += name[g[u][i]];
				dfs(v,tmp);
			}
		}
	}
	else 
	{
		cout << ss << " " << now << " " << val[u] << endl;
	}

}

int son(int u,string s)
{
	for(int i = 0;i < g[u].size();i ++)
	{
		int v = g[u][i];
		if(s == name[v]) return v;
	}
	return -1;
}

char s[1010];

int main()
{
	int n;
	scanf("%d",&n);
	for(int k = 1;k <= n;k ++)
	{
		scanf("%s",s + 1);
		int len = strlen(s + 1),now = 0;
		for(int i = 2,l = 1;i <= len;i ++)
			if(s[i] == '/')
			{
				string S;
				for(int j = l + 1;j < i;j ++)
					S += s[j];
				int p = son(now,S);
				if(p == -1)
					p = maps[S] = ++ tot,name[tot] = S,
					g[now].push_back(p),fa[p] = now;
				dr[now] = 1;
				now = p;
				l = i;
			}
			else if(i == len)
			{
				string S;
				bool flag = 0;
				for(int j = l + 1;j <= len;j ++)
				{
					S += s[j];
					if(s[j] == '.') flag = 1;
				}
			//	if(!flag)
				{
					int p = son(now,S);
					if(p == -1)
						p = maps[S] = ++ tot,name[tot] = S,
						g[now].push_back(p),fa[p] = now;
					dr[p] = 1;
					wj[p] = 1;
					now = p;
				}
			//	else wj[now] = 1;
			}
		int x;
		scanf("%d",&x);
		val[now] += x;
		while(now)
		{
			int t = fa[now];
			val[t] += x;
			wj[t] |= wj[now];
			dr[t] |= dr[now];
			now = fa[now];
		}
	}
	scanf("%d",&m);

	//cout << tot << endl;	
	//for(int i = 1;i <= tot;i ++) cout << name[i] << " " << dr[i] << " " << wj[i] << endl;
	
	dfs_pre(0);
	dfs(0,"");
	return 0;
}
