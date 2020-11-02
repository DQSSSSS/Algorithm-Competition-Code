#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
const int mod = 1e9 + 7;
const LD pi = acos(-1);

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

LD R,r,L;

LD pf(LD x) { return x * x; }

LD get1(LD x)
{
	return r * r * asin(x / r) + x * sqrt(pf(r) - pf(x));
}

LD get2(LD x)
{
	return R * R * asin(x / R) + x * sqrt(pf(R) - pf(x));
}

int main()
{
	int RR,rr,LL;
	while(cin >> RR >> rr >> LL)
	{		
		R = RR,r = rr,L = LL;
		LD ans1 = 4 * pi * (pf(R) + pf(r));
		LD ans2 = pi * (get1(r) - get1((r + L - R) / 2));
		LD ans3 = pi * (get2(R) - get2((R + L - r) / 2));
		cout << (double)(ans1 - ans2 - ans3) <<endl;
	}
	return 0;
}



