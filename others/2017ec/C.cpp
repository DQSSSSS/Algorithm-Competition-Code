#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;


int main() {
	int T,cc = 0;
	scanf("%d",&T);
	while(T --) {
		int n;
		scanf("%d",&n);
		double ans = 0;
		for(int i = 1;i <= n +1;i ++) {
			double x;
			scanf("%lf",&x);
			ans += x;
		}
		double maxb = 0;
		for(int i = 1;i <= n;i ++) {
			double a,b;
			scanf("%lf%lf",&a,&b);
			maxb = max(maxb,b);
		}
		ans += maxb;
		printf("Case #%d: %.10f\n",++ cc,ans);
	}
}
