#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'0');
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
const int N=1<<18,D=998244353;
s64 mi(s64 x,int y=D-2,int p=D)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%p;
		x=x*x%p;y>>=1;
	}
	return ans;
}
s64 a[N],b[N],a1[N];
namespace NTT
{
s64 w[N];
int rev[N];
void ntt(s64 a[],int n,int flag)
{
	rep(i,1,n-1)rev[i]=rev[i/2]/2+i%2*n/2;
	rep(i,0,n-1)
	if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1)
	{
		s64 wn=mi(3,(D-1)/(2*i)*flag+D-1);
		w[0]=1;
		rep(k,1,i-1)w[k]=w[k-1]*wn%D;
		for(int j=0;j<n;j+=i*2)
		{
			s64 *a1=a+j,*a2=a1+i;
			rep(k,0,i-1)
			{
				s64 x=a1[k],y=a2[k]*w[k];
				a1[k]=(x+y)%D;
				a2[k]=(x-y)%D;
			}
		}
	}
	if(flag==-1)
	{
		s64 niv_n=mi(n);
		rep(i,0,n-1)a[i]=a[i]*niv_n%D;
	}
}
};
using NTT::ntt;
struct Poly
{
vector<s64>a;
void set(int n)
{
	a.resize(n+1);
}
Poly (int n=-1)
{
	set(n);
}
int size()const
{
	return int(a.size())-1;
}
s64& operator [](int i)
{
	return a[i];
}
const s64& operator [](int i)const
{
	return a[i];
}
};
Poly operator *(const Poly &A,const Poly &B)
{
	int n=1;
	while(n<=A.size()+B.size())n*=2;
	rep(i,0,n-1)a[i]=b[i]=0;
	rep(i,0,A.size())a[i]=A[i];
	rep(i,0,B.size())b[i]=B[i];
	ntt(a,n,1);ntt(b,n,1);
	rep(i,0,n-1)a[i]=a[i]*b[i]%D;
	ntt(a,n,-1);
	Poly ans(A.size()+B.size());
	rep(i,0,ans.size())ans[i]=a[i];
	return ans;
}
Poly operator -(Poly A,const Poly &B)
{
	if(A.size()<B.size())A.set(B.size());
	rep(i,0,B.size())(A[i]-=B[i])%=D;
	return A;
}
Poly rev(const Poly &A)
{
	Poly B=A;
	reverse(B.a.begin(),B.a.end());
	return B;
}
Poly niv(const Poly &A,int n0)
{
//	assert(A[0]!=0);
	int n=1;a1[0]=mi(A[0]);
//	if(A.size()==3&&n0==2)
//		int yyx=1;
	while(n<n0)
	{
		n*=2;
		rep(i,0,n*2-1)a[i]=b[i]=0;
		rep(i,0,min(n-1,A.size()))a[i]=A[i];
		rep(i,0,n/2-1)b[i]=a1[i];
		ntt(a,n*2,1);ntt(b,n*2,1);
		rep(i,0,n*2-1)a[i]=a[i]*b[i]%D*b[i]%D;
		ntt(a,n*2,-1);
		rep(i,0,n-1)a1[i]=(((i<n/2)?(2*a1[i]):0)-a[i])%D;
	}
	Poly ans(n0-1);
	rep(i,0,n0-1)ans[i]=a1[i];
/*	Poly tmp=ans*A;
	rep(i,1,n0-1)
	if(tmp[i]%D)
	{
		printf("%d %d\n",A.size(),n0);
		rep(i,0,A.size())printf("%d ",int(A[i]));puts("");
		rep(i,0,n0-1)printf("%d ",int(ans[i]));
		assert(0);
	}*/
	return ans;
}
pair<Poly,Poly> div(const Poly &A,const Poly &B)
{
	int n=A.size(),m=B.size();
	if(n<m)return {{},A};
	Poly _A=rev(A),_B=niv(rev(B),n-m+1);
	_A.set(n-m);
	Poly Q=_A*_B;
	Q.set(n-m);
	Q=rev(Q);
	Poly R=A-Q*B;
	R.set(m-1);
	return {Q,R};
}
Poly operator %(const Poly &a,const Poly &b)
{
	return div(a,b).second;
}
Poly ln(const Poly &A,int n)
{
	Poly B=A;
	rep(i,0,B.size()-1)B[i]=B[i+1]*(i+1)%D;
	B.a.pop_back();
	B=B*niv(A,n);
	B.set(n-1);
	per(i,n-1,1)B[i]=B[i-1]*mi(i)%D;
	B[0]=0;
	return B;
}
Poly exp(const Poly &A,int n0)
{
	int n=1;
	Poly B(0);
	B[0]=1;
	while(n<n0)
	{
		n*=2;
		Poly _A(n-1);
		rep(i,0,n-1)_A[i]=(i<=A.size())?A[i]:0;
		++_A[0];
		B=B*(_A-ln(B,n));
		B.set(n-1);
	}
	B.set(n0-1);
	return B;
}
int bsgs(s64 a,s64 b)//a^x=b,return x
{
	static const int L=30000;
	unordered_map<s64,int>mp;
	b=(b%D+D)%D;
	rep(k,1,L)
	{
		b=b*a%D;
		mp[b]=k;
	}
	s64 w=mi(a,L),x=1;
	for(int k=1;;++k)
	{
		x=x*w%D;
		if(mp.count(x))return k*L-mp[x];
	}
}
void exgcd(int a,int &x,int b,int &y)//ax+by=1
{
	if(!b)
	{
		x=1;y=0;
		return ;
	}
	exgcd(b,y,a%b,x);
	y-=a/b*x;
}
int niv(int x,int p)//x^-1 mod p
{
	int _x,y;
	exgcd(x,_x,p,y);
	return _x;
}
int jie(int k,int b,int p)//kx=b(mod p)
{
	b=(b%p+p)%p;
	int d=__gcd(k,p);
	k/=d;p/=d;b/=d;
	return (s64(b)*niv(k,p)%p+p)%p;
}
s64 sqrt(int x,int k)//x^{1/k}
{
	x=bsgs(3,x);
	int y = jie(k,x,D-1);
	cout << x << " "<< y << " " << mi(3,y) << " " << k << endl;
	return mi(3,y);
}
Poly sqrt(Poly A)
{
	int n=A.size();
	s64 c=A[0];
	s64 niv_c=mi(c);
	rep(i,0,n)A[i]=A[i]*niv_c%D;

	A=ln(A,n+1);
	s64 niv_2=mi(2);
	rep(i,0,n)A[i]=A[i]*niv_2%D;
	A=exp(A,n+1);

	c=sqrt(c,2);
	c=min(c,(D-c)%D);
	cout << c << endl;
	rep(i,0,n)A[i]=A[i]*c%D;
	return A;
}
Poly pow(Poly A,int k)//A^k
{
	int n=A.size();
	A=ln(A,n+1);
	rep(i,0,n)A[i]=A[i]*k%D;
	A=exp(A,n+1);
	return A;
}

