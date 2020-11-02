#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    int T,cc = 0;
    scanf("%d",&T);
    while(T --) {
        int n;
        scanf("%d",&n);
        int ans = 0;
        for(int i = 1,r;i <= n;i = r + 1) {
            r = n / (n / i);
            ans += (r-i+1ll) * (n / i) & 1;
        }
        if(ans&1) printf("Case %d: odd\n",++ cc);
        else printf("Case %d: even\n",++ cc);
    }
}
