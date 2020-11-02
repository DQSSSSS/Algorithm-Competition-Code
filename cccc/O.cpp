#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
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

struct haha
{
	double x,y;
}a[SZ];

double xl(haha a,haha b)
{
	return (a.y - b.y) / (a.x - b.x);
}

int main()
{
	int n = read();
	for(int i = 1;i <= n;i ++)
		a[i].x = read(),a[i].y = read();
	int ans = 0;
	for(int i = n - 1;i >= 2;i --)
	{
		haha l = a[i + 1],now = a[i],r = a[i - 1];
		if(xl(l,now) > 0 && xl(now,r) < 0) ans ++;
	}
	cout << ans << endl;
	return 0;
}

/*

9
10 -9
9 -10
6 6
5 1
4 4
3 3
2 0
1 1
0 -1

*/
