#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int g[SZ],f[333][SZ],h[SZ];

LL work(int n) {
    int B = max(3,(int)sqrt(n));
    g[0] = 1;
    for(int i = 3;i < B;i ++)
        for(int j = i;j <= n;j ++)
            (g[j] += g[j - i]) %= mod;

    f[0][0] = 1;
    for(int i = 0;i <= n / B;i ++)
        for(int j = 0;j <= n;j ++) {
            if(i < n / B && j + B <= n) (f[i + 1][j + B] += f[i][j]) %= mod;
            if(i && j + i <= n) (f[i][j + i] += f[i][j]) %= mod;
        }
    for(int i = 0;i <= n / B;i ++)
        for(int j = 0;j <= n;j ++)
            (h[j] += f[i][j]) %= mod;
    LL ans = 0;
    for(int i = 0;i <= n;i ++)
        (ans += 1ll * h[i] * g[n-i]) %= mod;
    return ans;
}

int main() {
    int n = read();
    cout << work(n) << endl;
    return 0;
}
/**
12 =
12
3+9
4+8
5+7
6+6
3+4+5
3+3+6
4+4+4
3+3+3+3

*/
