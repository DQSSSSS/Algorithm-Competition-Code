#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

int main() {
    int T = read();
    while(T --) {
        LL n = read(),k = read();
        LL ans = 0;
        while(n) {
            if(n % k == 0) n /= k,ans ++;
            else {
                LL x = n / k * k;
                ans += n - x;
                n = x;
            }
        }
        printf("%lld\n",ans);
    }
}
