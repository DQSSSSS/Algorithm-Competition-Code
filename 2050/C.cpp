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

int main() {
    int T = read();
    while(T --) {
        LL n = read(),m = read(),k = read();
        LL a = read(),b = read(),c = read();
        LL ans = 1e18;
        for(int i = 0;i <= k;i ++) {
            for(int j = 0;j <= min(n+i,10ll);j ++) {
                for(int l = 0;l <= min(m+i,10ll);l ++) {
                    LL tmp = (k-i) * c;
                    tmp += (n+i-j+1)/2*a+(j+2)/3*b;
                    tmp += (m+i-l+1)/2*a+(l+2)/3*b;
                    ans = min(ans,tmp);
                }
            }
            for(int j = 0;j <= min(n+i,10ll);j ++) {
                for(int l = 0;l <= min(m+i,10ll);l ++) {
                    LL tmp = (k-i) * c;
                    tmp += (n+i-j+2)/3*b+(j+1)/2*a;
                    tmp += (m+i-l+2)/3*b+(l+1)/2*a;
                    ans = min(ans,tmp);
                }
            }
        }
        printf("%lld\n",ans);
    }
}
