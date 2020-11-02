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
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

LL gcd(LL a,LL b) { return b == 0 ? a : gcd(b,a % b); }

void exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b == 0)
	{
        x = 1; y = 0;
        return ;
	}
    exgcd(b,a % b,x,y);
    LL t = x;
    x = y; y = t - a / b * y;
}

int main()
{
	LL n,a,b;
	cin >> n >> a >> b;
    if(n % gcd(a,b)) puts("NO");
    else
	{
		LL x,y;
        exgcd(a,b,x,y);
        LL d = gcd(a,b);
		x *= n / d,y *= n / d;
        while(x < 0) x += b / d,y -= a / d;
        while(y < 0) x -= b / d,y += a / d;
		if(x < 0 || y <0) { puts("NO"); return 0; }
        puts("YES");
        cout << x << " " << y << endl;
	}
	return 0;
}



