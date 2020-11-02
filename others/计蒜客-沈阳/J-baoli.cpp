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
vector<int> g[1010];

void dfs(int u,int f) {
    dx[++ dfs_clock] = u;
    pre[u] = dfs_clock;
    sz[u] = 1;
    deep[u] = deep[f] + 1;
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
        if(v == f) continue;
        dfs(v,u);
    	sz[u] += sz[v];
    }
}
/*
queue<int> q;
bool vis[SZ];
void bfs(int u) {
    q.push(u);
    vis[u] = 1;
   	while(q.size()) {
        int u = q.front(); q.pop();
        bx[u] = ++ bfs_clock;
        for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i];
			if(vis[v]) continue;
			vis[v] = 1;
			q.push(v);
		}
   	}
}

bool cmp(int x,int y) {
	return bx[x] < bx[y];
}
*/
LL sum[SZ],a[SZ],dd[SZ],B;
short dp[330][100010];

void Add(int d,LL w) {
	dd[d] += w;
	for(int i = 0;i <= n / B;i ++) {
        sum[i] += 1ll * dp[i][d] * w;
	}
}

LL ask(int l,int r) {
    int lb = l / B,rb = r / B;
    LL ans = 0;
    while(l <= r && l / B == lb) {
		ans += dd[deep[dx[l]]]; l ++;
    }
    while(l <= r && r / B == rb) {
        ans += dd[deep[dx[r]]]; r --;
    }
//    if(l <= r)
		for(int i = lb + 1;i <= rb - 1;i ++) {
			ans += sum[i];
		}
    return ans;
}

LL baoli(int l,int r) {
    LL ans = 0;
    for(int i = l;i <= r;i ++) {
    	ans += dd[deep[dx[i]]];
    }
    return ans;
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("std.txt","w",stdout);
    n = read();
    int q = read();
    B = sqrt(n) + 1;
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    deep[0] = -1;
    dfs(1,0);// bfs(1);
    assert(dfs_clock == n);
    for(int i = 1;i <= n;i ++) {
        g[i / B].push_back(dx[i]);
    }
    for(int i = 0;i <= n / B;i ++) {
        //sort(g[i].begin(),g[i].end(),cmp);
    	for(int j = 0;j < g[i].size();j ++) {
            int x = g[i][j];
            dp[i][deep[x]] ++;
    	}
    }

    for(int i = 1;i <= q;i ++) {
		int opt = read();
		if(opt == 1) {
			int deep = read();
			LL d = read();
            Add(deep,d);
		}
		else {
			int u = read();
            //printf("%lld\n",ask(pre[u],pre[u] + sz[u] - 1));
            printf("%lld\n",baoli(pre[u],pre[u] + sz[u] - 1));
		}
    }
}
/***
8 233
1 2
1 3
2 4
2 5
3 6
3 8
6 7
*/

