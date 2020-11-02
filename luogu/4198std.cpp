#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define re register
#define il inline
#define inf 123456789
#define debug printf("Now is %d\n",__LINE__);
using namespace std;
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
#define D double
#define maxn 100005
int n,m,ans[maxn<<2];
D ma[maxn<<2];
#define ls k<<1
#define rs k<<1|1
#define max(a,b) a>b?a:b
il int query(int k,int l,int r,D maxx)
//maxx表是我们要查询的值，也就是我们要查询的比该值斜率大的斜率的楼房数
{
    if(ma[k]<=maxx)
    {
        return 0;
    }//如果这段区间的最大斜率比目前要查询的值大，那么显然对答案不会有影响，所以返回0
    if(l==r)
    {
        return ma[k]>maxx;
    }//如果是叶子节点，那么如果该点的斜率大于要查询的值就返回1，否则返回0
    else if(ma[ls]<=maxx)
    {
        return query(rs,((l+r)>>1)+1,r,maxx);
    }//如果左儿子的最大值小于等于查询值，就递归右儿子
    return query(ls,l,(l+r)>>1,maxx)+ans[k]-ans[ls];//否则递归左儿子
}
il void change(int k,int l,int r,int ll,D v)
{
    if(l==ll&&r==ll)
    {
        ans[k]=1,ma[k]=v;
        return;
    }
    re int mid=(l+r)>>1;
    if(ll<=mid) change(ls,l,mid,ll,v);
    else change(rs,mid+1,r,ll,v);
    ma[k]=max(ma[ls],ma[rs]);
    //目前区间的最大值显然是左右区间的最大值的最大值
    ans[k]=ans[ls]+query(rs,mid+1,r,ma[ls]);
    //该区间的答案是左区间的答案加上右区间的斜率大于左区间最大值的所有楼房
}
int main()
{
    freopen("4198.in","r",stdin); freopen("std.out","w",stdout);
    n=read(),m=read();
    for(re int i=1,l,r;i<=m;++i)
    {
        l=read(),r=read();
        change(1,1,n,l,(D)r/l);//注意斜率要用double
        printf("%d\n",ans[1]);
    }
    return 0;
}
