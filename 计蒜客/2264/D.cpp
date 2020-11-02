#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e5 + 10;
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

int n,m,w[SZ],f[SZ][460],tmp[460];
vector<int> g[SZ];

void dfs(int u,int fa) {
    f[u][1] = w[u];
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v,u);
        memset(tmp,63,sizeof(tmp));
        for(int i = 1;i <= 450;i ++) tmp[i] = f[u][i];
        for(int i = 1;i <= 450;i ++) {
            for(int j = 1;f[v][j] <= m;j ++) {
                tmp[i+j] = min(tmp[i+j],f[v][j] + f[u][i]);
            }
        }
        for(int i = 1;i <= 450;i ++) f[u][i] = tmp[i];
    }
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) w[i] = read();
    memset(f,63,sizeof(f));
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j <= 450;j ++) {
            if(f[i][j] <= m) ans = max(ans,j);
        }
    }
    cout << ans << endl;
}
