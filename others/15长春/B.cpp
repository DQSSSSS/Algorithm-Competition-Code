#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int SZ = 1e5 + 10;

int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
			vis[m] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

ULL bl(ULL n) {
	ULL ans = 0;
	for(ULL m = 1;m <= n;m ++) {
		if(n % m == 0) {
			ans += m * m - n;
		}
	}
	return ans;
}

int main() {
	shai(1e5);
	int T;
	scanf("%d",&T);
	while(T --) {
		int n; scanf("%d",&n);
		ULL ans1 = 1,ans2 = 1,nn = n;
		for(int i = 1;;i ++) {
			ULL p = pri[i];
			if(p * p > n) break;
			if(n % p) continue;
			ULL t1 = 1,t2 = 0,pp = p * p;
			while(n % p == 0) {
				n /= p,t2 ++;
				t1 += pp; pp *= p * p;
				//cout << n << " " << t1 << endl;
			}
			//cout << p << " " << t1 << " " << t2 << endl;
			ans1 *= t1;
			ans2 *= t2 + 1;
		}
		if(n != 1) {
			ans1 *= (1 + 1ll * n * n);
			ans2 *= 2;
		}
		//cout << ans1 << " " << ans2 << endl;
		printf("%llu\n",ans1 - nn * ans2);
	//	printf("%llu\n",bl(nn));
	}
	return 0;
}
