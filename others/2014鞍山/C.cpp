#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 1e9 + 10;
const int SZ = 1e5 + 10;

int mu[SZ],pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
	mu[1] = 1;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
			vis[m] = 1;
			if(i % pri[j] == 0) {
				mu[m] = 0;
			}
			else mu[m] = -mu[i];
		}
	}
}

int a[SZ];
LL b[SZ];
vector<int> t[SZ];

int main() {
	shai(1e5);
	int T;
	scanf("%d",&T);
	while(T --) {
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= 1e5;i ++) t[i].clear();
		for(int i = 1;i <= n;i ++) {
			scanf("%d",&a[i]);
			t[a[i]].push_back(i);
			b[i] = 0;
		}
				
		for(int i = 1;i <= 1e5;i ++) {
			if(!mu[i]) continue;
			LL sum = 0;
			for(int j = i;j <= 1e5;j += i)
				sum += t[j].size();
			for(int j = i;j <= 1e5;j += i)
				for(int k = 0;k < t[j].size();k ++)
					b[t[j][k]] += mu[i] * (sum - t[j].size());
		}
		
	//	for(int i = 1;i <= n;i ++) cout << b[i] << " "; puts("");
		
		LL ans = 0;
		
		for(int i = 1;i <= n;i ++) {
			ans += 1ll * b[i] * (n - b[i] - 1);
		}
		ans /= 2;
		ans = 1ll * n * (n - 1) * (n - 2) / 6 - ans;
		printf("%lld\n",ans);
	}
	return 0;
}

