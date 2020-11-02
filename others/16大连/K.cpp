#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int SZ = 5e6 + 10;
const int mod = 100000073;

int f[SZ];
LL tim[SZ];

int main() {
	f[1] = 1; tim[1] = 1; tim[0] = 1;
	int l = 0,r = 1,sum = 2;
	for(int i = 2,ans = 2,t = 1;i <= 5e6;i ++) {
		if(t == ans + 1) {
			ans ++; t = 1;
			l = r = i - 1; sum = tim[i - 1];
			while(f[l] == ans - 1) (sum += tim[-- l]) %= mod;
		}		
		t ++;
		f[i] = ans; tim[i] = (sum + mod) % mod;
		(sum -= tim[l]) %= mod; l ++;
	}
	while(~scanf("%d%d",&l,&r)) printf("%d %lld\n",f[r-l+1],tim[r-l+1]);
	return 0;
}
