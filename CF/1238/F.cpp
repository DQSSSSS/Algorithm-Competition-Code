#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1048576 + 10;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int ans,f[SZ],val[SZ];
vector<int> g[SZ];

void dfs(int u,int fa) {
    f[u] = val[u];
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v,u);
        ans = max(ans,f[u] + f[v]);
        f[u] = max(f[u],f[v] + val[u]);
    }
}

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i = 1;i <= n;i ++) {
            if(g[i].size() == 1) val[i] = 1;
            else val[i] = g[i].size() - 1;
        }
        ans = 0;
        dfs(1,0);
        printf("%d\n",ans);
    }
}
