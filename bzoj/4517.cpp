#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

LL fac[SZ],inv[SZ],f[SZ];

LL C(LL n,LL m)
{
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
    inv[1000000] = 397802501; fac[0] = 1; f[0] = 1; f[1] = 0;
    for(int i = 1e6 - 1;i >= 0;i --) inv[i] = inv[i + 1] * (i + 1) % mod;
    for(int i = 1;i <= 1e6;i ++) fac[i] = fac[i - 1] * i % mod;
    for(int i = 2;i <= 1e6;i ++) f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod;
    int T = read();
    while(T --)
    {
        LL n = read(),m = read();
        printf("%lld\n",C(n,m) * f[n - m] % mod);
    }
    return 0;
}
