#include <bits/stdc++.h>
#define maxn 1000010
#define rep(i,x,y) for(int i=x;i<(y);i++)
using namespace std;
#define mod 1000000007
typedef long long ll;
ll powmod(ll a,ll b) {
	ll res=1LL;
	while(b) {
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1LL;
	}
	return res;
}
namespace linear_seq {
	const int N=10010;
	ll res[N],base[N],_c[N],_md[N];
	vector<int>Md;
	void mul(ll *a,ll *b,int k) {
		rep(i,0,k+k) _c[i]=0;
		rep(i,0,k) if(a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
		for(int i=k+k-1;i>=k;i--) if(_c[i])
			rep(j,0,Md.size()) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
			rep(i,0,k) a[i]=_c[i];
	}
	int solve(ll n,vector<int> a,vector<int> b) {
		ll ans=0,pnt=0;
		int k=a.size();
		rep(i,0,k) _md[k-1-i]=-a[i];_md[k]=1;
		Md.clear();
		rep(i,0,k) if(_md[i]!=0) Md.push_back(i);
		rep(i,0,k) res[i]=base[i]=0;
		res[0]=1;
		while((1LL<<pnt)<=n) pnt++;
		for(int p=pnt;p>=0;p--) {
			mul(res,res,k);
			if((n>>p)&1) {
				for(int i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
				rep(j,0,Md.size()) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
			}
		}
		rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
		if(ans<0) ans+=mod;
		return ans;
	}
	vector<int> BM(vector<int> s){
		vector<int> C(1,1),B(1,1);
		int L=0,m=1,b=1;
		rep(n,0,s.size()) {
			ll d=0;
			rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
			if(d==0) ++m;
			else if(2*L<=n) {
				vector<int> T=C;
				ll c=mod-powmod(b,mod-2)*d%mod;
				while(C.size()<B.size()+m) C.push_back(0);
				rep(i,0,B.size()) C[i+m]=(C[i+m]+c*B[i])%mod;
				L=n+1-L;B=T;b=d;m=1;
			}
			else {
				ll c=mod-d*powmod(b,mod-2)%mod;
				while(C.size()<B.size()+m) C.push_back(0);
				rep(i,0,B.size()) C[i+m]=(C[i+m]+c*B[i])%mod;
				++m;
			}
		}
		return C;
	}
	int gao(vector<int> a, ll n) {
		vector<int>c= BM(a);
		c.erase(c.begin());
		rep(i,0,c.size()) c[i]=(mod-c[i])%mod;
		return solve(n,c,vector<int>(a.begin(),a.begin()+c.size()));
	}
}

int main()
{	
	/*while(cin>>n){
	ans=100000000;
	dfs(1);
	cout<<ans<<endl;
	}*/
	/*int ans=0;
	for(int i=1;i<1000;i++){
//		if ((i%111)==0) continue;
		int a=i/100;
		int b=i/10%10;
		int c=i%10;
		//cout<<a<<' '<<b<<' '<<c<<endl;
		if (a <= b && b<=c && !(a == b && b == c)) ans++,cout << i << endl;
	}
	cout<<ans<<endl;*/
	/*for(ll n = 2,y = 100;n <= 10;n ++,y *= 10)
	{
		ll ans = 0;
		for(ll i = 1;i < y;i ++)
		{
			bool flag = 0;
			ll x = i;
			for(ll j = 1;j < n;j ++)
				if((x *= 10) % y <= i) flag = 1;
			if(!flag) ans ++; //cout << i << endl;
		}
		cout << n << " " << ans * n << endl;
	}*/
	vector<int>vec;vec.clear();
	vec.push_back(45);
	vec.push_back(330);
	vec.push_back(2475);
	vec.push_back(19998);
	vec.push_back(166485);
	vec.push_back(1428570);
	vec.push_back(12498750);
	int ans=linear_seq::gao(vec,6);
	printf("%d\n",ans);
	return 0;
}

