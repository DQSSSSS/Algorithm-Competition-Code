#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

LL f[SZ][2];
int a[SZ][2];

void dfs(int u,int fa) {
    f[u][0] = 0;
    f[u][1] = 0;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v,u);
        for(int i = 0;i < 2;i ++) {
            LL t = 0;
            for(int j = 0;j < 2;j ++) {
                t = max(t,abs(a[u][i]-a[v][j])+f[v][j]);
            }
            f[u][i] += t;
        }
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
        for(int i = 1;i <= n;i ++) a[i][0] = read(),a[i][1] = read();
        dfs(1,0);
        printf("%lld\n",max(f[1][0],f[1][1]));
    }
}
