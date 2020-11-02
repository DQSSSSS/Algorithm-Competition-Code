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
	while(a <= '9' && a >= '0') { n = n *10 +a - '0'; a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[SZ],tot = 0;

void get(LL n)
{
	tot = 0;
	LL x = n;
	for(int i = 2;i <= sqrt(n);i ++)
	{
		if(x % i == 0)
		{
			while(x % i == 0) x /= i;
			a[++ tot] = i;
		}
	}
	if(x > 1) a[++ tot] = x;
}

LL tmp[SZ];

LL ask(LL x)
{
	int t = 0;
	tmp[++ t] = -1;
	for(int i = 1;i <= tot;i ++)
	{
		LL d = a[i];
		int k = t;
		for(int j = 1;j <= k;j ++)
			tmp[++ t] = -d * tmp[j];
	}
	LL ans = 0;
	for(int i = 2;i <= t;i ++)
		ans += x / tmp[i];
	return ans;
}

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
		LL L = read(),R = read(),n = read();
		get(n);			
		LL x = R - ask(R),y = L - 1 - ask(L - 1);
		printf("Case #%d: %lld\n",++ cc,x - y);
	}
	return 0;
}


