#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 +a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

LL a[SZ];


int main()
{
	freopen("in.txt","r",stdin);
	freopen("std.txt","w",stdout);
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	while(m --)
	{
		int opt = read(),l = read(),r = read(),d;
		if(opt == 1)
		{
			d = read();
			for(int i = l;i <= r;i ++) if(a[i] % d == 0) a[i] /= d;
		}
		else
		{
			LL ans = 0;
			for(int i = l;i <= r;i ++) ans += a[i];
			cout << ans << endl;
		}
	}
	return 0;
}

