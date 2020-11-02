#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;
const int MOD = 1000000007;

LL a[SZ];

LL f(LL x) {
	if(x <= 1e6) return a[x];
    return f(x - f(x - 1)) + f(x - 1 - f(x - 2));
}

int main() {

	for(int i = 0;i < 100;i ++)


    int T;
    scanf("%d",&T);
    while(T --) {
		LL n;
		scanf("%lld",&n);
        printf("%lld\n",f(n));
    }
	return 0;
}
//1 2 3 4 1
//1 2 3 1 4


