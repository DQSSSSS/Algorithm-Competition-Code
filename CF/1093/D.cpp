#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

vector<int> g[SZ];
bool vis[SZ];
int c[SZ];
int q[SZ];

bool dfs(int u,int d) {
    q[++ q[0]] = u;
    vis[u] = 1;
    c[u] = d;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(vis[v]) {
            if(c[v] == c[u]) return false;
            continue;
        }
        if(!dfs(v,d ^ 1)) return false;
    }
    return true;
}

int mi[SZ];

int main() {
    int T = read();
    mi[0] = 1;
    for(int i = 1;i <= 3e5;i ++) mi[i] = mi[i - 1] * 2 % mod;
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) vis[i] = c[i] = 0,g[i].clear();
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        LL ans = 1;
        bool flag = 0;
        for(int i = 1;i <= n;i ++) {
            if(vis[i]) continue;
            q[0] = 0;
            if(!dfs(i,0)) { flag = 1; break; }
            int t = 0;
            for(int j = 1;j <= q[0];j ++)
                if(c[q[j]]) t ++;
            (ans *= (mi[t] + mi[q[0]-t]) % mod) %= mod;
        }
        if(flag) puts("0");
        else printf("%d\n",ans);
    }
    return 0;
}
