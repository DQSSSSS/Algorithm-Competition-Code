#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

int main() {
    LL A = read(),B = read(),C = read(),D = read();
    LL ans = 0;
    for(int x = 1;x <= 999;x ++)
        for(int y = 1;y <= 999-x;y ++) {
            if(__gcd(x,y) != 1) continue;
            LL R = min(B/x,D/y);
            LL L = max((A+x-1)/x,(C+y-1)/y);
            ans += max(0ll,R-L+1);
        }
    cout << ans << endl;
}
