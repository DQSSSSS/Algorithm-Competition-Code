#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 332748118;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ];
int f[1010][1010];
int g[1010][1010];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();

        for(int i = 0;i <= n;i ++) {
            for(int j = 0;j <= n;j ++) {
                f[i][j] = -INF;
                g[i][j] = INF;
            }
        }
        f[0][1] = -1; g[0][1] = 1;
        f[1][0] = 1; g[1][0] = -1;

        for(int i = 0;i <= n;i ++) {
            for(int j = 0;j <= n;j ++) {
                if(i < j) {
                    if(j < n) {
                        if(a[j+1] > a[i]) {
                            f[j+1][j]
                        }
                        if(a[j+1] > a[j]) {

                        }
                    }
                }
                if(j < i) {

                }
            }
        }


        if(flag) puts("-1");
        else printf("%d\n",abs(len1-(n-len1)));
    }
}
