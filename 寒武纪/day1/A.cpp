#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int n,m;

LL ksm(LL a,int b)
{
	LL ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

LL fac[SZ];

int main()
{
	fac[0] = 1;
	for(int i = 1;i <= 2e5;i ++) fac[i] = fac[i - 1] * i % mod;
	int T = read();
	while(T --)
	{
		int t = read(),p = read();
		LL ans = 0;
		for(int a = 0;a <= max(p,t);a ++)
		{
			if((t - a + p) % 2) continue;
			int b = (t - a + p) / 2;
			int c = (t - a - p) / 2;
			if(b < 0 || c < 0) continue;
			(ans += ksm(ksm(2,2 * t - a),mod - 2) * ksm((LL)fac[a] * fac[b] % mod * fac[c] % mod,mod - 2) % mod) %= mod;
		//	cout << ksm(4,mod - 2) << endl;
		}
		printf("%lld\n",ans * fac[t] % mod);
	}
	return 0;
}
