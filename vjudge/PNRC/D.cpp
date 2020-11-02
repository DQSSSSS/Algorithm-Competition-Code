#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
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

int n,k;
struct edge {
    int t,d;
};

vector<edge> g[SZ];
LL f[SZ][22],ans,val[SZ];
int sz[SZ];

void dfs(int u,int fa) {
    sz[u] = 1;
    for(edge e : g[u]) {
        int v = e.t;
        if(v == fa) continue;
        dfs(v,u);
        sz[u] += sz[v];
        val[u] += val[v] + e.d;
        for(int i = min(sz[u],k);i >= 0;i --)
            for(int j = 0;j <= min(sz[v],i);j ++) {
                if(j < sz[v])
                    f[u][i] = max(f[u][i],f[u][i-j] + f[v][j]);
                else
                    f[u][i] = max(f[u][i],f[u][i-j] + f[v][j] + e.d);
            }
  //      cout << u << endl;
  //      for(int i = 0;i <= k;i ++) cout << f[u][i] << " "; puts("");
    }
    for(int i = 0;i <= k;i ++)
        if(sz[u] - i == n - k)
            ans = min(ans,(val[u] - f[u][i])*2);

    //cout << "-- " << u << endl;
    //    for(int i = 0;i <= k;i ++) cout << f[u][i] << " "; puts("");
}

int main() {
    int T = read();
    while(T --) {
        n = read(),k = read();
        for(int i = 1;i <= n;i ++) {
            g[i].clear();
            val[i] = 0;
            for(int j = 0;j <= k;j ++)
                f[i][j] = 0;
        }

        LL sum = 0;
        for(int i = 1;i < n;i ++) {
            int x = read()+1,y = read()+1,z = read();
            g[x].push_back((edge){y,z});
            g[y].push_back((edge){x,z});
            sum += z * 2;
        }
        ans = 1e18;
        dfs(1,0);
        printf("%lld\n",ans);
    }
}
/*
233
9 2
0 1 1000
1 2 1200
0 3 1000
3 4 1200
0 5 1000
5 6 1200
0 7 1800
7 8 600

*/
