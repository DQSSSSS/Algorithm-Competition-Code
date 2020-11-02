#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
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
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int n,m;

LL r,x[SZ];
double y[SZ];

LL pf(LL x) { return x * x; }

int main()
{
	cin >> n >> r;
	r *= 2;
	for(int i = 1;i <= n;i ++) cin >> x[i];
	for(int i = 1;i <= n;i ++)
	{
		double ans = r / 2.0;
		for(int j = 1;j < i;j ++)
		{
			double tmp = sqrt(pf(r) - pf(x[i] - x[j]));
			ans = max(ans,y[j] + tmp);
		}
		y[i] = ans;
	}
	for(int i = 1;i <= n;i ++) printf("%.10f ",y[i]);
	return 0;
}




