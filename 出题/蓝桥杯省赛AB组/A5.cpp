#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int n,m;
int f[1010][1010];
int a[1010],b[1010];

int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
        for(int i = 1;i <= m;i ++) scanf("%d",&b[i]);
        for(int i = 0;i <= n;i ++) f[i][0] = 1;
        for(int i = 0;i <= m;i ++) f[0][i] = 1;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++) {
                if(a[i] != b[j]) {
                    f[i][j] = ((f[i-1][j] + f[i][j-1]) % mod - f[i-1][j-1] + mod) % mod;
                }
                else {
                    f[i][j] = (f[i-1][j] + f[i][j-1]) % mod;
                }
            }
        f[n][m] = (f[n][m] + mod - 1) % mod;
        cout << f[n][m] << endl;
    }
    return 0;
}
