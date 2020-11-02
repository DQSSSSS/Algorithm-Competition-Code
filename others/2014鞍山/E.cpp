#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;
const int SZ = 210;
int a[SZ][SZ],b[SZ],f[SZ][SZ];

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= m;i ++)
			for(int j = 1;j <= m;j ++)
				scanf("%d",&a[i][j]);
		for(int i = 1;i <= n;i ++) {
			scanf("%d",&b[i]);
		}
		for(int i = 0;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				f[i][j] = -INF;
		//f[0][0] = 0;
		for(int i = 1;i <= n;i ++) {
			if(b[i] != -1) {
				if(i == 1) f[i][b[i]] = 0;
				else 
					for(int j = 1;j <= m;j ++)
						f[i][b[i]] = max(f[i][b[i]],f[i - 1][j] + a[j][b[i]]);
			}
			else {
				if(i == 1)
					for(int j = 1;j <= m;j ++)
						f[i][j] = 0;
				else
					for(int j = 1;j <= m;j ++)
						for(int k = 1;k <= m;k ++)
							f[i][k] = max(f[i][k],f[i - 1][j] + a[j][k]);
			}
		}
		int ans = 0;
		for(int i = 1;i <= m;i ++) ans = max(ans,f[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
