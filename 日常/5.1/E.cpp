#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

int a[SZ];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	LL sum = 0,ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] > sum) sum += a[i],ans ++;
	}
	cout << ans << endl;
	return 0;
}
