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
//maxx��������Ҫ��ѯ��ֵ��Ҳ��������Ҫ��ѯ�ıȸ�ֵб�ʴ��б�ʵ�¥����
{
    if(ma[k]<=maxx)
    {
        return 0;
    }//��������������б�ʱ�ĿǰҪ��ѯ��ֵ����ô��Ȼ�Դ𰸲�����Ӱ�죬���Է���0
    if(l==r)
    {
        return ma[k]>maxx;
    }//�����Ҷ�ӽڵ㣬��ô����õ��б�ʴ���Ҫ��ѯ��ֵ�ͷ���1�����򷵻�0
    else if(ma[ls]<=maxx)
    {
        return query(rs,((l+r)>>1)+1,r,maxx);
    }//�������ӵ����ֵС�ڵ��ڲ�ѯֵ���͵ݹ��Ҷ���
    return query(ls,l,(l+r)>>1,maxx)+ans[k]-ans[ls];//����ݹ������
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
    //Ŀǰ��������ֵ��Ȼ��������������ֵ�����ֵ
    ans[k]=ans[ls]+query(rs,mid+1,r,ma[ls]);
    //������Ĵ���������Ĵ𰸼����������б�ʴ������������ֵ������¥��
}
int main()
{
    freopen("4198.in","r",stdin); freopen("std.out","w",stdout);
    n=read(),m=read();
    for(re int i=1,l,r;i<=m;++i)
    {
        l=read(),r=read();
        change(1,1,n,l,(D)r/l);//ע��б��Ҫ��double
        printf("%d\n",ans[1]);
    }
    return 0;
}
