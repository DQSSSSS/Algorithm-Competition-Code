#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int f[SZ],a[SZ],b[SZ];

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		for(int i = 0;i <= 200;i ++) f[i] = 0;
		int n;
		cin >> n;
		for(int i = 1;i <= n;i ++)
		{
			int ax,ay,bx,by;
			scanf("%d.%d %d.%d",&ax,&ay,&bx,&by);
			a[i] = ax * 10 + ay;
			b[i] = bx * 10 + by;
		}
		int ans = 0,maxt = 0;
		for(int i = 1;i <= n;i ++)
		{
			f[i] = 1;
			for(int j = 0;j < i;j ++)
				if(a[j] < a[i] && b[j] > b[i])
					f[i] = max(f[i],f[j] + 1);
			ans = max(ans,f[i]);
		}
		cout << ans << endl;
	}
	return 0;
}


