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
const LL INF = 5e18;
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

LL L[SZ],R[SZ],a[SZ];

int main()
{
    int n = read();
    LL p = read(),q = read(),r = read();
    for(int i = 0;i <= n + 1;i ++) L[i] = R[i] = -INF;
    for(int i = 1;i <= n;i ++)
        a[i] = read();
    for(int i = 1;i <= n;i ++) L[i] = max(L[i - 1],a[i] * p);
    for(int i = n;i >= 1;i --) R[i] = max(R[i + 1],a[i] * r);
    LL ans = -INF;
//    for(int i = 1;i <= n;i ++) cout << L[i] << " "; puts("");
//    for(int i = 1;i <= n;i ++) cout << R[i] << " "; puts("");
    for(int i = 1;i <= n;i ++)
        ans = max(ans,L[i] + a[i] * q + R[i]);
    printf("%I64d",ans);
    return 0;
}
