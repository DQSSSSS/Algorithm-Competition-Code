#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e7 +10;

LL dfs(LL p,LL k,LL r) {
    if(r <= 0) return 0;
    if(k == 0) return p/2;
    LL sz = (1ll << (k+1)) - 1;
    if(r >= sz) {
        LL ans = p;
        for(int i = 1;i <= k-1;i ++) {
            ans += (1ll<<i)*(1ll<<i)*p + ((1ll<<i)-1)*(1ll<<(i-1));
        }
        ans *= 2;
        ans += p / 2;
        printf("%lld %lld %lld: %lld\n",p,k,r,ans);
        return ans;
    }
    LL lsz = (1ll << k) - 1;
    if(r <= lsz) return dfs(p<<1,k-1,r);
    else return dfs(p<<1,k-1,lsz) + dfs(p<<1|1,k-1,r-lsz);
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m); n --;
    while(m --) {
        LL x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        LL l = x,r = x + (z-1) * y;
        cout << l << " "<< r << endl;
        printf("%lld\n",dfs(1,n,r));
        printf("%lld\n",dfs(1,n,l - 1));
        printf("%lld\n",dfs(1,n,r) - dfs(1,n,l - 1));
    }
}
/*
4 4 3
4 12
52
10
*/
