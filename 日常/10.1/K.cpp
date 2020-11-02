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
int main()
{
    int T = read();
    while(T --)
    {
        LL a = read(),b = read(),n = read();
        int use[20] = {};
        for(LL x = 1,y;(y = a * x * x + b * x) <= n;x ++)
        {
            LL t[20] = {};
            while(y) t[y % 10] ++,y /= 10;
            LL maxc = 0;
            for(int i = 0;i <= 9;i ++) maxc = max(maxc,t[i]);
            for(int i = 0;i <= 9;i ++)
                if(t[i] == maxc) use[i] ++;
        }
        LL ans = 10,maxc = 0;
        for(int i = 0;i <= 9;i ++)
            if(use[i] > maxc)
                maxc = use[i],ans = i;
        if(ans == 10) puts("-1");
        else printf("%I64d\n",ans);
    }
    return 0;
}
