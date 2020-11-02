#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
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

int w[SZ];
vector<int> g[SZ];

int sz[SZ],leaf;

void dfs(int u) {
    for(int v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    if(g[u].size() == 0) sz[u] = 1,leaf ++;
}

int f[SZ];

void dfs2(int u) {
    for(int v : g[u]) {
        dfs2(v);
        if(w[u] == 0) f[u] += f[v];
    }
    if(g[u].size() == 0) sz[u] = 1,leaf ++;
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i++) scanf("%d",w + i);
    for(int i = 2;i <= n;i++) {
        int x = read();
        g[x].push_back(i);
    }
    dfs(1);
    int ans = dfs2(1);
    cout << leaf - ans;
}
