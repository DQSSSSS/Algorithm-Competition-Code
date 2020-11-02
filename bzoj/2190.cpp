#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

bool vis[SZ];
int pri[SZ],mu[SZ];

void init()
{
    mu[1] = 1;
    for(int i = 2,tot = 0;i <= 50000;i ++)
    {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= 50000;j ++)
        {
            vis[m] = 1;
            if(i % pri[j] == 0) { mu[m] = 0; break; }
            else mu[m] = -mu[i];
        }
    }
    for(int i = 1;i <= 50000;i ++) mu[i] += mu[i - 1];
}

LL ask(int n,int m)
{
    LL ans = 0;
    for(int i = 1,r;i <= min(n,m);i = r + 1)
    {
        r = min(n / (n / i),m / (m / i));
        ans += ((LL)mu[r] - mu[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}

int main()
{
    init();
    int n = read();
    printf("%lld\n",ask(n-1,n-1) + 2);
    return 0;
}
