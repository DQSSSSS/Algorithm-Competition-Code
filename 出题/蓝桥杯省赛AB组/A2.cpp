#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll yin[100000];
const long long INF = 21474836470;
int main()
{
	//freopen("G.txt", "r", stdin);
	ll T;
	cin >> T;
	while(T--)
	{
		ll v;
		cin >> v;
		ll sq3 = 1;
		ll ans = INF;

		ll cnt = 0;

		for(int i = 1; i <= sqrt(v); i++)
			if(v % i == 0) yin[++cnt] = i;

		for(int i = 1; i <= cnt; i++)  //10e3
			for(int j = 1; j <= cnt; j++)    //10e4.5
			{
				ll a, b, c;
				a = yin[i];
				b = yin[j];
				c = v / a;
				c /= b;
				if(a * b * c == v) ans = min(ans, 2*(a*b + a*c + b*c));
			}
		if(v == 0) ans = 0;
		cout << ans << endl;

		for(int i = 1; i <= cnt; i++)
			yin[i] = 0;
	}
	return 0;
}
