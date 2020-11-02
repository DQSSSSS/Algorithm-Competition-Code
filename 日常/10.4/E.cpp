#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
#define     N       50005

int i,j,k,l,n,m,Son[N],Link[N],Next[N],Find[N],used[N],Len,t,girl[N],all;
long long x[N],y[N],Data[N],xx;
map <long long,int> Map;

bool find(int x){
    int i,j;
    for (j=Son[x];j;j=Next[j]){
        if (used[Link[j]]==false)
        {
            used[Link[j]]=1;
            if (girl[Link[j]]==0 || find(girl[Link[j]])) {
                girl[Link[j]]=x;Find[x]=Link[j];
                return true;
            }
        }
    }
    return false;
}

inline  void    Add(int x,long long y)
{
    Next[++Len]=Son[x];
    Son[x]=Len;
    if (Map[y]==0)
    {
        Map[y]=++t;
        Data[t]=y;
    }
    Link[Len]=Map[y];
}

int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&x[i],&y[i]);
        Add(i,x[i]+y[i]);
        Add(i,x[i]*y[i]);
        Add(i,x[i]-y[i]);
    }
    for (i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if (find(i)) all+=1;
    }
    if (all<n)
    {
        puts("impossible");
        return 0;
    }
    for (i=1;i<=n;i++)
    {
        xx=Data[Find[i]];
        if (x[i]+y[i]==xx)
        {
            printf("%I64d + %I64d = %I64d\n",x[i],y[i],xx);
            continue;
        }
        if (x[i]-y[i]==xx)
        {
            printf("%I64d - %I64d = %I64d\n",x[i],y[i],xx);
            continue;
        }
        if (x[i]*y[i]==xx)
        {
            printf("%I64d * %I64d = %I64d\n",x[i],y[i],xx);
            continue;
        }
    }
}
