#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> abcd;
ll P,n,m,a[20],ans;
struct prime_factor{
	ll p,a,p_a,left;
}prime[50];int tot;
void Decomposition(ll x)
{
	ll i;
	for(i=2;i*i<=x;i++)
		if(x%i==0)
		{
			prime[++tot].p=i;
			prime[tot].p_a=1;
			while(x%i==0)
				x/=i,prime[tot].a++,prime[tot].p_a*=i;
		}
	if(x!=1)
		prime[++tot].p=x,prime[tot].a=1,prime[tot].p_a=x;
}
ll Quick_Power(ll x,ll y,ll mo)
{
	ll re=1;
	while(y)
	{
		if(y&1)re*=x,re%=mo;
		x*=x,x%=mo;
		y>>=1;
	}
	return re;
}
abcd Deal(ll x,int pos)
{
	//cout << x << " " << pos <<endl;
	ll i;
	abcd re=make_pair( 1ll , x/prime[pos].p );
	for(i=1;i<prime[pos].p_a;i++)
		if(i%prime[pos].p)
			re.first*=i,re.first%=prime[pos].p_a;
	re.first=Quick_Power(re.first,x/prime[pos].p_a,prime[pos].p_a);
	for(i=x-x%prime[pos].p_a+1;i<=x;i++)
		if(i%prime[pos].p)
			re.first*=i,re.first%=prime[pos].p_a;
	if(re.second)
	{
		abcd temp=Deal(re.second,pos);
		re.first*=temp.first;
		re.first%=prime[pos].p_a;
		re.second+=temp.second;
	}
	return re;
}
abcd EXGCD(ll x,ll y)
{
	if(!y)
		return make_pair(1,0);
	abcd temp=EXGCD(y,x%y);
	return make_pair(temp.second,temp.first-x/y*temp.second);
}
ll Reverse(ll x,ll p)
{
	ll re=EXGCD(x,p).first;
	re=(re%p+p)%p;
	return re;
}
void Chinese_Remainder_Theorem()
{
	int i;
	//for(i=1;i<=tot;i++) cout << prime[i].p_a << " " << prime[i].left << endl;
	for(i=1;i<=tot;i++)
	{
		abcd temp=EXGCD(P/prime[i].p_a,prime[i].p_a);
		ll x=temp.first;x=(x%P+P)%P;
		ans+=x*P/prime[i].p_a*prime[i].left;
		ans%=P;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("std.txt","w",stdout);
	int i,j;
	ll sum=0;
	cin>>P>>n>>m;
	for(i=1;i<=m;i++)
		cin>>a[i],sum+=a[i];
	if(sum>n)
	{
		puts("Impossible");
		return 0;
	}
	if(sum<n)
		a[++m]=n-sum;
	Decomposition(P);
	for(i=1;i<=tot;i++)
	{
		abcd temp=Deal(n,i);
		//cout << "n : " << temp.first << " " << temp.second << endl;
		for(j=1;j<=m;j++)
		{
			abcd _temp=Deal(a[j],i);
		//	cout << "wi : " << _temp.first << " " << _temp.second << endl;
			temp.second-=_temp.second;
			temp.first*=Reverse(_temp.first,prime[i].p_a);
			temp.first%=prime[i].p_a;
		}
		//cout << temp.first << " " << temp.second << endl;
		temp.first*=Quick_Power(prime[i].p,temp.second,prime[i].p_a);
		prime[i].left=temp.first%prime[i].p_a;
	}
	Chinese_Remainder_Theorem();
	cout<<(ans%P+P)%P<<endl;
}

