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

struct haha {
    int l,r,x,c;
}a[55];

int f[55][55][55];

int main() {
    int n = read(),H = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        a[i].l = read(); a[i].r = read();
        a[i].x = read(); a[i].c = read();
    }

    for(int i = n;i >= 1;i --) {
        for(int j = i;j <= n;j ++) {
            for(int h = 0;h <= H;h ++) {
                for(int k = i;k <= j;k ++) {
                    int tmp = h * h;
                    for(int l = 1;l <= m;l ++) {
                        if(a[l].l >= i && a[l].r <= j &&
                           a[l].l <= k && k <= a[l].r && a[l].x < h)
                            tmp -= a[l].c;
                    }
                    f[i][j][h] = max(f[i][j][h],
                                     f[i][k-1][h] + f[k+1][j][h] + tmp);
                }
            }
            for(int h = 1;h <= H;h ++) f[i][j][h] = max(f[i][j][h],f[i][j][h-1]);
        }
    }
    int ans = 0;
    for(int i = 0;i <= H;i ++) {
        ans = max(ans,f[1][n][i]);
    }
    cout << ans << endl;
}
