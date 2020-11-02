#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 998244353;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL f[SZ],g[SZ],h[SZ];
vector<int> G[SZ];

void dfs(int u) {
    if(G[u].size() == 0) f[u] = g[u] = 1,h[u] = 0;
    else h[u] = 1;
    for(int v : G[u]) {
        dfs(v);
        LL fu = f[u],gu = g[u],hu = h[u];
        f[u] = (gu * g[v] % mod + fu * (h[v] + f[v]) % mod) % mod;
        g[u] = (gu * (h[v] + f[v]) % mod + hu * g[v] % mod + gu * g[v] % mod) % mod;
        h[u] = hu * (f[v] + h[v]) % mod;
       // cout << f[u] << " "<< g[u] << " " << h[u] << endl;
    }
}

int main() {
    int n = read();
    for(int i = 2;i <= n;i ++) {
        int x = read();
        G[x].push_back(i);
    }
    dfs(1);
    LL ans = f[1] + h[1];
    ans %= mod;
    cout << ans << endl;
}
