#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;
const int SZ = 1e5 + 10;

int a[SZ];
double sum[SZ],sum2[SZ];

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		k = n - k;
		for(int i = 1;i <= n;i ++) {
			scanf("%d",&a[i]);
		}
		sort(a + 1,a + 1 + n);
		for(int i = 1;i <= n;i ++) {
			sum[i] = sum[i - 1] + a[i];
			sum2[i] = sum2[i - 1] + 1ll * a[i] * a[i];
		}
		double ans = 1e100;
		for(int i = 1;i + k - 1 <= n;i ++) {
			int r = i + k - 1,l = i;
//			double ave = (sum[r] - sum[l - 1]) / k;
			double tmp2 = (sum2[r] - sum2[l - 1]) / k;
			double tmp1 = (sum[r] - sum[l - 1]) / k;
			tmp1 *= tmp1;
//			cout << tmp1 << " " << tmp2 << endl;
			ans = min(ans,tmp2 - tmp1);
		}
		printf("%.10f\n",k*ans);
	}
	return 0;
}
