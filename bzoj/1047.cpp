#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1010;
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

int n,m,k;
int ma[SZ][SZ],mb[SZ][SZ],mp[SZ][SZ],Sa[SZ],Sb[SZ];
int a[SZ],b[SZ];

int main()
{
    n = read(),m = read(),k = read();
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            mp[i][j] = read();
    for(int i = 1;i <= n;i ++)
    {
        int la = 1,ra = 0,lb = 1,rb = 0,*x = mp[i];
        for(int j = 1;j <= m;j ++)
        {
            while(la <= ra && x[Sa[ra]] <= x[j]) ra --;
            Sa[++ ra] = j;
            while(la <= ra && j - k >= Sa[la]) la ++;
            ma[i][j] = x[Sa[la]]; //max

            while(lb <= rb && x[Sb[rb]] >= x[j]) rb --;
            Sb[++ rb] = j;
            while(lb <= rb && j - k >= Sb[lb]) lb ++;
            mb[i][j] = x[Sb[lb]]; //min
        }
    }
/*
    for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= m;j ++)
            printf("%4d",ma[i][j]); puts("");
    for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= m;j ++)
            printf("%4d",mb[i][j]); puts("");
*/
    int ans = INF;
    for(int j = k;j <= m;j ++)
    {
        for(int i = 1;i <= n;i ++) a[i] = ma[i][j],b[i] = mb[i][j];
        int la = 1,ra = 0,lb = 1,rb = 0;
        for(int i = 1;i <= n;i ++)
        {
            int maxn,minn;
            while(la <= ra && a[Sa[ra]] <= a[i]) ra --;
            Sa[++ ra] = i;
            while(la <= ra && i - k >= Sa[la]) la ++;
            maxn = a[Sa[la]];

            while(lb <= rb && b[Sb[rb]] >= b[i]) rb --;
            Sb[++ rb] = i;
            while(lb <= rb && i - k >= Sb[lb]) lb ++;
            minn = b[Sb[lb]];

            if(i >= k) ans = min(ans,maxn - minn);
        }
    }

    printf("%d\n",ans);
    return 0;
}
