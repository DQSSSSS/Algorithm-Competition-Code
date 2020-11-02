#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double,double> pii;
const int SZ = 1000010;
const LL INF = 2e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};
const double eps = 1e-6;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n;

LL a[SZ],b[SZ];

LL check(LL p)
{
	LL sum = 0;
	for(int i = 1;i <= n;i ++) b[i] = a[i] % p,sum += b[i];
	sort(b + 1,b + 1 + n);
	LL ans = 0;
	int l = 1,r = n;
	while(l <= r)
	{
		LL d = min(b[l],p - b[r]);
		ans += d;
		if(d == b[l]) b[l] = 0,b[r] += d,l ++;
		else b[r] += d,b[l] -= d,r --;
	}
	return ans;
}

LL pri[SZ],tot;

void fj(LL x)
{
	tot = 0;
	LL y = x;
	for(int i = 2;i <= sqrt(x);i ++)
	{
		if(y % i == 0)
		{
			pri[++ tot] = i;
			while(y % i == 0) y /= i;
		}
	}
	if(y != 1) pri[++ tot] = y;
}

int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		LL sum = 0;
		for(int i = 1;i <= n;i ++)
			a[i] = read(),sum += a[i];
		fj(sum);
		LL ans = INF;
		for(int i = 1;i <= tot;i ++)
		{
			LL x = check(pri[i]);
		//	cout << pri[i] << " " << x << endl;
			ans = min(ans,x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

