#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
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

LL a[SZ],val[SZ],f[SZ],num[SZ];

LL get_val(LL &x)
{
    if(x < 0) return 0;
    if(x >= 10000) { x -= 10000; return 5; }
    return 1;
}

int main()
{
    int nn = 1;
    while(~scanf("%lld",&num[nn])) nn ++;
    nn --;
    int n = 0;
    for(int i = 1;i <= nn;i ++)
    {
        int x = get_val(num[i]);
        while(x --) a[++ n] = num[i];
    }
//    for(int i = 1;i <= n;i ++) printf("%4d",a[i]); puts("");
    for(int i = 1;i <= n;i ++) f[i] = INF;
    for(int i = 1;i <= n;i ++)
    {
        *upper_bound(f + 1,f + 1 + n,a[i]) = a[i];
    }
    printf("%d",lower_bound(f + 1,f + 1 + n,INF) - f - 1);
    return 0;
}
