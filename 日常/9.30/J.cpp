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

LL ni = 500000004;

int main()
{
    int n = read();
    LL t = 0,t2 = 0;
    for(int i = 1;i <= n;i ++)
    {
        int x = read();
        t += x - 1;
        if(x == 3) t2 ++;
    }
    if(t != n - 2) { puts("0"); return 0; }
    LL ans = 1;
    for(int i = 1;i <= n - 2;i ++)
        ans = ans * i % mod;
    for(int i = 1;i <= t2;i ++)
        ans = ans * ni % mod;
    printf("%I64d\n",ans);
    return 0;
}
