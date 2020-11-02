#include<bits/stdc++.h>
using namespace std;

typedef long long LL;



int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        LL n;
        scanf("%lld",&n);
        if(n%3==0) printf("%lld %lld %lld\n",n/3,n/3,n/3);
        else if(n%4==0) printf("%lld %lld %lld\n",n/2,n/4,n/4);
        else if(n%6==0) printf("%lld %lld %lld\n",n/2,n/2,n/3);
        else puts("IMPOSSIBLE");
    }
}
