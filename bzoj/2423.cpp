#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5010;
const int INF = 1e9 + 10;
const int mod = 1e8;

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

LL max(LL x,LL y) { return x < y ? y : x; }

char s1[SZ],s2[SZ];
int f[SZ][SZ],n,m;
LL cnt[2][SZ];

int main()
{
    scanf("%s%s",s1 + 1,s2 + 1);
    n = strlen(s1 + 1) - 1;
    m = strlen(s2 + 1) - 1;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(s1[i] == s2[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j],f[i][j - 1]);
    for(int i = 1;i <= n;i ++) cnt[i & 1][0] = 1;
    for(int i = 1;i <= m;i ++) cnt[0][i] = 1;

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            cnt[i & 1][j] = 0;
            if(s1[i] == s2[j])
            {
                cnt[i & 1][j] += cnt[i - 1 & 1][j - 1];
                if(f[i][j] == f[i - 1][j]) cnt[i & 1][j] += cnt[i - 1 & 1][j];
                if(f[i][j] == f[i][j - 1]) cnt[i & 1][j] += cnt[i & 1][j - 1];
                cnt[i & 1][j] %= mod;
            }
            else
            {
                if(f[i][j] == f[i - 1][j]) cnt[i & 1][j] += cnt[i - 1 & 1][j];
                if(f[i][j] == f[i][j - 1]) cnt[i & 1][j] += cnt[i & 1][j - 1];
                if(f[i][j] == f[i - 1][j - 1]) cnt[i & 1][j] -= cnt[i - 1 & 1][j - 1];
                cnt[i & 1][j] %= mod;
            }
        }
    printf("%d\n%lld",f[n][m],(cnt[n & 1][m] + mod) % mod);
    return 0;
}
