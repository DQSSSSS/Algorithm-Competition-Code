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
        int W = read(),H = read(),n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= m;i ++) b[i] = -read();
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        LL ans = n+1;
        for(int i = 1,j = 1;i <= n;i ++) {
            while(j <= m && b[j] <= )
        }
        printf("%d\n",ans);
    }
}
