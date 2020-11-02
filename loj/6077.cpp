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

int a[SZ],b[SZ];

int get(int n)
{
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j < i;j ++)
			if(a[i] > a[j])
				ans ++;
	return ans;
}

int main()
{
	int fac = 1;
	for(int i = 1;i <= 10;i ++)
	{
		for(int j = 0;j <= i * (i - 1) / 2;j ++) b[j] = 0;
		fac *= i;
		for(int j = 1;j <= i;j ++) a[j] = j;
		int n = fac;
		while(n --)
		{
			b[get(i)] ++;
			next_permutation(a + 1,a + 1 + i);
		}
		int ans = 0;
		puts("--------------------");
		printf("%d : \n",i);
		for(int j = 0;j <= i * (i - 1) / 2;j ++) printf("%d ",b[j]),ans += b[j]; puts("");
		cout << ans << endl;
		puts("--------------------");
	}
	return 0;
}
