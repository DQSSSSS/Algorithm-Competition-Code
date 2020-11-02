#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const int mod = 1e9 + 7;

LL fac[SZ],inv[SZ],f[SZ];

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

LL C(LL n,LL m)
{
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fac[0] = 1;
	for(int i = 1;i <= 1e6;i ++) fac[i] = fac[i - 1] * i % mod;
	inv[1000000] = ksm(fac[1000000],mod - 2);
	for(int i = 1e6 - 1;i >= 0;i --) inv[i] = inv[i + 1] * (i + 1) % mod;
	f[0] = 1;
	for(int i = 1;i <= m;i ++)
	{
		f[i] = f[i - 1] * i % mod;
	}
	LL ans = f[m];
	for(int i = 1;i <= m;i ++)
		cout << f[i] <<endl;
	if(m & 1) ans = ans * m % mod;
	ans = ans * C(n,m) % mod;
	cout <<ans <<endl;
	return 0;
}

