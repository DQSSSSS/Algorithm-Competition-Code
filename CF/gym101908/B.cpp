#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
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

bool vis[11000];
int f[110][110];

int main() {
    int n = read();
    memset(f,-1,sizeof f);
    f[1][2] = 0;
    f[2][1] = 0;
    for(int i = 1;i <= 100;i ++) {
        for(int j = 1;j <= 100;j ++) {
            if(i == j) continue;
            if(i == 1 && j == 2) continue;
            if(i == 2 && j == 1) continue;
            memset(vis,0,sizeof vis);
            for(int k = 1;k < i;k ++) {
                if(k == j) continue;
                vis[f[k][j]] = 1;
            }
            for(int k = 1;k < j;k ++) {
                if(k == i) continue;
                vis[f[i][k]] = 1;
            }
            for(int k = 1;k < min(i,j);k ++) vis[f[i-k][j-k]] = 1;
            for(int k = 0;k <= 300;k ++)
                if(!vis[k]) {
                    f[i][j] = k;
                    break;
                }
        }
    }
    int ans = 0;
    while(n --) {
        int x = read(),y = read();
        if(x == y) { puts("Y"); return 0; }
        ans ^= f[x][y];
    }
    puts(ans ? "Y" : "N");
}
