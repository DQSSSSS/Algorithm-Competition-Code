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
const int SZ = 1000010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};


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

LL pf(LL x) { return x * x; }

int main()
{
    for(LL i = 1;i <= 1000;i ++)
        for(LL j = i;j <= 1000;j ++)
            for(LL k = j;k <= 1000;k ++)
                if(pf(i)+pf(j)+pf(k)==5*(i*j+j*k+k*i)+1)
                    printf("%lld %lld %lld\n",i,j,k);
    return 0;
}
