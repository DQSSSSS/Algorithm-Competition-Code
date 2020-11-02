#include<cstdio>
#include<cstring>
using namespace std;
#define     I64     long long

int i,j,k,l,n,m,a[55],p;
I64 f[55][5],x,y,ans;

inline  I64     Dfs(int k,int lim,int pp,int qq)
{
    I64 tmp=0;
    int pos;
    if (k==0)
	{
		if (qq==1){return 1;}
			else return 0;
	}
    if (lim==1) pos=a[k];else pos=9;
    if (lim==0) if (f[k][pp]>0&&f[k][pp^1]>0) return qq?f[k][0]+f[k][1]:f[k][pp];
    for (int i=0;i<=pos;i++)
    {
        if (i!=pos||lim==0)
        {
            if (qq==0) tmp+=Dfs(k-1,0,i%2,1);
            else if (pp==i%2) tmp+=Dfs(k-1,0,i%2,0);
        }
        else if (qq==0) tmp+=Dfs(k-1,1,i%2,1);
            else if (pp==i%2) tmp+=Dfs(k-1,1,i%2,1);
        if (i!=pos||lim==0) f[k][i%2]+=tmp;
    }
    return tmp;
}

inline  I64     Ask(I64 z)
{
    I64 tmp=0;
    memset(f,0,sizeof(f));
    if (z==0) return 0;
    for (p=0;z;z/=10) a[++p]=z%10;
    tmp=Dfs(p,1,0,0);
    return tmp;
}

int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%lld%lld",&x,&y);
        ans=Ask(y)-Ask(x-1);
        printf("Case# %d: %lld\n",i,ans);
    }
}
