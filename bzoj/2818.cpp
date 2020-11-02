#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 10000010;
const int INF = 1e9 + 10;
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

int n;
int pri[SZ],mu[SZ],tot = 0;
bool vis[SZ];

void init()
{
    mu[1] = 1;
    for(int i = 2;i <= n;i ++)
    {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m = pri[j] * i) <= n;j ++)
        {
            vis[m] = 1;
            if(i % pri[j] == 0) { mu[m] = 0; break; }
            else mu[m] = -mu[i];
        }
    }
    for(int i = 1;i <= n;i ++) mu[i] += mu[i - 1];
}

LL ask(int n)
{
    LL ans = 0;
    for(int i = 1,r;i <= n;i = r + 1)
    {
        LL w = min(n,n / i);
        r = n / w;
        ans += (mu[r] - mu[i - 1]) * w * w;
    }
    return ans;
}

int main()
{
    n = read();
    init();
    LL ans = 0;
    for(int i = 1;i <= tot && pri[i] <= n;i ++)
        ans += ask(n / pri[i]);
    printf("%lld\n",ans);
    return 0;
}
