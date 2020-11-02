#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 5e6 + 10;
const LL INF = 1e9 + 10;
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

char mp[55][55];
int f[55][55][55][55];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) scanf("%s",mp[i]+1);
    for(int j = 1;j <= n;j ++) {
        for(int i = j;i >= 1;i --) {
            for(int r = 1;r <= n;r ++) {
                for(int l = r;l >= 1;l --) {
                    if(i == j && l == r) {
                        f[i][j][l][r] = mp[i][l] == '#';
                        continue;
                    }
                    f[i][j][l][r] = max(j-i+1,r-l+1);
                    for(int k = l;k < r;k ++) {
                        f[i][j][l][r] = min(f[i][j][l][r],
                                            f[i][j][l][k] + f[i][j][k+1][r]);
                    }
                    for(int k = i;k < j;k ++) {
                        f[i][j][l][r] = min(f[i][j][l][r],
                                            f[i][k][l][r] + f[k+1][j][l][r]);
                    }
                }
            }
        }
    }
    printf("%d\n",f[1][n][1][n]);
}
