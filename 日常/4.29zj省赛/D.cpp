#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

struct haha
{
	char c;
	LL x;
}a[SZ],tmpr[SZ],tmpl[SZ];


//vector<haha> g;
char s[SZ];
LL f[1010],g[1010][1010];

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s + 1);
		for(int i = 1;i <= n;i ++) cin >> a[i].x,a[i].c = s[i],f[i] = 0;
		
		for(int i = 1;i <= n;i ++)
		{
			LL d = 0,ans = 0;
			for(int j = i;j <= n;j ++)
			{
				if(a[j].c == '(') d += a[j].x;
				else ans += d * a[j].x;
				g[i][j] = ans;
			}
		}
		
	/*	for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
				printf("%d ",g[i][j]);
			}
			puts("");
		}*/
		
		for(int i = 1;i <= n;i ++)
			for(int j = 0;j < i;j ++)
				f[i] = max(f[i],f[j] + g[j + 1][i]);
		//for(int i = 1;i <= n;i ++) cout << f[i] << " "; puts("");
		cout << f[n] << endl;
	}
	return 0;
}

