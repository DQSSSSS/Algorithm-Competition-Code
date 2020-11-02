#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    LL n;
    while(~scanf("%lld",&n)) {
        LL ans = 0;
        for(int k = 1;;k ++) {
            LL t = 1;
            bool flag = 0;
            for(int i = 1;i <= k;i ++) {
                if(t>n/k) { flag = 1; break; }
                t *= k;
            }
            if(flag) break;
            ans ++;
        }
        printf("%lld\n",ans);
    }
}
