#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 82;
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

int f[2][SZ][SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        int mod = read();
        memset(f,0,sizeof(f));
        f[1][1][1] = n * m;
        for(int k = 1;k < n * m;k ++) {
            int nw = k & 1,nx = nw ^ 1;
            memset(f[nx],0,sizeof(f[nx]));
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= m;j ++) {
                    int d = f[nw][i][j];
                    if(d) {
                        f[nx][i + 1][j] = (f[nx][i + 1][j] + 1ll * (n - i) * j * d) % mod;
                           f[nx][i][j + 1] = (f[nx][i][j + 1] + 1ll * (m - j) * i * d) % mod;
                           f[nx][i][j] = (f[nx][i][j] + 1ll * (i * j - k) * d) % mod;
                    }
                }
        }
        printf("%d\n",f[n * m & 1][n][m]);
    }
    return 0;
}
