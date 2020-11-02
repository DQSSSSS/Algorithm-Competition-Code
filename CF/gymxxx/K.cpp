#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 3010;
const int mod = 1e9 + 7;

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int f[SZ][SZ];
int C[SZ][SZ];
int inv[SZ],n,m;
vector<int> g[SZ];

void dfs(int u) {
    for(int i = 1;i <= m;i ++) f[u][i] = i;
    for(int v : g[u]) {
        dfs(v);
        for(int i = 1;i <= m;i ++) {
            f[u][i] = 1ll * f[u][i] * f[v][i] % mod * (i-1) % mod * inv[i] % mod;
        }
    }
    //cout << u << endl;
    //for(int i = 1;i <= m;i ++) printf("%d ",f[u][i]); puts("");
}

int main() {
    scanf("%d%d",&n,&m);
    inv[1] = 1;
    for(int i = 2;i <= m;i ++) inv[i] = ksm(i,mod-2);
    C[0][0] = 1;
    for(int i = 1;i <= m;i ++) {
        C[i][0] = 1;
        for(int j = 1;j <= i;j ++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    for(int i = 1;i < n;i ++) {
        int x;
        scanf("%d",&x);
        g[x].push_back(i);
    }
    dfs(0);

    int ans = 0;
    for(int i = m,b = 1;i >= 1;i --,b *= -1) {
       // cout << f[0][i] << " " << C[m][i] << endl;
        (ans += 1ll * b * f[0][i] * C[m][i] % mod) %= mod;
       // cout << ans << endl;
    }
    ans += mod; ans %= mod;
    cout << ans << endl;
}
/**
2 3
0
*/
