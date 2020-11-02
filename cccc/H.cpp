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
		int d,h,m;
		scanf("%d %d:%d",&d,&h,&m);
		if(d == 0) printf("%d %02d:%02d\n",d,h,m);
		else
		{
			int sum = (d - 1) * 24 * 60 + h * 60 + m;
			sum /= 2;
			int dd = sum / (24 * 60) + 1;
			int hh = (sum % (24 * 60)) / 60;
			int mm = sum % 60;
			printf("%d %02d:%02d\n",dd,hh,mm);
		}
	}
	return 0;
}

