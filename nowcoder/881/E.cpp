#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int f[88][88][88][88];

int dfs(int l,int r,int a,int b) {
    if(a < 0 || b < 0) return 0;
    if(r-l+1 != 2*(a+b)) return 0;
    if(l == r + 1) {
        if(a == 0 && b == 0) return 1;
        else return 0;
    }
    if(l > r) return 0;
    if(f[l][r][a][b]) return f[l][r][a][b];
    int ans = dfs(l+1,r-1,a,b-1);
    for(int k = l;k <= r;k ++) {
        for(int i = 0;i <= a;i ++)
            for(int j = 0;j <= b;j ++)
                ans += (dfs(l+1,k-1,i-1,j)) *
                    dfs(k+1,r,a-i,b-j);
    }
    printf("%d %d %d %d\n",r-l+1,a,b,ans);
    return f[l][r][a][b] = ans;
}

int g[88][88][88];

int baoli(int n,int m) {
    memset(g,0,sizeof g);
    g[0][0][0] = 1;
    for(int i = 0;i <= 2*(n+m);i ++) {
        for(int a = 0;a <= 2*(n+m);a ++) {
            for(int b = 0;b <= 2*(n+m);b ++) {
                if(b == 0) g[i+1][a+1][0] += g[i][a][b];
                else g[i+1][a][b-1] += g[i][a][b];
                g[i+1][a][b+1] += g[i][a][b];
            }
        }
    }
    return g[6][1][1];
    return g[2*(n+m)][n][n];
}

int main() {
    //cout << dfs(1,6,1,2) << endl;
   // return 0;
    cout << baoli(1,2) << endl;
    return 0;
    for(int n = 0;n <= 5;n ++) {
        for(int m = 0;m <= 5;m ++) {
            //memset(f,0,sizeof f);
            printf("%d %d %d\n",n,m,baoli(n,m));
        }
    }
}
