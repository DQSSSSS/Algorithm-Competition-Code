#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const LL INF = 1e18 + 10;
const int SZ = 1e3 + 10;
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

LL W,a[22],f[7010];

int main() {
    LL W = read(),L = 840;
    for(int i = 1;i <= 8;i ++) a[i] = read();
    for(int i = 1;i < 8 * L;i ++) f[i] = -INF;

    for(int i = 1;i <= 8;i ++) {
        for(int j = min(8*L-1,W);j >= 0;j --) {
            for(int k = 0;k <= min(a[i],L/i-1);k ++)
                if(j >= k*i && f[j-k*i] >= 0 && W-j-L*f[j-k*i] >= 0) {
                    f[j] = max(f[j],f[j-k*i] + min((a[i]-k)/(L/i),(W-j-L*f[j-k*i])/L));
                }
        }
    }
    LL ans = 0;
    for(int i = 0;i < 8 * L;i ++)
        if(f[i] >= 0)
            ans = max(ans,i + L * f[i]);
    cout << ans << endl;
}

/**
1843961714300273
1144009530854086 0 3048782373340161 0 0 0 0 0

10000000
5000000 0 50000000 0 0 0 0 0

22811212883819247
0 1108162468654312 9267849252941926 5641326481085349 0 0 0 0
*/
