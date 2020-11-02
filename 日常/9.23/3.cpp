#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 310;
const int INF = 1000000010;
const LL mod = 1000000007;

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

int n,m,p;
int f[SZ][2],a[SZ],c[SZ];
int g[SZ][SZ],sum[SZ][SZ][SZ][2],s[SZ][SZ];

int main()
{
	//freopen("3.in","r",stdin); freopen("3.out","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        int xx = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
            {
                xx += g[i][j] = read();
                s[i][j] = g[i][j] + s[i - 1][j];
            }

        for(int i = 1;i <= m;i ++) sum[0][i][0][1] = -INF;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                for(int r = 1;r <= i;r ++)
                {
                    sum[i][j][r][0] = s[i][j] - s[i - r][j];
                    sum[i][j][r][1] = max(sum[i - 1][j][r - 1][1] + g[i][j],sum[i - 1][j][r - 1][0] + p);
                }
/*        for(int r = 1;r <= n;r ++)
        {
            cout << "r == " << r << endl;
            for(int i = r;i <= n;i ++,puts(""))
                for(int j = 1;j <= m;j ++)
                {
                    cout << sum[i][j][r][1] << " ";
                }
        }*/
        int ans = -INF;
        for(int i = 1;i <= n;i ++)
        {
            for(int r = 1;r <= i;r ++)
            {
                for(int j = 1;j <= m;j ++)
                {
                    a[j] = sum[i][j][r][0];
                    c[j] = sum[i][j][r][1];
                    f[j][0] = f[j][1] = -INF;
                }
                f[0][1] = -INF;
                f[0][0] = 0;

        /*        cout << r << " " << i << endl;
                for(int j = 1;j <= m;j ++) cout << a[j] << " "; puts("");
                for(int j = 1;j <= m;j ++) cout << c[j] << " "; puts("");
*/
                for(int j = 1;j <= m;j ++)
                {
                    f[j][0] = max(f[j - 1][0] + a[j],a[j]);
                    f[j][1] = max(max(f[j - 1][1] + a[j],f[j - 1][0] + c[j]),c[j]);
                }

            /*    for(int j = 1;j <= m;j ++) cout << f[j][0] << " "; puts("");
                for(int j = 1;j <= m;j ++) cout << f[j][1] << " "; puts("");
                puts("");*/

                for(int j = 1;j <= m;j ++)
                {
                    if(r < n) ans = max(ans,f[j][0]);
                    ans = max(ans,f[j][1]);
                }
            }
        }
        for(int i = 1;i <= m;i ++)
            for(int j = i;j <= m;j ++)
            {
                if(i == 1 && j == m) continue;
                int tmp = 0;
                for(int x = i;x <= j;x ++)
                    tmp += sum[n][x][n][0];
                ans = max(ans,tmp);
            }
        printf("%d\n",ans);
    }
    return 0;
}

/*
3 5 -5
-2 -1 -7 -3 6
3 -7 5 -5 5
-8 0 -3 -2 2

13

3 5 -9
10 -3 8 -4 9
5 4 -4 -4 7
-4 10 0 3 -8

28

*/
