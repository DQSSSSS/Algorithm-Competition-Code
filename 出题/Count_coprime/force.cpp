#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 998244353;
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

int a[SZ];

int main() {
    freopen("data.in","r",stdin);
    freopen("force.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        int m = read();
        while(m --) {
            int l = read(),r = read(),x = read();
            int ans = 0;
            for(int i = l;i <= r;i ++) if(__gcd(x,a[i]) == 1) ans ++;
            printf("%d\n",ans);
        }
    }
    return 0;
}


