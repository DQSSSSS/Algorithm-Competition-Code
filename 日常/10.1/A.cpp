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
int pre[SZ],nxt[SZ];

int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        scanf("%s",s + 1);
        for(int i = 1,pos = 0;i <= n;i ++)
            if(s[i] == '1')
                pre[i] = pos,pos = i;
        for(int i = n,pos = n + 1;i >= 1;i --)
            if(s[i] == '1')
                nxt[i] = pos,pos = i;
        LL ans = 0,L = 0,R = 0;
        for(int i = 1,r = 1;i <= n;i ++,r ++)
            if(s[i] == '1')
            {
                LL d = i - pre[i] - 1;
                ans =
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
