#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int INF = 1000000010;
const LL mod = 1024 * 8;
const double eps = 1e-7;

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
    int n = 0,h = 0;
    char s[20];
    while(scanf("%s",s) && s[1] != 'N')
    {
        n ++;
        for(int i = 7;i >= 0;i --)
        {
            
        }
    }
    return 0;
}
