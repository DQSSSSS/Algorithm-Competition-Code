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

int f[1010][2010],n,m,k,tmp[2010],sz[SZ];
vector<pii> g[SZ];

void dfs(int u,int fa) {
    sz[u] = 1;
    f[u][0] = f[u][1] = 0;
    for(pii p : g[u]) {
        int v = p.first,d = p.second;
        if(v == fa) continue;
        dfs(v,u);
        fill(tmp,tmp+2*m+1,INF);
        for(int i = 0;i <= min(m*2,sz[u]);i ++) {
            for(int j = 0;j <= sz[v] && i+j<=2*m;j ++) {
                if(j & 1) tmp[i+j] = min(tmp[i+j],f[u][i] + f[v][j] + d);
                else tmp[i+j] = min(tmp[i+j],f[u][i] + f[v][j] + 2*d);
            }
        }
        sz[u] += sz[v];
        for(int i = 0;i <= min(m*2,sz[u]);i ++) f[u][i] = tmp[i];
      //  printf("%d->%d\n",u,v);
    //    for(int i = 0;i <= min(m*2,sz[u]);i ++) cout <<tmp[i] << " "; puts("");
    }
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read(),k = read();
        for(int i = 1;i <= n;i ++) {
            g[i].clear();
            for(int j = 0;j <= 2*m;j ++) f[i][j] = INF;
        }
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read(),d = read();
            g[x].push_back(make_pair(y,d));
            g[y].push_back(make_pair(x,d));
        }
        dfs(1,0);
        int ans = 1e9;
        /*for(int j = 1;j <= n;j ++,puts(""))
            for(int i = 0;i <= sz[j];i ++) {
                cout << f[j][i] << " ";
            }*/

        for(int i = 0;i <= min(n,2 * m);i += 2) {
            ans = min(ans,f[1][i] + i/2*k);
        }
        printf("%d\n",ans);
    }
}
