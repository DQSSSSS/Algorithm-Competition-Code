#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,m,a[510][510],f[510][1025],pre[510][1025];

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            a[i][j] = read();
    memset(f,-1,sizeof f);
    f[0][0] = 1;
    for(int i = 1;i <= n;i ++) {
        for(int k = 1;k <= m;k ++) {
            for(int j = 0;j < 1024;j ++) {
                if(f[i-1][j] != -1) {
                    f[i][j^a[i][k]] = 1;
                    pre[i][j^a[i][k]] = k;
                }
            }
        }
    }
    for(int i = 1;i < 1024;i ++) {
        if(f[n][i] != -1) {
            puts("TAK");
            vector<int> ans;
            int x = pre[n][i],m = i;
            for(int j = n;j >= 1;j --) {
                ans.push_back(x);
                x = pre[j-1][m^=a[j][x]];
            }
            for(int j = n-1;j >= 0;j --) cout << ans[j] << " ";
            return 0;
        }
    }
    puts("NIE");
}
