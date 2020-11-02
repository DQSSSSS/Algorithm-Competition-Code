#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2010;
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


void work1(double f[SZ][SZ]) {
    bool r[SZ] = {0},c[SZ] = {0};
    int n = read(),m = read();
    for(int i = n+1;i >= 0;i --)
        for(int j = n+1;j >= 0;j --)
            f[i][j] = 0;
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        r[x] = 1;
        c[y] = 1;
    }
    int tx = 0,ty = 0;
    for(int i = 1;i <= n;i ++) {
        if(r[i] == 1) tx ++;
        if(c[i] == 1) ty ++;
    }
    for(int i = n;i >= 0;i --) {
        for(int j = n;j >= 0;j --) {
            if(i == n && j == n) continue;
            double t = n*n-i*j;
            f[i][j] = f[i+1][j]*j*(n-i)/t + f[i][j+1]*i*(n-j)/t + f[i+1][j+1]*(n-i)*(n-j)/t + 1.0*n*n/t;
        }
    }
    printf("%.5f\n",f[tx][ty]);
}

double f[2010][2010];

int main() {
    freopen("data9.in","r",stdin);
    freopen("data9.out","w",stdout);
    int T = read();
    while(T --) {
        work1(f);
    }
}