int main()
{

   // freopen("150.in","r",stdin);
 //   freopen("std.out","w",stdout);
	int n=read(),k=read();
	Poly A(n);
	rep(i,0,n)A[i]=read();

	Poly B=sqrt(A);
	rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D); puts("");
	B=niv(B,n+1);
	rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D); puts("");
	per(i,n,1)B[i]=B[i-1]*mi(i)%D;
	B[0]=0;
	rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D); puts("");

	B=exp(B,n+1);
	rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D); puts("");
	B=A-B;
	B[0]=1;
    rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D); puts("");

	B=ln(B,n+1);
	++B[0];
	rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D); puts("");
	B=pow(B,k);
	rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D); puts("");
	rep(i,0,n-1)B[i]=B[i+1]*(i+1)%D;
	rep(i,0,n-1)printf("%d ",int(B[i]%D+D)%D);
}
/**

1 499122181 124780535 935854125 912457489 315852238 43858315
1 499122172 623902750 311951143 850069141 276843411 968132982
0 1 249561086 540715701 327548874 768960440 545262745
1 1 748683263 956650846 753882411 601546474 72743546
1 8 249561092 41593513 244361942 396697887 925500808
1 8 249561060 707089889 941052536 997728473 931628962
1 154086536 894879441 967971876 448610157 227932347 185853080
154086536 791514529 907426922 796196275 141417382 116874127 473725705

496491309 342956475 527999560 244343968 372099966 384318834 478714861 534025842 182300987 931922721
247406891 290063595 450792046 371779198 416626811 518580243 615359442 285621481 765676412 805222415
0 247406891 644153974 483012133 592066976 682271974 585552217 373121164 909166494 639655353
1 247406891 227295155 19265447 356324098 935294297 637693187 110745139 86589499 537928669
1 334056214 8158698 529073334 721378832 924530759 351485710 691511976 878366880 217966734
1 334056214 222850677 256959378 93078129 537811191 137466712 896180041 307263795 69311369
1 88889702 221130001 70542877 913225455 707177503 265901571 944346769 345094461 41509797
88889702 442260002 211628631 658168761 541154456 597165073 620961265 764266982 373588173 546458969
*/
