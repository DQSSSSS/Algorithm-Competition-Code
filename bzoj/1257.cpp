#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int main()
{
    LL n = read(),k = read();
    LL ans = k * n;
    for(LL i = 1,r;i <= n;i = r + 1)
    {
        LL d = k / i;
        if(d == 0) break;
        r = min(k / d,n);
        ans -= d * (r - i + 1) * (i + r) / 2;
    }
    printf("%lld\n",ans);
    return 0;
}
// k - (k/i) * i
