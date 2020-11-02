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

int g[SZ][SZ],sum[SZ][SZ],n,m,p;

int work(int x,int y)
{
	int xx = g[x][y];
	g[x][y] = p;
	int ans = -INF;
	for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        	sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i][j];
	for(int a = 1;a <= n;a ++)
		for(int b = 1;b <= m;b ++)
			for(int i = a;i <= n;i ++)
				for(int j = b;j <= m;j ++)
					ans = max(ans,sum[i][j] - sum[a - 1][j] - sum[i][b - 1] + sum[a - 1][b - 1]);
	g[x][y] = xx;
	return ans;
}

int main()
{
	freopen("3.in","r",stdin); freopen("std.out","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                g[i][j] = read();
        int ans = -INF;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				ans = max(ans,work(i,j));
        printf("%d\n",ans);
    }
}
