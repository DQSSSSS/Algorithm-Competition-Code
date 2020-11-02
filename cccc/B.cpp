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

string s;

int main()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	if(0 <= h && h <= 11 || (h == 12 && m == 0))
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
	else
	{
		int t = h - 12;
		if(m != 0) t ++;
		for(int i = 1;i <= t;i ++) cout << "Dang";
	}
	return 0;
}

