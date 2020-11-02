#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e7 +10;

LL n,p,r;

LL inv[SZ];

int main() {
    scanf("%lld %lld %lld",&n,&p,&r);
    inv[1] = 1;
    for(int i = 2;i <= 1e7;i ++) inv[i] = (p - p/i * inv[p%i] % p) % p;
    if(r == 0) {
        if(n > p) return printf("%lld %d\n",n,1),0;
        if(n == p) {
            if(n > 2) return printf("%d %d\n",2,1),0;
            else return puts("-1 -1"),0;
        }
        else return puts("-1 -1"),0;
    }
    if(n >= 2*p) {
        return puts("-1 -1"),0;
    }

    if(n >= p) {
        LL ans = 1;
        for(int i = 1;i <= n;i ++) {
            if(i!=p) ans = ans * i % p;
        }
        LL k = r * inv[ans] % p;
        if(k < p) return printf("%lld %lld\n",p,k),0;
        return puts("-1 -1"),0;
    }

    LL ans = 1;
    for(int i = 1;i <= n;i ++) ans = ans * i % p;

    for(int i = 1;i <= n;i ++) {
        LL k = r * i % p * inv[ans] % p;
        if(k < i) {
            return printf("%d %lld\n",i,k),0;
        }
    }

    return puts("-1 -1"),0;
}
