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
	while(a >= '0' && a <= '9') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

double f[SZ],fac[SZ];

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
		LL x = read(),y = read(),k = read(),ans = 0;
		if(x > y) ans = k;
		else
		{
			LL now = 0,a = 11 * y;
			for(int i = 1;i <= k;i ++)
			{
				if(now + 9 * x - 11 * y < 0) now += 11 * x;
				else ans ++,now -= 11 * y,now += 9 * x;
			}
		}
		printf("Case #%d: %d\n",++ cc,ans);
	}
	return 0;
}


