#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1000 + 5;
int f[N], g[N][2], n;
int main() {
    while(cin >> n)
     {
        f[1] = 1, g[1][0] = 1;
        for(int i = 2; i <= n; i++) {
            g[0][1] = 0;
            for(int j = 1; j <= i; j++) {
                if(i & 1) f[j] = (g[i - 1][0] - g[j - 1][0] + mod) % mod;
                else f[j] = g[j - 1][0];
                g[j][1] = (g[j - 1][1] + f[j]) % mod;
                //cout << i << " " << j <<" " << f[j] << endl;
            }
            for(int j = 1; j <= n; j++) g[j][0] = g[j][1];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) ans = (ans + f[i]) % mod;
        ans = (ans + mod) % mod;
        cout << ans << endl;
    }

}
