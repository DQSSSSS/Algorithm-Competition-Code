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

LL gcd(LL a,LL b)
{
    return b == 0 ? a : gcd(b,a % b);
}

int main()
{
    for(LL i = 2;i <= 1000;i += 2)
    {
        LL x = 2 * i,y = i * i - 1,z = i * i + 1;
    /*    if(gcd(x,y) != 1) continue;
        if(gcd(y,z) != 1) continue;
        if(gcd(x,z) != 1) continue;*/
        printf("%lld %lld %lld\n",x,y,z);
    /*    for(LL k = 1;k <= 17;k ++)
            printf("%6lld",y % (1ll << k));*/
        printf("%lld\n",y % 4);
    //    puts("");
    }
}
