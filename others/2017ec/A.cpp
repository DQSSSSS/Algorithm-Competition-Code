#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;
const int mod = 1000000007;

LL inv[SZ];

LL ksm(LL a,LL b){
	LL ans = 1;
	while(b){
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

LL x[100];
int main() {
	//inv[1] = 1;
	//for(int i = 2;i <= 1e5;i ++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	//inv[0] = 1;
	//for(int i = 1;i <= 1e5;i ++) (inv[i] *= inv[i - 1]) %= mod;
	int T,cc = 0;
	scanf("%d",&T);
	while(T --) {
		for(int i=1;i<=5;i++) scanf("%lld",&x[i]);
		
		int n,k;
		scanf("%d",&n);
		//LL ans = ksm(2,n) - 1,t = 1;
		LL ans=0;
		//cout << ans << endl;
		//for(int i = 1;i < k;i ++) {	
		//	(t *= n - i + 1) %= mod;
		//	(ans -= t * inv[i] % mod) %= mod;
		//	cout << n - i << " " << i << endl;
		//}
		//ans += mod; ans %= mod;
		for(int i=1;i<=n;i++){
			int a; scanf("%d",&a);
			if (a<=48) ans+=x[1];
			else if (a<=56) ans+=x[2];
			else if (a<=60) ans+=x[3];
			else if (a<=62) ans+=x[4];
			else ans+=x[5];
		}
		printf("Case #%d: %lld\n",++ cc,ans*10000);
	}
	return 0;
}
