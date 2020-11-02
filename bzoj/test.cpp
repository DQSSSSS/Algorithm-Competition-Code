#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL dp[12][1245][90];
int n,m;

int get(int x)
{
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        if(x&(1<<i)) ans++;
    }
    return ans;
}

bool check(int a)
{
    return (a&(a<<1));
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<=(1<<(n+1))-1;i++) dp[1][i][get(i)]=1;

    for(int i=2;i<=n;i++)//行
    {
        for(int a=0;a<=(1<<(n+1))-1;a++)//从a转移
        {
            for(int b=0;b<=(1<<(n+1))-1;b++)//到b
            {
                if( !(a&1) && !(b&1) && !(a&(b>>1)) && !(a&b) && !(a&(b<<1)) && !check(a) && !check(b)  )
                for(int j=0;j<=m-get(b);j++)
                {
                    dp[i][b][j+get(b)]+=dp[i-1][a][j];
                }
            }
        }
    }
    LL ans=0;
    for(int i=0;i<=(1<<(n+1))-1;i++)
        ans+=dp[n][i][m];
    printf("%lld",ans);
    return 0;
}
