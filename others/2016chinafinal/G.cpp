#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct haha {
	int f,t,d;
}l[SZ];
bool cmp(haha a,haha b) { return a.d < b.d; }

int a[SZ],fa[SZ],mx[SZ],mxt[SZ];
map<int,int> S[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int id[SZ],Ans[SZ],ys[SZ],val[SZ];

vector<int> g[SZ];

int anc[SZ][22],mxdist[SZ][22],deep[SZ];

void dfs(int u,int f) {
	deep[u] = deep[f] + 1;
	anc[u][0] = f;
	mxdist[u][0] = val[f];
	for(int i = 1;i <= 20;i ++) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
		mxdist[u][i] = mxdist[anc[u][i - 1]][i - 1];
	}
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		dfs(v,u);
	}
}	

int main() {
	int T = read(),cc = 0;
	while(T --) {
		int n = read(),m = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
		for(int i = 1;i <= m;i ++) {
			l[i].f = read(),l[i].t = read(),l[i].d = read();
		}		
		sort(l + 1,l + 1 + m,cmp);
		int tot = 0;
		for(int i = 1;i <= n;i ++) S[i][a[i]] = 1,mx[i] = a[i],fa[i] = i,mxt[i] = 1;
		for(int x = 1;x <= n;x ++) id[x] = ++ tot,Ans[tot] = mx[x],ys[x] = tot,val[tot] = 0;
		for(int i = 1;i <= m;i ++) {
			int u,v;
			int x = find(u = l[i].f);
			int y = find(v = l[i].t);
			if(x != y) {
				if(S[x].size() > S[y].size()) swap(x,y),swap(u,v);
				fa[x] = y;
				while(S[x].size()) {
					map<int,int> :: iterator it = S[x].begin();
					S[y][it -> first] += it -> second;
					if(S[y][it -> first] > mxt[y] || (S[y][it -> first] == mxt[y] && mx[y] > it -> first)) 
						mxt[y] = S[y][it -> first],mx[y] = it -> first;
					S[x].erase(it);
				}
				Ans[++ tot] = mx[y];
				g[tot].push_back(ys[x]);
				g[tot].push_back(ys[y]);
				ys[y] = tot;
				val[tot] = l[i].d;
			//	cout << tot << " " << u << " " << v << " " << Ans[tot] << " " << val[tot]<< endl;
			}
		}
		/*cout << tot << endl;
		for(int i = 1;i <= n;i ++) cout << id[i] << " "; puts("");
		for(int i = 1;i <= tot;i ++) cout << Ans[i] << " "; puts("");
		*/
		for(int i = 1;i <= n;i ++)
			if(fa[i] == i)
				dfs(ys[i],0);
		/*
		for(int i = 1;i <= tot;i ++,puts("")) 
			for(int j = 0;j <= 10;j ++)
				cout << mxdist[i][j] << " "; puts("");
		*/
		printf("Case #%d:\n",++ cc);
		int q = read(),lstans = 0;
		while(q --) {
			int x = read() ^ lstans,y = read() ^ lstans;//cout << x << " " << y << endl;
			//int x = read(),y = read();
			x = id[x];
			//cout << x << endl;
			for(int i = 20;i >= 0;i --)
				if(anc[x][i] && mxdist[x][i] <= y)
					x = anc[x][i];
			//cout << x << endl;
			printf("%d\n",lstans = Ans[x]);
		}
		
		for(int i = 1;i <= tot;i ++) S[i].clear(),g[i].clear();
		memset(anc,0,sizeof anc);
		memset(mxdist,0,sizeof mxdist);
		memset(id,0,sizeof id);
		memset(Ans,0,sizeof Ans);
		memset(ys,0,sizeof ys);
		memset(val,0,sizeof val);
	}
	return 0;
}
/**
1
5 6
2 1 1 3 2
1 2 2
1 3 4
2 3 7
3 4 5
4 5 6
5 3 3
4
1 1
0 0
5 5
6 11

8 10
1 1 1 1 2 2 2 2
1 2 2
2 3 1
2 4 2
3 5 2
3 6 2
4 7 2
4 8 2
1 8 3
7 2 3
4 8 3
122

233
7 4
2 3 2 3 1 6 5
5 6 3
1 2 2
2 3 5
2 4 3

*/
