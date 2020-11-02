#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

LL f[SZ];

int main() {
    LL n = read();
    if(n == 1) {
        cout << 3 << " " << 1 << endl;
        return 0;
    }
    for(LL k = 1;k <= 1e6;k ++) f[k] = k;
    for(LL k = 3;;k ++) {
        if(1+f[2]*2 > n) break;
        LL sum = 0;
        for(LL i = 1;;i ++) {
            f[i] *= i;
            sum += f[i];
            if(sum > n) break;
            if(sum == n) {
                printf("%lld %lld\n",k,i);
                return 0;
            }
        }
    }
    puts("impossible");
}

