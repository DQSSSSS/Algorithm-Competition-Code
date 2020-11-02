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

LL kll[SZ],a[SZ],f[110][20010];

int main()
{
	LL n = read(),g = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	LL m = 0;
	while(233)
	{
		m ++;
		kll[m] = g;
		g = g * 2 / 3;
		if(g == 0) break;
	}
	LL ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= min(n,m);j ++)
		{
			for(int k = 0;k < i;k ++)
			{
				if(k != i - 1) 
					f[i][j] = max(f[i][j],f[k][j] + min(kll[j],a[i]));
				else
					f[i][j] = max(f[i][j],f[k][j - 1] + min(kll[j],a[i]));
			}
			ans = max(ans,f[i][j]);
		}
	//for(int i = 1;i <= n;i ++,puts(""))
	//	for(int j = 1;j <= min(n,m);j ++)
	//		cout << f[i][j] << " ";
	cout << ans <<endl;
	return 0;
}
