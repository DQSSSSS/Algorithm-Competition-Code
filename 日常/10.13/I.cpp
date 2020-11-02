#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define     N       305

int i,j,k,l,n,m,T,Gcd[N][N];
long long ans[N],f[N][N],a[N],b[N];

inline long long gcd(long long a,long long b) { return b == 0 ? a : gcd(b,a % b); }

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (i=1;i<=n;i++) scanf("%lld",&b[i]);
        memset(f,0,sizeof(f));
        memset(ans,0,sizeof(ans));
        for (i=1;i<=n;i++)
            for (j=i+1;j<=n;j++) Gcd[i][j]=gcd(a[i],a[j]);
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                for (k=j+1;k<=n;k++) if (Gcd[j][k]>1) if (j+1<k-1){ if (f[j+1][k-1]>0) f[j][k]=f[j+1][k-1]+(long long)b[j]+(long long)b[k];}
                    else if (j+1==k) f[j][k]=(long long)b[j]+(long long)b[k];
        for (i=1;i<=n;i++)
            for (j=i+1;j<=n;j++)
            {
                ans[j]=max(ans[i-1]+f[i][j],ans[j]);
                for (k=j+1;k<=n;k++) ans[k]=max(ans[k],ans[j]);
            }
        printf("%lld\n",ans[n]);
    }
}
