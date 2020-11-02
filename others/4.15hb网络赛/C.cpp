#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

LL ksm(LL a,LL b)
{
	LL ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a %mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	LL n;
	while(cin >> n)
	{
		cout << n * (n - 1) % mod * ksm(4,1e9+5) % mod << endl;
	}
	return 0;
}


