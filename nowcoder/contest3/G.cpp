#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5010;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

LL read() {
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int n,k;

vector<int> g[SZ];

bool vis[SZ];
LL a[SZ];

int dfs(int u,int fa,int dist,int maxd) {
	if(dist == maxd) return 0;
	int ans = 1;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == fa || !vis[v]) continue;
		ans += dfs(v,u,dist + 1,maxd);
	}
	return ans;
}

queue<int> q;

LL f(int d) {
	for(int i = 1;i <= n;i ++) a[i] = vis[i] = 0;
    q.push(1);
    vis[1] = 1;
    a[1] = max(0,k - dfs(1,0,0,d) + 1);
    while(q.size()) {
    	int u = q.front(); q.pop();
        for(int i = 0;i < g[u].size();i ++) {
            int v = g[u][i];
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
            int x = dfs(v,0,0,d);
       		a[v] = max(0,k - x + 1);
        }
    }
  //  cout << d << endl;
  //  for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
    LL ans = 1;
    for(int i = 1;i <= n;i ++) ans = (ans * a[i]) % MOD;
    return ans;
}

int main() {
    int d;
	n = read(),k = read(),d = read();
	for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
	}
    printf("%lld\n",((f(d) - f(d + 1)) % MOD + MOD) % MOD);
	return 0;
}
