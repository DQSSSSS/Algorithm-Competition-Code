#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

LL f[22][22][11],base[22];

void init()
{
    base[0] = 1;
    for(int i = 1;i <= 15;i ++) base[i] = base[i - 1] * 10;
    for(int i = 0;i <= 9;i ++) f[1][i][i] = 1;
    for(int len = 2;len <= 15;len ++)
        for(int i = 0;i <= 9;i ++)
            for(int j = 0;j <= 9;j ++)
            {
                for(int k = 0;k <= 9;k ++)
                    f[len][i][k] += f[len - 1][j][k];
                f[len][i][i] += base[len - 2];
            }
}

int bits[22];

int get(LL x)
{
    if(x == 0) { bits[0] = 0; return 1; }
    int len = 0;
    while(x) bits[++ len] = x % 10,x /= 10;
    return len;
}

void ask(LL ans[],LL x)
{
    if(x == 0) { ans[0] = 1; return ; }
    int len = get(x);
    for(int i = 1;i < len;i ++)
        for(int j = 1;j <= 9;j ++)
            for(int x = 0;x <= 9;x ++)
                ans[x] += f[i][j][x];
    ans[0] ++;
    for(int i = 1;i < bits[len];i ++)
        for(int x = 0;x <= 9;x ++)
            ans[x] += f[len][i][x];
    x %= base[len - 1];
    ans[bits[len]] += x + 1;
    for(int i = len - 1;i >= 1;i --)
    {
        for(int j = 0;j < bits[i];j ++)
            for(int x = 0;x <= 9;x ++)
                ans[x] += f[i][j][x];
        x %= base[i - 1]; ans[bits[i]] += x + 1;
    }
}

LL ans1[22],ans2[22];

int main()
{
    init();
    LL a = read(),b = read();
    ask(ans1,b); ask(ans2,a - 1);
    //for(int i = 0;i <= 9;i ++) printf("%lld ",ans1[i]); puts("");
    //for(int i = 0;i <= 9;i ++) printf("%lld ",ans2[i]); puts("");
    for(int i = 0;i <= 9;i ++) printf("%lld%c",ans1[i] - ans2[i],i == 9 ? '\n' : ' ');
    return 0;
}
