#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

vector<int> g2[SZ];
vector<int> g[SZ];

int n,m,q;

int ccnt = 0;
int dfn[SZ],low[SZ],dfs_clock;
stack<int> S;
bool cut[SZ],ins[SZ];

void Tarjan(int u,int f) {
	dfn[u] = low[u] = ++ dfs_clock;
	S.push(u); ins[u] = 1;
	int child = 0;
	for(int i = 0;i < g2[u].size();i ++) {
		int v = g2[u][i];
		if(v == f) continue;
		if(!dfn[v]) {
			child ++;
			Tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfn[u]) {
				ccnt ++;
				cut[u] = 1;
				int x;
				do{
					x = S.top(); S.pop();
					ins[x] = 0;
					g[ccnt + n].push_back(x);
					g[x].push_back(ccnt + n);
				//	cout << x << " "<< ccnt + n << endl;
				}while(x != v && !S.empty());
				g[ccnt + n].push_back(u);
				g[u].push_back(ccnt + n);
				//cout << u << " " << ccnt + n << endl;
			}	
		}
		else if(ins[v]) {
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(f == 0 && child == 1) cut[u] = 0;
}

int anc[SZ][22],deep[SZ];

void dfsLca(int u,int f) {
	deep[u] = deep[f] + 1;
	anc[u][0] = f;
	for(int i = 1;anc[u][i - 1];i ++)
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfsLca(v,u);
	}
}	

int askLca(int u,int v) {
	if(deep[u] < deep[v]) swap(u,v);
	int dd = deep[u] - deep[v];
	for(int i = 20;i >= 0;i --)
		if(dd >> i & 1)
			u = anc[u][i];
	if(u == v) return u;
	for(int i = 20;i >= 0;i --)
		if(anc[u][i] != anc[v][i])
			u = anc[u][i],v = anc[v][i];
	return anc[u][0];
}

int main() {
	n = read(),m = read(),q = read();
	for(int i = 1;i <= m;i ++) {
		int x = read(),y = read();
		g2[x].push_back(y);
		g2[y].push_back(x);
	}
	//puts("");
	Tarjan(1,0);
	n += ccnt;
	dfsLca(1,0);
	//for(int i = 1;i <= n;i ++) cout << deep[i] << " "; puts("");
	/*
	cout << ccnt << endl;
	for(int i = 1;i <= n;i ++) cout << cut[i] << " "; puts("");
	for(int i = 1;i <= n;i ++) cout << belong[i] << " "; puts("");
	for(int i = 1;i <= ccnt;i ++) cout << csz[i] << " "; puts("");
	for(int i = 1;i <= n;i ++) {
		cout << ds[i].size() << endl;
		for(int j = 0;j < ds[i].size();j ++)
			cout << ds[i][j] << " ";
		puts("");
	}
	*/
	while(q --) {
		int x = read(),y = read();
		int lca = askLca(x,y);
		int ans = deep[x] + deep[y] - 2 * deep[lca];
		printf("%d\n",ans / 2);
	}
	return 0;
}
/**
8 11 4
1 2
2 3
3 4
4 5
1 3
1 6
3 5
3 7
4 7
5 7
6 8
1 5
2 4
6 7
3 8

9 12 233
1 2
1 3
2 3
1 4
4 5
1 5
4 7
4 6
6 7
5 8
5 9
8 9

*/
