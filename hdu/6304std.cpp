#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

//int a[101000];
int _;
ll n;
ll mul(ll a,ll b) {
	a%=mod; b%=mod;
//	printf("%lld %lld %lld %lld\n",a,b,c,d);
	return a*b%mod;
}


ll mul(ll a,ll b,ll c) {
	a%=mod; b%=mod; c%=mod;
//	printf("%lld %lld %lld %lld\n",a,b,c,d);
	return a*b%mod*c%mod;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lld",&n);
		ll l=0,r=n;
		while (l+1<r) {
			ll md=(l+r)>>1;
			if (2*md-__builtin_popcountll(md)<n) l=md; else r=md;
		}
		ll ans=(1+mul(n-1+n+1-2*r,r,(mod+1)/2))%mod;
		rep(i,0,61) {
			ll q=r/(1ll<<(i+1)),q2=r-(q<<(i+1));
			if (q2<(1ll<<i)) q2=0; else q2-=(1ll<<i);
			ans=(ans+mul(q,1ll<<i)+q2)%mod;
		}
/*		rep(k,0,r) {
			ans+=__builtin_popcount(k);
		}*/
		printf("%lld\n",ans);
	}
}
