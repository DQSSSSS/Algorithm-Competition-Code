#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1010;

LL read()
{
    LL n = 0;
    scanf("%I64d",&n);
    return n;
}

bool check(int x)
{
    for(int i = 2;i <= sqrt(x);i ++)
        if(x % i == 0) return false;
    return true;
}

LL tmp[SZ][SZ][3],ans[SZ][SZ],pri[SZ],n;

bool check()
{
    for(int a = 1;a <= n;a ++)
        for(int b = 1;b <= n;b ++)
            for(int c = 1;c <= n;c ++)
                for(int d = 1;d <= n;d ++)
                    if((a != c || b != d) && ans[a][b] == ans[c][d])
                        return false;
    return true;
}


int main()
{
    freopen("elegant.in","r",stdin); freopen("elegant.out","w",stdout);
    srand(time(0));
    n = read();
    int tot = 0;
    for(int i = 1;i <= 2000;i ++)
        if(check(i)) pri[++ tot] = i;

    //for(int i = 1;i <= tot;i ++) printf("%I64d\n",pri[i]);

        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++)
                for(int k = 0;k < 3;k ++)
                    tmp[i][j][k] = 1;

    for(int d = 0;d < 3;d ++)
        for(int k = n * d + 1;k <= n * (d + 1);k ++)
        {
            LL x = pri[k];
            for(int i = 1,j = i + k - n * d - 1;i <= n;i ++,j --)
            {
                if(j == 0) j = n;
                tmp[i][j][d] *= x;
            }
        }
/*    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            printf("%4I64d%c",ans1[i][j],j == n ? '\n' : ' ');
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= n;j ++)
                    printf("%4I64d%c",ans2[i][j],j == n ? '\n' : ' ');
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            printf("%4I64d%c",ans[i][j] = ans1[i][j] * ans2[i][j],j == n ? '\n' : ' ');
*/
    while(!check())
    {
        int opt = rand() % 3;
        int x = rand() % n + 1,y = rand() % n + 1;
        for(int j = 1;j <= n;j ++) swap(tmp[x][j][opt],tmp[y][j][opt]);

        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++)
            {
                ans[i][j] = 1;
                for(int k = 0;k < 3;k ++)
                    ans[i][j] *= tmp[i][j][k];
            }
    }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            printf("%I64d%c",ans[i][j],j == n ? '\n' : ' ');
    return 0;
}
