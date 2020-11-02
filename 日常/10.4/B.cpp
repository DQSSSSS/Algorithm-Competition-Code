#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2000010;
const LL INF = 1000000010;
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

pii l[SZ];

bool cmp(pii a,pii b)
{
    return (a.x + a.y) < (b.x + b.y);
}

pii fg(pii a,pii b)
{
    return make_pair(max(a.x,b.x),min(a.y,b.y));
}

int g[210][210],f[210][210];

int main()
{
    int n = read(),p = read();
    for(int i = 1;i <= n;i ++)
        l[i].x = read(),l[i].y = read();
    sort(l + 1,l + 1 + n,cmp);
    for(int i = 1;i <= n;i ++)
    {
        int ans = l[i].y - l[i].x;
        g[i][i] = ans;
        pii xd = l[i];
        for(int j = i - 1;j >= 1;j --)
        {
            xd = fg(l[j],xd);
            g[j][i] = max(0,xd.y - xd.x);
        }
    }

    /*for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= n;j ++)
            printf("%d ",g[i][j]);*/

    for(int i = 1;i <= n;i ++) f[i][0] = f[0][i] = -INF;

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= min(p,i);j ++)
            for(int k = 0;k < i;k ++)
                if(g[k + 1][i])
                    f[i][j] = max(f[i][j],f[k][j - 1] + g[k + 1][i]);


    /*for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= p;j ++)
            printf("%d ",f[i][j]);*/
    printf("%d",f[n][p]);
    return 0;
}
