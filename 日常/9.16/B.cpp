#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;
const LL mod = 1000000007;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

void exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b == 0)
    {
        x = 1; y = 0; return ;
    }
    exgcd(b,a % b,x,y);
    LL t = x; x = y; y = t - a / b * y;
}

LL ni(LL a)
{
    LL x,y;
    exgcd(a,mod,x,y);
    return (x % mod + mod) % mod;
}

LL ksm(LL a,LL b)
{
    a = (a % mod + mod) % mod;
    LL ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int T = read();
    while(T --)
    {
        LL p = read(),q = read(),k = read();
        LL A = q * ni(p) % mod;
        printf("%lld\n",(ksm(1 - 2 * A,k) + 1) * ni(2) % mod);
    }
    return 0;
}
//17 17 65 17 257 17 65 17 257 17 65 17 1025 17 65 17 257 17 65 17
//4  4  6  4
