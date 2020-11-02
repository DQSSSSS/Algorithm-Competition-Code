#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 15000005

#define ls tree[t].l
#define rs tree[t].r
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,q,l[N],r[N],sx,sy,ex,ey,root,tot,ans,A0;

vector<pair<int,int> >add[N],del[N];

struct Node{
		int l,r,sum1,sum2,rev,sum0;
}tree[M];

#define Mo 998244353

int Work1(int l,int r)
{
		return 1ll*(l+r)*(r-l+1)/2%Mo;
}

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
			  if (y&1) sum=1ll*sum*x%Mo;
			  x=1ll*x*x%Mo;
		}
		return sum;
}

int inv6=power(6,Mo-2);

int W(int x)
{
		return 1ll*x*(x+1)%Mo*(2*x+1)%Mo*inv6%Mo;
}

int Work2(int l,int r)
{
		return (W(r)-W(l-1)+Mo)%Mo;
}

int Work0(int l,int r)
{
		return r-l+1;
}

int A1,A2;

void Up(int t,int l,int r)
{
		if (tree[t].rev)
		{
				tree[t].sum1=tree[t].sum2=tree[t].sum0=0;
				return;
		}
		if (l==r) tree[t].sum0=Work0(l,r),tree[t].sum1=Work1(l,r),tree[t].sum2=Work2(l,r);
		else
		{
				tree[t].sum1=tree[t].sum2=tree[t].sum0=0;
				if (ls) (tree[t].sum1+=tree[ls].sum1)%=Mo,(tree[t].sum2+=tree[ls].sum2)%=Mo,tree[t].sum0+=tree[ls].sum0;
				else 	(tree[t].sum1+=Work1(l,mid))%=Mo,(tree[t].sum2+=Work2(l,mid))%=Mo,tree[t].sum0+=Work0(l,mid);
				if (rs) (tree[t].sum1+=tree[rs].sum1)%=Mo,(tree[t].sum2+=tree[rs].sum2)%=Mo,tree[t].sum0+=tree[rs].sum0;
				else 	(tree[t].sum1+=Work1(mid+1,r))%=Mo,(tree[t].sum2+=Work2(mid+1,r))%=Mo,tree[t].sum0+=Work0(mid+1,r);
		}
}

int Cover(int ll,int rr,int c,int l,int r,int t)
{
		if (ll<=l&&r<=rr)
		{
				tree[t].rev+=c;
				Up(t,l,r);
		}
		else
		{
				if (ll<=mid)
				{
					if (!ls) ls=++tot,Up(tot,l,mid);
					Cover(ll,rr,c,l,mid,ls);
				}
				if (rr>mid)
				{
					if (!rs) rs=++tot,Up(tot,mid+1,r);
					Cover(ll,rr,c,mid+1,r,rs);
				}
				Up(t,l,r);
		}
}

void Ask(int ll,int rr,int l,int r,int t)
{
		if (tree[t].rev) return;
		if (ll<=l&&r<=rr)
		{
				if (t) (A1+=tree[t].sum1)%=Mo,(A2+=tree[t].sum2)%=Mo,(A0+=tree[t].sum0);
				else   (A1+=Work1(l,r))%=Mo,(A2+=Work2(l,r))%=Mo,(A0+=Work0(l,r));
		}
		else
		{
				if (ll<=mid) Ask(ll,rr,l,mid,ls);
				if (rr>mid)  Ask(ll,rr,mid+1,r,rs);
		}
}

int Work()
{
		int temp=r[i]-l[i]+1,Chu=power(1ll*temp*(temp+1)/2%Mo,Mo-2);
		temp=(((Mo-A2)%Mo+1ll*(l[i]+r[i])*A1%Mo)%Mo-1ll*A0*(l[i]-1)%Mo*(r[i]+1)%Mo+Mo)%Mo;
		return 1ll*temp*Chu%Mo;
}

int main()
{
    freopen("H.in","r",stdin);
    freopen("std.out","w",stdout);
		scanf("%d%d%d",&n,&m,&q);
		for (i=1;i<=n;++i) scanf("%d%d",&l[i],&r[i]);
		for (i=1;i<=q;++i)
		{
				scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
				add[sx].pb(mk(sy,ey));
				del[ex].pb(mk(sy,ey));
		}
		root=tot=1;
		tree[1].sum1=Work1(1,m);
		tree[1].sum2=Work2(1,m);
		for (i=1;i<=n;++i)
		{
				 for (j=0;j<(int)add[i].size();++j)
				 			Cover(add[i][j].fi,add[i][j].se,1,1,m,1);
				 A1=A2=A0=0;
				 Ask(l[i],r[i],1,m,1);
				 (ans+=Work())%=Mo;
				 for (j=0;j<(int)del[i].size();++j)
				 			Cover(del[i][j].fi,del[i][j].se,-1,1,m,1);
		}
		printf("%d\n",(ans+Mo)%Mo);
}
