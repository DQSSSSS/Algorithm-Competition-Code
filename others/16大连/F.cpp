#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;
const int mod = 1e9 + 7;

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a *ans %mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

LL cj[SZ],sum[SZ];

int main() {
	//pcout << pow(2e9,0.5) << endl;
	cj[0] = 1;
	for(int i = 1;i <= 1e5;i ++) cj[i] = 1ll * cj[i - 1] * i % mod;
	sum[1] = 0;
 	for(int i = 2;i <= 50000;i ++) sum[i] = sum[i - 1] + i;
 	//for(int i = 1;i <= 10;i ++) cout << sum[i] << " "; puts("");
 	//for(int i = 1;i <= 10;i ++) cout << cj[i] << " "; puts("");
	int T;
	scanf("%d",&T);
	while(T --) {
		int n;
		scanf("%d",&n);
		if(n == 1) { puts("1"); continue; }
		if(n == 2) { puts("2"); continue; }
		if(n == 3) { puts("3"); continue; }
		if(n == 4) { puts("4"); continue; }
		int pos = lower_bound(sum + 1,sum + 1 + 50000,n) - sum;
		if(n == sum[pos]) {
			printf("%lld\n",cj[pos]);
		}
		else {
			LL rst = n - sum[pos - 1];
			//cout << sum[pos] << " " << sum[pos - 1] << endl;
			///cout << pos << " " << rst << endl;
			//cout << cj[pos] << " " << pos - rst << endl;
			assert(pos - rst >= 1);
			if(pos - rst == 1) {
				LL ans = cj[pos] * ksm(2,mod - 2) % mod * (pos + 1) % mod * ksm(pos,mod - 2) % mod;
				printf("%lld\n",ans);			
			}
			else {
				LL ans = 1ll * cj[pos] * ksm(pos - rst,mod - 2) % mod;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
