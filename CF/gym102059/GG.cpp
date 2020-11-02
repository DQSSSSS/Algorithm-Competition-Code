#include <bits/stdc++.h>
using namespace std;

const int N = 255000;

long long dp[N][10][10];
long long a[N];

int main() {
    freopen("G.in","r",stdin);
    freopen("std.out","w",stdout);
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    const long long inf = 1LL<<60;
    for (int i = 2; i <= n+1; i++) cin >> a[i];
    a[1] = a[n+2] = inf; a[n+3] = 0;
    for (int k = 0; k <= n+3; k++) for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++) dp[k][i][j] = inf;
    dp[0][0][0] = 0;
    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) if (dp[i][j][k] < inf) {
                for (int s = i+1; s <= i+3 && s <= n+3; s++) {
                    for (int l : {0, 1}) {
                        if (k+l > m) break;
                        dp[s][j][k+l] = min(dp[s][j][k+l], dp[i][j][k] + a[s]*(1-l));
                        if (j < m && s >= i+2) {
                            long long mina = inf;
                            for (int t = i+1; t < s; t++) mina = min(mina, a[t]);
                            dp[s][j+1][k+l] = min(dp[s][j+1][k+l], dp[i][j][k] + a[s]*(1-l) + mina);
                        }
                        if (j < m-1 && s == i+3) {
                            dp[s][j+2][k+l] = min(dp[s][j+2][k+l], dp[i][j][k] + a[s]*(1-l)+a[i+1]+a[i+2]);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0;i <= n+3;i ++,puts("")) {
        cout << i << endl;
        for(int a = 0;a <= m;a ++,puts(""))
            for(int b = 0;b <= m;b ++) {
                printf("%3lld",dp[i][b][a]==inf?-1:dp[i][b][a]);
            }
    }

    long long ans = inf;
   // for (int i = 0; i <= m; i++) cout << dp[n-1][i][i] << " " << dp[n][i][i] << endl;
    for (int i = 0; i <= m; i++) ans = min(ans, dp[n+3][i][i]);
    cout << ans << endl;
    return 0;
}
