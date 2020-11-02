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

int h[233];

int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        int x = read();
        h[x] ++;
    }
    int x = -1,y = -1,t = 0;
    for(int i = 1;i <= 100;i ++)
        if(h[i])
        {
            t ++;
            if(x == -1) x = i;
            else y = i;
        }
    if(t != 2 || h[x] != h[y]) puts("NO");
    else puts("YES"),printf("%d %d",x,y);

    return 0;
}
