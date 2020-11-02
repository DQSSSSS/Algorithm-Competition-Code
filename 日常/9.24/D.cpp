#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int INF = 1000000010;
const LL mod = 1000000007;
const double eps = 1e-7;

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

double a,b;
int d[200][200],n,m;
double D[200][200];

double dfs(int i,int j)
{
    if(!(1 <= i && i <= n && 1 <= j && j <= m)) return INF;
    if(D[i][j]) return D[i][j];
    D[i][j] = min(dfs(i - 1,j - 1) + b * d[i][j],
                min(dfs(i - 2,j - 1) + a * (d[i - 1][j] + d[i][j]),
                    dfs(i - 1,j - 2) + a * (d[i][j - 1] + d[i][j])));
    return D[i][j];
}

int p[SZ][2],tot = 0;

void dfs_ans(int i,int j)
{
    if(i == 1 && j == 1) return ;
    if(abs(D[i][j] - (D[i - 1][j - 1] + b * d[i][j])) < eps)
        p[++ tot][0] = i - 1,p[tot][1] = j - 1,dfs_ans(i - 1,j - 1);
    else if(abs(D[i][j] - (D[i - 2][j - 1] + a * (d[i - 1][j] + d[i][j]))) < eps)
        p[++ tot][0] = i - 1,p[tot][1] = j,
        p[++ tot][0] = i - 2,p[tot][1] = j - 1,dfs_ans(i - 2,j - 1);
    else
        p[++ tot][0] = i,p[tot][1] = j - 1,
        p[++ tot][0] = i - 1,p[tot][1] = j - 2,dfs_ans(i - 1,j - 2);
}

int main()
{
    freopen("233.in","r",stdin);
    scanf("%lf%lf\n",&a,&b);

    n = 1,m = 1;
    int i = 1,j = 1;
    while(233)
    {
        char a = getchar();
        if(a == EOF) break;
        while(233)
        {
            int flag = 0;
            while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
            int y = 0;
            while(a >= '0' && a <= '9') y = y * 10 + a - '0',a = getchar();
            d[i][j ++] = y;
            if(a == '\n' || a == EOF) break;
        }
        n = max(n,i); m = max(j - 1,m);
        if(a == EOF) break;
        i ++; j = 1;
    }
    D[1][1] = 1;
    printf("%.6f\n",dfs(n,m));
    dfs_ans(n,m);
    for(int i = tot;i >= 1;i --)
        printf("(%d,%d)\n",p[i][1],p[i][0]);
    printf("(%d,%d)\n",m,n);
    return 0;
}
