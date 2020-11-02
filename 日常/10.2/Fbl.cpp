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

int a[SZ],tmp[SZ],n,m;

int main()
{
    while(~scanf("%d%d",&n,&m) && n)
    {
        for(int i = 1;i <= n;i ++)
            a[i] = read();
        for(int i = 1;i <= m;i ++)
        {
            int l = read(),r = read();
            for(int j = l;j <= r;j ++)
                a[j] ++;
            for(int j = 1;j <= n;j ++)
                tmp[j] = a[j];
            sort(tmp + 1,tmp + 1 + n);
            printf("%d\n",tmp[n / 2 + 1]);
        }
    }
    return 0;
}
