#include<cstdio>
#include<cstring>
using namespace std;

int a[1005],flag[1005],t,t1,qq,T,i,j,k,n;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a_.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        memset(flag,0,sizeof(flag));
        scanf("%d",&n);
        for (i=1;i<=n;i++) scanf("%d",&a[i]);
        t=n;
        for (;;)
        {
            t1=0;qq=0;
            for (i=1;i<=t;i++)
            {
                if (i!=1) if (a[i]<a[i-1]) flag[i]=1;
                if (i!=t) if (a[i]>a[i+1]) flag[i]=1;
            }
            for (i=1;i<=t;i++) if (flag[i]==0){a[++t1]=a[i];}else qq=1;
            t=t1;if (qq==0) break;
            memset(flag,0,sizeof(flag));
        }
        printf("%d\n",t);
        for (i=1;i<=t;i++) printf("%d ",a[i]);
        puts("");
    }
}
