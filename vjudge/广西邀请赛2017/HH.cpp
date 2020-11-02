#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<string>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXM=100010;
const long long MOD=1000000007;
const double PI=acos(-1);

long long n,a;

long long qpow(long long x,long long y,long long mod)
{
    long long res=1;
    while(y)
    {
        if (y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y=y>>1;
    }
    return res;
}
long long qpow(long long x,long long y)
{
    long long res=1;
    while(y)
    {
        if (y&1) res=res*x;
        x=x*x;
        y=y>>1;
    }
    return res;
}
int main()
{
    while(scanf("%lld%lld",&n,&a)!=EOF)
    {
        if (a&1)
        {
            printf("1\n");
            continue;
        }
        else
        {
            long long m=1<<n;
            long long ans=0;
            for (long long i=1;i<=n;i++)
                if (qpow(a,i,m)==qpow(i,a,m))
                ans++;
            long long b2=n/a;
            if (b2*a<n) b2=b2+1;
            long long b3=qpow(2,b2);
            //int b4=qpow(2,a);
            long long res=m/b3-n/b3;
            ans=ans+res;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
