#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

ULL f[110][3][110];

int main() {
    int n = read(),m = read();
    f[0][0][0] = 1;
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < 2;j ++) {
            for(int k = 0;k <= n/m;k ++) {
                f[i+1][j^1][k] += f[i][j][k];
                if(j == 0 && i+m <= n)
                    f[i+m][1][k+1] += f[i][0][k];
            }
        }
    }
    ULL ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int k = 0;k <= n/m;k ++) {
            ans += f[i][1][k];
          //  cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
