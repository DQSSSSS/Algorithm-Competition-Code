#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int t[SZ];

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		for(int i = 1;i <= 1000;i ++) t[i] = 0;
		int n;
		cin >> n;
		for(int i = 1;i <= n;i ++)
		{
			int x;
			scanf("%d",&x);
			t[x] ++;
		}
		int ans = 0,maxt = 0;
		for(int i = 1;i <= 1000;i ++)
		{
			if(t[i] > maxt) maxt = t[i],ans = i;
		}
		cout << ans << endl;
	}
	return 0;
}

