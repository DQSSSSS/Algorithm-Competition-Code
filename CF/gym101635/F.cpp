#include<bits/stdc++.h>
using namespace std;

int main() {
    int w,n;
    while(~scanf("%d%d",&w,&n)) {
        long long ans = 0;
        for(int i = 1;i <= n;i ++) {
            int x,y;
            scanf("%d%d",&x,&y);
            ans+=1ll*x*y;
        }
        printf("%lld\n",ans/w);
    }
}
