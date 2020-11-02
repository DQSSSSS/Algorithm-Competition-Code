#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

int a[SZ];

int main() {
    int n = read();
    double sum = 0;
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        sum += a[i];
    }
    sum /= n;
    int ans = 0;
    for(int i = 1;i <= n;i ++) if(a[i] > sum + 1e-6) ans ++;
    cout << ans << endl;
}
