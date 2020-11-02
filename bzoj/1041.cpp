#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int SZ = 1000010;
const int INF = 1e7 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,k,a[SZ],L[SZ],R[SZ];

int main()
{
    n = read(),k = read();
    int pos;
    for(int i = 1;i <= n;i ++)
    {
        int x = read();
        if(x == k) a[i] = 0,pos = i;
        else if(x < k) a[i] = -1;
        else a[i] = 1;
    }
    for(int i = pos,sum = 0;i >= 1;i --)
        sum += a[i],L[sum + n] ++;
    for(int i = pos,sum = 0;i <= n;i ++)
        sum += a[i],R[sum + n] ++;
    LL ans = (LL)L[n] * R[n];
    for(int i = 1;i <= n;i ++)
        ans += (LL)L[n + i] * R[n - i] + (LL)L[n - i] * R[n + i];
    printf("%lld\n",ans);
    return 0;
}
/*
1 1 -1 0 -1 -1 1

   -1  0  1
    1  2  1
-2 -1  0
 1  2  1
*/
