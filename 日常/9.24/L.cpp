#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 200010;
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

LL a[SZ],val[SZ],f[SZ];

LL get_val(LL &x)
{
    if(x < 0) return 0;
    if(x >= 10000) { x -= 10000; return 5; }
    return 1;
}

int main()
{
    int n = 1;
    while(cin >> a[n]) val[n] = get_val(a[n]),n ++;
    n --;
//    memset(f,63,sizeof(f));
    LL ans = 0;
    for(int i = 1;i <= n;i ++) printf("%4d",a[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%4d",val[i]); puts("");
    for(int i = 1;i <= n;i ++)
    {
        f[i] = val[i];
        for(int j = 1;j < i;j ++)
        {
            if(a[j] <= a[i])
                f[i] = max(f[i],f[j] + val[i]);
        }
        ans = max(ans,f[i]);
    }
    printf("%lld",ans);
    return 0;
}
