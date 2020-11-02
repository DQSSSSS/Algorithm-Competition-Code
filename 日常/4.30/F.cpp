#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL ksm(LL a,LL b,LL p)
{
	LL ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	LL n,p,r;
	cin >> n >> p >> r;
	if(n >= 2 * p) 
	{
		if(r) puts("-1 -1");
		else
			puts("2 1");
	}
	else if(n >= p)
	{
		if(!r)
			for(LL k = 2;k <= n;k ++)
			{
				if(k != p)
				{
					cout << k << " " << k - 1;
					return 0;
				}
			}
		else
		{
			LL ans = 1;
			for(LL k = 2;k <= n;k ++) if(k != p) ans = ans * k % p;
			ans = ksm(ans,p - 2,p) * r % p;
			if(ans < p) { cout << p << " " << ans << endl; return 0; }
		}
		puts("-1 -1");
	}
	else
	{
		LL jc = 1;
		for(LL i = 1;i <= n;i ++) jc = jc * i % p;
		//cout << jc << endl;
		jc = ksm(jc,p - 2,p) * r % p;
		for(LL k = 2;k <= n;k ++)
		{
			LL x = jc * k % p;
			if(x < k && 1 <= x) { cout << k << " " << x << endl; return 0; }
		}
		puts("-1 -1");
	}
	return 0;
}
