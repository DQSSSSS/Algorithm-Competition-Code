#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 400010;
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

struct haha
{
	LL x,y,w;
}a[SZ];

bool cmp(haha a,haha b)
{
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int pos[SZ],n,m;

LL get_ans(LL x)
{
	LL ans = 0;
	for(LL i = 1;i * i <= x;i ++)
	{
		if(x % i == 0)
		{
			if(i * i == x) ans ++;
			else ans += 2;
		}
	}
	return ans;
}

LL work()
{
	int len = n - pos[m] + 1;
	for(int i = 1;i < m;i ++)
		if(pos[i + 1] - pos[i] != len) return 0;
	//cout << m << endl;
	for(int j = 0;j < len;j ++)
	{
		LL y = a[pos[1] + j].y;
		for(int i = 1;i <= m;i ++)
			if(a[pos[i] + j].y != y) return 0;
	}
	LL ans = 0;
	for(int i = 1;i <= m;i ++)
	{
		LL tmp = 0;
		for(int j = 0;j < len;j ++)
			tmp = __gcd(tmp,a[pos[i] + j].w);
		ans = __gcd(tmp,ans);
	}
	for(int j = 0;j < len;j ++)
	{
		LL tmp = 0;
		for(int i = 1;i <= m;i ++)
			tmp = __gcd(tmp,a[pos[i] + j].w);
		ans = __gcd(ans,tmp);
	}
	ans = get_ans(ans);
	if((m > 1 || len > 1) && ans == 1) ans = 0;
	return ans;
}

int main()
{
	n = read();
	for(int i = 1;i <= n;i ++)
		a[i].x = read(),a[i].y = read(),a[i].w = read();
	sort(a + 1,a + 1 + n,cmp);
	m = 0;
	for(int i = 1,l = 1;i <= n;i ++)
	{
		if(i == n || a[i + 1].x != a[i].x)
		{
			pos[++ m] = l;
			l = i + 1;
		}
	}
	pos[m + 1] = n + 1;
	printf("%I64d\n",work());
	return 0;
}
/*

4
2 3 36
2 4 9
3 3 6
3 4 9

*/
