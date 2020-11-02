#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

int d[SZ];

void fj(int x)
{
	for(int i = 2;i <= sqrt(x);i ++)
	{
		if(x % i == 0)
		{
			int t = 0;
			while(x % i == 0) x /= i,t ++;
			printf("%d^%d ",i,t);
		}
	}
	if(x != 1)
		printf("%d^1",x);
	puts("");
}


int main()
{
	int n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= i;j ++) if(i % j == 0) d[i] ++;
		int t = 0;
		for(int j = 1;j < i;j ++)
			if(d[j] > d[i])
				if(++ t >= 2) break;
		if(t <= 1) cout << i << " " << d[i] << endl,ans ++;//fj(i);
	}
	cout << ans << endl;
	return 0;
}

