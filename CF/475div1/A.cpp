#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 9;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

LL ksm(LL a,LL b)
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

char s[SZ];

int main()
{
	LL n,a,b,k;
	cin >> n >> a >> b >> k;
	LL ni2 = ksm(a,mod - 2),qq = b * ksm(a,mod - 2) % mod;
	scanf("%s",s);
	LL d = 0;
	for(LL i = 0,dd = ksm(a,n);i < min(n + 1,k);i ++)
	{
		if(s[i] == '-') (d -= dd) %= mod;
		else (d += dd) %= mod;
		(dd *= qq) %= mod;
	}

	LL m = (n + 1) / k;
	LL q = ksm(qq,k),ans = 0;
	if(q == 1)
		ans = m * d % mod;
	else
		ans = d * (ksm(q,m) - 1) % mod * ksm(q - 1,mod - 2) % mod;

	cout << (ans % mod + mod) % mod << endl;
	return 0;
}
/*
5 2 3 4
+-+-
4 1 5 1
-

*/
