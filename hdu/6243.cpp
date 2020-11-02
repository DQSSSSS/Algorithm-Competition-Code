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
		int n = read();
		printf("Case #%d: %d.0000000000\n",++ cc,n - 1);
	}
	return 0;
}
