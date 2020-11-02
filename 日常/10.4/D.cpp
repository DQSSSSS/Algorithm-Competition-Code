#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
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

LL r,p;

LL f[SZ];

LL dfs(LL x)
{
    if(x == 1) return 0;
    if(f[x]) return f[x];
    LL ans = 1e18;
    for(LL d = 2;d <= x;d ++)
    {
        LL k = x % d == 0 ? x / d : x / d + 1;
        ans = min(ans,dfs(k) + r + (d - 1) * p);
    }
    return f[x] = ans;
}

LL n;

int main()
{
    n = read(); r = read(); p = read();
    printf("%lld\n",dfs(n));
    return 0;
}
