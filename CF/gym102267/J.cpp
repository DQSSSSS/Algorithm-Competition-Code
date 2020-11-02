#include<bits/stdc++.h>
using namespace std;

const int SZ = 2010;
const int mod = 1e9 + 7;

int sum[SZ][SZ];
int f[SZ][SZ];
int g[SZ];

int main() {
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    int len = min(k,m/2); /// ³¤¶È

    f[0][1] = 1;
    for(int i = 1;i <= m;i ++) {
        for(int j = 1;j <= len+1;j ++) {
            if(j>1) (f[i][j] += f[i-1][j-1]) %= mod;
            if(j<= len) (f[i][j] += f[i-1][j+1]) %= mod;
            printf("%d ",f[i][j]);
        }
        puts("");
    }

    for(int i = 1;i <= len+1;i ++) {
        for(int j = 1;j <= m;j ++) {
            sum[j][i] = (sum[j-1][i] + f[j][i]) % mod;
        }
    }

    for(int i = 1;i <= len;i ++) {
        int ans = 0;
        for(int j = 1;j <= m;j ++) {
            (ans += 1ll * f[j][i+1] * sum[m-j][i+1] % mod) %= mod;
        }
        g[i] = ans;
    }

    int ans = 0;
    for(int i = 1;i <= len;i ++) {
        cout << g[i] << " ";
        (ans += g[i]) %= mod;
    }
    ans = 1ll * ans * 2 * n % mod;
    cout << ans << endl;
}
