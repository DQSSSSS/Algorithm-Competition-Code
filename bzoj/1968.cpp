#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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

int d[SZ],pri[SZ],cnt[SZ];
bool vis[SZ];

void init()
{
    d[1] = 1;
    for(int i = 2,tot = 0;i <= 1e6;i ++)
    {
        if(!vis[i]) pri[++ tot] = i,d[i] = 2,cnt[i] = 1;
        for(int j = 1,m;(m = i * pri[j]) <= 1e6 && j <= tot;j ++)
        {
            vis[m] = 1;
            if(i % pri[j] == 0) { cnt[m] = cnt[i] + 1; d[m] = d[i] / (cnt[i] + 1) * (cnt[m] + 1); break; }
            else d[m] = d[i] * 2,cnt[m] = 1;
        }
    }
}

int main()
{
    init();
    int n = read();
    LL ans = 0;
    for(int i = 1;i <= n;i ++) ans += d[i];
    printf("%lld\n",ans);
    return 0;
}
