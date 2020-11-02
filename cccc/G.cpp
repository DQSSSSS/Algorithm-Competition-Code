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

int main()
{
	int T = read();
	while(T --)
	{
		double x,y;
		cin >> x >> y;
		double bz = (x - 100) * 0.9 * 2;
		if(fabs(y - bz) < bz * 0.1) puts("You are wan mei!");
		else if(bz < y) puts("You are tai pang le!");
		else puts("You are tai shou le!");
	}
	return 0;
}






