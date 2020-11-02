#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 3000010;
const LL INF = 1e17 + 10;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

LL f[SZ],a[SZ];
LL sum[SZ];

int main()
{
	int n = read(),len = 0,now = 0;
	for(int i = 1;i <= n;i ++)
	{
		int opt = read();
		if(opt == 2)
		{
			long double ans = a[len] - ((long double)sum[now] + a[len]) / (now + 1);
			printf("%.8f\n",(double)ans);
		}
		else
		{
			len ++;
			LL x = read();
			a[len] = x;
			sum[len] = sum[len - 1] + x;
			f[len] = sum[len - 1] - x * len;
			//cout << now << " " << f[now + 1] <<endl;
			while(now < len && x + f[now + 1] >= 0) now ++; 
		}
	}
	return 0;
}
