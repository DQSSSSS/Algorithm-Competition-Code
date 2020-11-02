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

int a[SZ];

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
		int n = read(),q = read();
		printf("Case #%d:\n",++ cc);
		while(q --)
		{
			for(int i = 1;i <= n;i ++) a[i] = read();
			sort(a + 1,a + 1 + n);
			int ans = 2e9;
			for(int i = 2;i <= n;i ++)
				ans = min(ans,a[i] - a[i - 1]);
			printf("%.4f\n",ans * 1.0 / sqrt(2));
		}
	}
	return 0;
}
