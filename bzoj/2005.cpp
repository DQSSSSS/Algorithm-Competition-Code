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
int pri[SZ],phi[SZ];

void init()
{
    phi[1] = 1;
    for(int i = 2,tot = 0;i <= 100000;i ++)
    {
        if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= 100000;j ++)
        {
            vis[m] = 1;
            if(i % pri[j] == 0) { phi[m] = pri[j] * phi[i]; break; }
            else phi[m] = phi[i] * phi[pri[j]];
        }
    }
    for(int i = 1;i <= 100000;i ++) phi[i] += phi[i - 1];
}

LL ask(int n,int m)
{
    LL ans = 0;
    for(int i = 1,r;i <= min(n,m);i = r + 1)
    {
        r = min(n / (n / i),m / (m / i));
        ans += ((LL)phi[r] - phi[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}

int main()
{
    init();
    int n = read(),m = read();
    printf("%lld\n",2 * ask(n,m) - n * m);
    return 0;
}
