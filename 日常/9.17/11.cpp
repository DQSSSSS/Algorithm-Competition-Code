#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
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

LL lf(LL x)
{
    return x * x * x;
}
LL biao[SZ];

bool check(LL x)
{
    for(int i = 2;i <= 600000;i ++)
        if(biao[i] == x) return true;
    return false;
}


int main()
{
    for(LL i = 2,x;i <= 600000;i ++)
        biao[i] = lf(i) - lf(i - 1);
    int T = read();
    while(T --)
    {
        LL n = read();
        if(check(n)) puts("YES");
        else puts("NO");
    }
    return 0;
}
