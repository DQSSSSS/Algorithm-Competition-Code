#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 510;
const int INF = 1000000010;

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

const int pri[233] = {2,3,5,7,11,13,17,19}; //8
const int MAXC = (1 << 8) - 1;

struct haha
{
    int p,s;
}l[SZ];

bool cmp(haha a,haha b) { return a.p < b.p; }

void calc(int x)
{
    int xx = x;
    for(int i = 0;i < 8;i ++)
    {
        while(x % pri[i] == 0)
            x /= pri[i],l[xx].s |= 1 << i;
    }
    l[xx].p = x;
}

LL f[SZ][SZ];
LL dp[SZ][SZ][2];

int main()
{
    int n = read();
    LL p = read();
    for(int i = 2;i <= n;i ++)
        calc(i);
    sort(l + 2,l + 1 + n,cmp);

    f[0][0] = 1;
    for(int i = 2;i <= n;i ++)
    {
        if(i == 2 || l[i].p == 1 ||  l[i].p != l[i - 1].p)
        {
            for(int x = 0;x <= MAXC;x ++)
                for(int y = 0;y <= MAXC;y ++)
                    dp[x][y][0] = dp[x][y][1] = f[x][y];
        }
        for(int x = MAXC;x >= 0;x --)
            for(int y = MAXC;y >= 0;y --)
            {
                if(((x | l[i].s) & y) == 0)
                    (dp[x | l[i].s][y][0] += dp[x][y][0]) %= p;
                if((x & (y | l[i].s)) == 0)
                    (dp[x][y | l[i].s][1] += dp[x][y][1]) %= p;
            }
        if(i == n || l[i].p == 1 || l[i].p != l[i + 1].p)
        {
            for(int x = 0;x <= MAXC;x ++)
                for(int y = 0;y <= MAXC;y ++)
                    (f[x][y] = dp[x][y][0] + dp[x][y][1] - f[x][y] + p) %= p;
        }
    }
    LL ans = 0;
    for(int x = 0;x <= MAXC;x ++)
        for(int y = 0;y <= MAXC;y ++)
            if((x & y) == 0)
                (ans += f[x][y]) %= p;
    printf("%lld\n",ans);
    return 0;
}
