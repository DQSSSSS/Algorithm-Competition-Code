#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

struct haha
{
	string s;
	LL x;
}a[233];

bool cmp(haha a,haha b)
{
	if(a.x != b.x) return a.x > b.x;
	return a.s < b.s;
}

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int n,m;
		cin >> n >> m;
		for(int i = 1;i <= n;i ++)
			cin >> a[i].s >> a[i].x;
		sort(a + 1,a + 1 + n,cmp);
		LL ans = 0;
		for(int i = 1;i <= m;i ++) ans += (LL)(m - i + 1) * a[i].x;
		cout << ans << " ";
		for(int i = 1;i <= m;i ++) printf("%s%c",a[i].s.c_str(),i == m ? '\n' : ' ');
	}
	return 0;
}

