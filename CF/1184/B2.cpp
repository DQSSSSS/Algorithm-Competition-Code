#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 3e6 + 10;
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
int match[SZ];

bool dfs(int u) {
    for(int v : g[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            if(!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int f[110][110];

struct hhhh {
    int x,a,f;
}a[SZ];

struct hhhhh {
    int x,d;
}b[SZ];

int main() {
    int n = read(),m = read();
    memset(f,63,sizeof f);
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        f[x][y] = f[y][x] = 1;
    }
    for(int k = 1;k <= n;k ++) f[k][k] = 0;
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++)
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    int S = read(),B = read(),K = read(),H = read();
    for(int i = 1;i <= S;i ++) a[i].x = read(),a[i].a = read(),a[i].f = read();
    for(int i = 1;i <= B;i ++) b[i].x = read(),b[i].d = read();

    for(int i = 1;i <= S;i ++) {
        for(int j = 1;j <= B;j ++) {
            int x = a[i].x,y = b[j].x;
            if(f[x][y] <= a[i].f && a[i].a >= b[j].d) {
                g[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= S;i ++) {
        for(int j = 1;j <= B;j ++) vis[j] = 0;
        if(dfs(i)) ans ++;
    }
    cout << min(1ll*ans*K,1ll*H*S) << endl;
}
