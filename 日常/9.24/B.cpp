#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 2010;
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

LL sum[SZ];
int n;

int main()
{
    while(scanf("%d",&n) && n)
    {
        memset(sum,0,sizeof(sum));
        for(int i = 1;i <= n;i ++)
        {
            int l = read(),r = read();
            LL d = read();
            if(l > r) swap(l,r);
            for(int j = l;j <= r - 1;j ++) sum[j] += d;
        }
        LL ans = 0;
        for(int i = 1;i <= 100;i ++) ans = max(ans,sum[i]);
        printf("%lld\n",ans);
    }
    putchar('*');
    return 0;
}
