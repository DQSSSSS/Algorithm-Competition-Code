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


int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        int x = read();
        for(int j = 0;j <= 255;j ++)
            if(((j ^ (j << 1)) & 255) == x)
            {
                printf("%d ",j);
                break;
            }
    }
    return 0;
}
