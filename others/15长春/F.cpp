#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e5 + 10;

int n,a[SZ],f[SZ];

bool check() {
	for(int i = 1;i <= n;i ++) f[i] = 1e9;
	for(int i = 1;i <= n;i ++) {
		*upper_bound(f + 1,f + 1 + n,a[i]) = a[i];
	}
	int len = lower_bound(f + 1,f + 1 + n,1e9) - f - 1;
	if(len >= n - 1) return true;
	
	for(int i = 1;i <= n;i ++) f[i] = 1e9;
	for(int i = n;i >= 1;i --) {
		*upper_bound(f + 1,f + 1 + n,a[i]) = a[i];
	}
	len = lower_bound(f + 1,f + 1 + n,1e9) - f - 1;
	if(len >= n - 1) return true;
	return false;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		puts(check() ? "YES" : "NO");		
	}
	return 0;
}
