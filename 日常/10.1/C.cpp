#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
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

int n;

LL gcd(LL a,LL b)
{
    return b == 0 ? a : gcd(b,a % b);
}

int main()
{
    int T = read();
    while(T --)
    {
        scanf("%d",&n);
        LL sum = 0,ans = 0;
        for(int i = 1;i <= n;i ++)
        {
            LL x = read();
            sum += x;
            ans = gcd(ans,x);
        }
        printf("%I64d %I64d\n",sum,ans);
    }
    return 0;
}
