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

LL a[SZ],b[SZ],c[SZ];
LL f[1010][1010];

int main() {
    int T = read();
    while(T --) {
        int n = read(),now = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
            b[i] = read();
            c[i] = read();
        }
        memset(f,0,sizeof f);
        f[0][0] = now;
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j <= i;j ++) {
                if(f[i-1][j])
                    f[i][j] = f[i-1][j]+c[i];
                if(min(f[i-1][j-1],b[i]) > a[i])
                    f[i][j] = max(f[i][j],min(f[i-1][j-1],b[i])-a[i]+c[i]);
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i ++)
            if(f[n][i] > 0) ans = i;
        printf("%d\n",ans);
    }
}
