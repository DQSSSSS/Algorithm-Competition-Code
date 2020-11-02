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
int f[SZ],gs;
vector<int> g[SZ];

void dfs(int u) {
    if(g[u].size() == 0) {
        gs ++,f[u] = 1;
        return ;
    }
    for(int v : g[u]) {
        dfs(v);
    }
    if(!w[u]) {
        for(int v : g[u]) f[u] += f[v];
    }
    else {
        f[u] = 1e9;
        for(int v : g[u]) f[u] = min(f[u],f[v]);
    }
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i++) scanf("%d",w + i);
    for(int i = 2;i <= n;i++) {
        int x = read();
        g[x].push_back(i);
    }
    dfs(1);
    printf("%d\n",gs - f[1] + 1);
    return 0;
}
