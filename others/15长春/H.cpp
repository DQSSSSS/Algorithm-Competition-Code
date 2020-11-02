#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e5 + 10;

int a[SZ],f[SZ],n;

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		scanf("%d",&n);
		for(int i = 1;i <= n - 1;i ++)
			scanf("%d",&a[i]);
		for(int i = 0;i <= n - 2;i ++) f[i] = 0;
		f[0] = a[1] * n;
		
		for(int i = 0;i < n - 1;i ++) {
			for(int j = i;j <= n - 2;j ++)
				f[j] = max(f[j], f[j - i] + a[i + 1] - a[1]);
				//f[j] = max(f[j],f[j - (i - 1)] + a[i]);
			//for(int j = 0;j <= n - 2;j ++) cout << f[j] << " "; puts("");
		}
		//int ans = 0;
		//for(int i = 
		printf("%d\n",f[n - 2]);
	}
	return 0;
}

