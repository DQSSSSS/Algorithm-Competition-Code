#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 500010;
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

vector<int> g[SZ];

LL ans = 0,mi[SZ],a[SZ];

int dfs(int u,int f) {
    int sz = 1;
    LL tmp = 0;
    for(int v : g[u]) {
        if(v == f) continue;
        int son = dfs(v,u);
        (tmp -= mi[son]-1) %= mod;
        sz += son;
    }
    (tmp += mi[sz]-1) %= mod;
    (ans += tmp * a[u] % mod) %= mod;
    return sz;
}

int main() {
    mi[0] = 1;
    for(int i = 1;i <= 1e5;i ++) mi[i] = mi[i-1] * 2 % mod;
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ans = 0;
        dfs(1,0);
        ans += mod; ans %= mod;
        cout << ans << endl;
    }
    return 0;
}
