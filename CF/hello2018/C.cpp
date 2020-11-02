#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

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

LL c[SZ],f[SZ];

int main()
{
	int n = read();
	LL l = read();
	for(int i = 0;i < n;i ++) c[i] = read();
	f[0] = c[0];
	for(int i = 1;i < 31;i ++)
	{
		f[i] = min(f[i - 1] * 2,i >= n ? (LL)1e18 : c[i]);
	}
	//for(int i = 0;i < 31;i ++) cout << f[i] << " "; puts("");
	LL ans = 1e18,tmp = 0;
	for(int i = 30;i >= 0;i --)
	{
		if(l & (1 << i)) tmp += f[i];
		else
		{
			ans = min(ans,tmp + f[i]);
		}
	}
	ans = min(ans,tmp);
	cout << ans << endl;
	return 0;
}

