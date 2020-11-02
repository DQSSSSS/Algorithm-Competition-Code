#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

ULL f[110][22];

void pre()
{
	for(int i = 1;i <= 9;i ++) f[1][i] = 1;
	for(int i = 2;i <= 100;i ++)
		for(int j = 0;j <= 9;j ++)
			for(int k = j;k <= 9;k ++)
				f[i][j] += f[i - 1][k];
}

string s;

ULL dp()
{
	int n = s.length();	
	ULL ans = 0;
	for(int i = 1;i < n;i ++)
		for(int j = 1;j <= 9;j ++)
			ans += f[i][j];
	int lst = 1;
	for(int i = 0;i < n;i ++)
	{
		if(s[i] - '0' < lst) break;
		if(i != n - 1)
			for(int j = lst;j < s[i] - '0';j ++)
				ans += f[n - i][j];
		else
			for(int j = lst;j <= s[i] - '0';j ++)
				ans += f[n - i][j];
		lst = s[i] - '0';
	}
	return ans;
}

int main()
{
	pre();
	int T;
	cin >> T;
	while(T --)
	{
		cin >> s;	
		int l = s.length(),flag = 0;
		for(int i = 0;i < l - 1;i ++) if(s[i + 1] < s[i]) flag = 1;
		if(flag) { puts("-1"); continue; }
		ULL ans = dp();
		cout << ans << endl;
	}
	return 0;
}




