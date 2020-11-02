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

int n,m,ta,tb,k;
LL a[SZ],b[SZ];

int main() {
    n = read(),m = read(),ta = read(),tb = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read() + ta;
    a[++ n] = 3e9;
    for(int i = 1;i <= m;i ++) b[i] = read();
    b[++ m] = 3e9;
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        int x = lower_bound(b+1,b+1+m,a[i])-b;
        if(x <= m) {
            if(i-1 <= k) {
                int d = k - i + 1;
                x += d;
                if(x <= m) {
                    ans = max(ans,b[x]+tb);
                }
            }
        }
    }
    if(ans >= 3e9) ans = -1;
    cout << ans << endl;
}
/**
5 5 1 1 3
1 3 5 7 8
1 2 3 9 10

*/
