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

int n;
LL f[2010][2010];

int main() {
    n = read();
    for(int i = 0;i <= n;i ++)
        for(int j = i;j <= n;j ++) {
            if(i) f[i][j] += f[i-1][j];
            if(j) f[i][j] += f[i][j-1];
            f[i][j] += (i+j)%2;
            f[i][j] %= mod;
        }
    cout << f[n][n] << endl;
}
