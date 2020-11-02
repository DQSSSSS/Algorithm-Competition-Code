#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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

void init()
{
    phi[1] = 1;
    for(int i = 2;i <= 7e4;i ++)
	{
		if(!vis[i]) phi[i] = i - 1,pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = pri[j] * i) <= 7e6;j ++)
		{
            vis[m] = 1;
            if(i % pri[j] == 0) phi[m] = phi[i] * pri[j];
            else phi[m] = phi[i] * phi[j];
		}
	}
}

int main()
{
	init();
	LL n = read(),ans = 0;
    for(int i = 1;i <= sqrt(n);i ++)
        if(n % i == 0)
			ans += phi(i) * (n / i) + phi(n / i) * i;
    printf("%lld\n",ans);
	return 0;
}
/*
5 1
4 3 2 5 1
1 2
7
Q 3 2
Q 2 1
B 2 3
B 1 5
Q 2 1
Q 2 4
Q 2 3
*/

