#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e5 + 10;
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

vector<pii> g[SZ];

LL f[SZ][110];
int n,k,sz[SZ];

void dfs(int u,int fa) {
    for(int i = 0;i <= k;i ++) f[u][i] = 1e18;
    f[u][0] = 0;
    if(g[u].size() == 1) sz[u] = 1,f[u][1] = 0;
    else sz[u] = 0;
    for(pii p : g[u]) {
        int v = p.first,w = p.second;
        if(v == fa) continue;
        dfs(v,u);
        for(int i = min(sz[u]+sz[v],k);i >= 0;i --) {
            for(int j = 0;j <= min(i,sz[v]);j ++) {
                f[u][i] = min(f[u][i],f[u][i-j] + f[v][j] + 1ll*w*j*(k-j));
            }
        }
    //    printf("%d %d:\n",u,v); for(int i = 0;i <= k;i ++) printf("%lld ",f[u][i]); puts("");

        sz[u] += sz[v];
    }
 //   printf("%d:\n",u); for(int i = 0;i <= k;i ++) printf("%lld ",f[u][i]); puts("");
}

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        n = read(),k = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read(),z = read();
            g[x].push_back(make_pair(y,z));
            g[y].push_back(make_pair(x,z));
        }

        LL ans;
        if(n == 2) {
            if(k == 1) ans = 0;
            else ans = g[1][0].second;
        }
        else {
            int rt;
            for(int i = 1;i <= n;i ++) {
                if(g[i].size() != 1) {
                    rt = i;
                    break;
                }
            }
            dfs(rt,0);
            ans = f[rt][k];
        }
        printf("Case #%d: %lld\n",cc,ans);
    }
}

