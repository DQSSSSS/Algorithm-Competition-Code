#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double LD;
typedef pair<LL,LL> pii;
const int SZ = 210010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;
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

vector<int> g[SZ];

int s,e,maxdist;
int b[SZ],a[SZ];

void dfs(int u,int f,int nowd,int flag) {
	if(b[u] && nowd > maxdist) {
		maxdist = nowd;
		if(flag == 0) s = u;
		else e = u;
	}
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs(v,u,nowd + 1,flag);
	}
}

int main() {
	int T = read();
	while(T --) {
		int n = read(),m = read();
		for(int i = 1;i <= n;i ++) g[i].clear(),b[i] = 0;
		for(int i = 1;i <= m;i ++) b[a[i] = read()] = 1;
		for(int i = 1;i < n;i ++) {
			int x = read(),y = read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(m == 1) { puts("0.00"); continue; }
		s = e = -1; maxdist = 0;
		dfs(a[1],0,0,0); maxdist = 0;
		dfs(s,0,0,1);
		printf("%d.00\n",maxdist / 2);
	}
	return 0;
}
