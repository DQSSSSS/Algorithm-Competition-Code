#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e5 + 10;
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

int dx[SZ],bx[SZ],dfs_clock = 0,bfs_clock = 0;
int pre[SZ],sz[SZ],deep[SZ],n;
vector<int> g[SZ];
int maxd = 0;

void dfs(int u,int f) {
    dx[++ dfs_clock] = u;
    pre[u] = dfs_clock;
    sz[u] = 1;
    deep[u] = deep[f] + 1;
        maxd = max(maxd,deep[u]);
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
        if(v == f) continue;
        dfs(v,u);
    	sz[u] += sz[v];
    }
}

int main() {
	freopen("in.txt","w",stdout);
	srand(time(0));
    int n = 1000,q = 2000;
    cout << n << " " << q << endl;
    for(int i = 2;i <= n;i ++) {
    	int u = rand() % (i - 1) + 1;
    	printf("%d %d\n",i,u);
    	g[i].push_back(u);
    	g[u].push_back(i);
    }
    maxd = 0;
    dfs(1,0);
    //cout << maxd << endl;
    while(q --) {
        int opt = rand() % 2 + 1;
		if(opt == 1) {
            printf("%d %d %d\n",1,rand() % maxd,rand() % 10 + 1);
		}
		else {
            printf("%d %d\n",2,rand() % n + 1);
		}
    }
}
