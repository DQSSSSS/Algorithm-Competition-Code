#include<bits/stdc++.h>
using namespace std;

const int SZ = 100010;
const int INF = 1000000010;
const int MOD = 1000000007;


int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
		int n;
		scanf("%d",&n);
		if(n % 3 == 0)
			printf("%lld\n",1ll * n * n * n / 27);
		else if(n % 4 == 0)
			printf("%lld\n",1ll * n * n * n / 32);
		else
			puts("-1");
	}
	return 0;
}
