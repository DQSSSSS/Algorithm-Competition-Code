#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const int mod = 1e7 + 7;

int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}

int main() {
    shai(1e6);
    int n;
    while(scanf("%d",&n) && n) {
        LL ans = 1;
        for(int i = 1;i <= tot;i ++) {
            int p = pri[i];
            if(p > n) break;
            LL tmp = 0;
            for(LL j = 1,d = p;d <= n;j ++,d *= p) {
                (tmp += n / d) %= mod;
            }
            tmp ++;
            tmp %= mod;
            (ans *= tmp * (tmp + 1) / 2 % mod) %= mod;
        }
        printf("%lld\n",ans);
    }
}
