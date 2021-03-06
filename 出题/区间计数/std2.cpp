#include<cstdio>
#include<algorithm>
#define mid (l+r)/2
#define lt (s<<1)
#define rt (s<<1|1)
#define Mn 300005
using namespace std;
long long ans;
int fc[Mn*4],fm[Mn*4],sm[Mn*4],sc[Mn*4];
int p[Mn],nt[Mn],add[Mn*4],n,i,k1,k2,x;

void updata(int s)
{
	int k1=lt,k2=rt;
	if (fm[k1]>fm[k2]) swap(k1,k2);
	if (fm[k1]<fm[k2])
		{
			fm[s]=fm[k1],fc[s]=fc[k1];
			if (sm[k1]<fm[k2])
				sm[s]=sm[k1],sc[s]=sc[k1];
			else
				if (sm[k1]==fm[k2])
					sm[s]=sm[k1],sc[s]=sc[k1]+fc[k2];
				else sm[s]=fm[k2],sc[s]=fc[k2];
		}
	if (fm[k1]==fm[k2])
		{
			fm[s]=fm[k1],fc[s]=fc[k1]+fc[k2];
			if (sm[k1]<sm[k2])
				sm[s]=sm[k1],sc[s]=sc[k1];
			else
				if (sm[k2]<sm[k1])
					sm[s]=sm[k2],sc[s]=sc[k2];
				else sm[s]=sm[k2],sc[s]=sc[k1]+sc[k2];
		}
}
void plus(int s,int up)
{
	fm[s]+=up; sm[s]+=up;
	add[s]+=up;
}
void push(int s)
{
	if (add[s]!=0)
		plus(lt,add[s]),plus(rt,add[s]),add[s]=0;
}
void work(int s,int l,int r,int ls,int rs,int up)
{
	if (l>rs || r<ls) return;
	if (ls<=l && r<=rs)
		return(void)(plus(s,up));
	push(s);
	work(lt,l,mid,ls,rs,up);
	work(rt,mid+1,r,ls,rs,up);
	updata(s);
}
void build(int s,int l,int r)
{
	if (l==r) return(void)(fc[s]=1,sm[s]=1);
	build(lt,l,mid); build(rt,mid+1,r);
	updata(s);
}
void upans(int s,int l,int r,int ls,int rs)
{
	if (ls<=l && r<=rs)
		{
			if (fm[s]==1 || fm[s]==2) ans+=fc[s];
			if (sm[s]==1 || sm[s]==2) ans+=sc[s];
			return;
		}
	if (ls>r || l>rs) return;
	push(s);
	upans(lt,l,mid,ls,rs);
	upans(rt,mid+1,r,ls,rs);
	updata(s);
}
int main()
{
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]),nt[p[i]]=i;
	build(1,1,n);
	for(i=n;i>=1;i--)
		{
			x=nt[i];
			if (p[x+1]<i && p[x-1]<i) work(1,1,n,i,n,1);
			if (p[x+1]<i && p[x-1]>i) work(1,1,n,i,p[x-1]-1,1);
			if (p[x+1]>i && p[x-1]<i) work(1,1,n,i,p[x+1]-1,1);
			if (p[x+1]>i && p[x-1]>i)
				{
					k1=p[x+1]; k2=p[x-1];
					if (k1>k2) swap(k1,k1);
					work(1,1,n,i,k1-1,1);
					work(1,1,n,k2,n,-1);
				}
			upans(1,1,n,i,n);
		}
	printf("%lld",ans-n);
	return 0;
}
