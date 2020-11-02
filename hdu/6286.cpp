#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a,b,c,d;

LL get_d(LL l,LL r,LL x)
{
	return r / x - (l - 1) / x;
}

int main()
{
	while(cin >> a >> b >> c >> d)
	{
        LL al = b - a + 1,bl = d - c + 1;
        LL a2018 = get_d(a,b,2018),b2018 = get_d(c,d,2018);
        LL a1009 = get_d(a,b,1009) - a2018,b1009 = get_d(c,d,1009) - b2018;
        LL a2 = get_d(a,b,2) - a2018,b2 = get_d(c,d,2) - b2018;
        LL aa = al - (a1009 + a2 - a2018),bb = bl - (b1009 + b2 - b2018);
		LL ans = a2 * b1009 + b2 * a1009 + a2018 * (bl - b2018) + (al - a2018) * b2018 + a2018 * b2018;
		//printf("%5lld%5lld%5lld%5lld%5lld\n",al,a2,a1009,a2018,aa);
		//printf("%5lld%5lld%5lld%5lld%5lld\n",bl,b2,b1009,b2018,bb);
		cout << ans << endl;
	}
	return 0;
}

