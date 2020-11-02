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

int n,k;
LL m;

int a[SZ],b[SZ];

LL check(int x)
{
	for(int i = 1;i <= n;i ++)
		b[i] = a[i] >= x ? 1 : 0;
	LL ans = 0;
	for(int i = 1,r = 0,now = 0;i <= n;i ++)
	{
		while(r < n && now < k) now += b[++ r];
		if(now < k) break;
		ans += n - r + 1;
		now -= b[i];
	}
	return ans;
}

int Div()
{
    int l = 0,r = 1e9 + 1;
    while(r - l > 1)
	{
		int mid = l + r >> 1;
		LL x = check(mid);
		if(x >= m) l = mid;
		else r = mid;
	}
	return l;
}

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
	    n = read(),k = read(),m = read();
	    for(int i = 1;i <= n;i ++) a[i] = read();
	    printf("%d\n",Div());
	}
	return 0;
}

