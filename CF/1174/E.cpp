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

int n;
int f[SZ][22][2];

int F(int x,int y) {
    int d = 1<<x;
    if(y) d *= 3;
    return n / d;
}

int main(){
    n = read();
    int x = log2(n);
    if(x && (1<<(x-1))*3 <= n) f[1][x-1][1] = 1;
    f[1][x][0] = 1;

    for(int i = 1;i < n;i ++) {
        for(int j = 0;j <= x;j ++) {
            for(int k = 0;k < 2;k ++) {
                if(f[i][j][k]) {
                    (f[i+1][j][k] += 1ll * f[i][j][k] * (F(j,k)-i) % mod) %= mod;
                    if(j) (f[i+1][j-1][k] += 1ll * f[i][j][k] * (F(j-1,k)-F(j,k)) % mod) %= mod;
                    if(k) (f[i+1][j][k-1] += 1ll * f[i][j][k] * (F(j,k-1)-F(j,k)) % mod) %= mod;
                }
            }
        }
    }
    cout << f[n][0][0] << endl;
}
