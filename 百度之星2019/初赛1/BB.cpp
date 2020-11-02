#include<bits/stdc++.h>
using namespace std;
#define        N        100005

int T,a[N],b[N],n;

int main()
{
    freopen("B.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        long long ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        int l=a[1],r=b[1];
        int j=n+1;
        int posl=0,posr=0;
        for (int i=2;i<=n;i++)
        {
            if (a[i]>r)
            {
                posl=r;
                posr=r;
                j=i;
                break;
            }
            if (b[i]<l)
            {
                posl=l;
                posr=l;
                j=i;
                break;
            }
            l=max(l,a[i]);
            r=min(r,b[i]);
        }
        for (int i=j;i<=n;i++)
        {

            if (posl<a[i]&&posr==a[i]) posl=posr;
            if (posr>b[i]&&posl==b[i]) posr=posl;
            if (posr<a[i])
            {
                ans+=(a[i]-posr+1)/2;
                if ((a[i]-posr)%2) posr=a[i]+1;
                else posr=a[i];
                posl=a[i];
            }
            if (posl>b[i])
            {
                ans+=(posl-b[i]+1)/2;
                if ((posl-b[i])%2) posl=b[i]-1;
                else posl=b[i];
                posr=b[i];
            }
            if (posl<a[i]&&posr==a[i]) posl=posr;
            if (posr>b[i]&&posl==b[i]) posr=posl;
        }
        printf("%I64d\n",ans);
    }
}
