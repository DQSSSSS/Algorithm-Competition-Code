#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
const int SZ = 1e5 + 10;

int a[SZ];
LL b[SZ][25][2];

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
		for(int i = 0;i <= 22;i ++)
			b[0][i][0] = 1,b[0][i][1] = 0;
		for(int i = 1,x = 0;i <= n;i ++) {
			x ^= a[i];
			for(int j = 0;j <= 22;j ++) {
					b[i][j][0] = b[i - 1][j][0];
					b[i][j][1] = b[i - 1][j][1];
				b[i][j][x >> j & 1] ++;
			}
		}
		for(;q --;) {
			int l,r;
			scanf("%d%d",&l,&r);
			l --;
			LL ans = 0;
			for(int i = 0;i <= 22;i ++) {
				LL x0,x1;
				if(l == 0) x0 = b[r][i][0],x1 = b[r][i][1];
				else {
					x0 = b[r][i][0] - b[l - 1][i][0];
					x1 = b[r][i][1] - b[l - 1][i][1];
				}
				//cout << x0 << " " << x1 << " "<< i << endl;
				(ans += (1 << i) * x0 % mod * x1 % mod) %= mod;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/**
1
3 1
1 2 3
1 3
*/
