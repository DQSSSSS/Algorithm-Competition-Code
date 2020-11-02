#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int n;
char s[110];
map<string,int> maps;

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		maps.clear();
		cin >> n;	
		for(int i = 1;i <= n;i ++)
		{
			scanf("%s",s);
			string ss = s;
			maps[ss] = i;
		}
		int t = 0,maxx = 0;
		for(int i = 1;i <= n;i ++)
		{
			scanf("%s",s);
			string ss = s;
			maxx = max(maxx,maps[ss]);
			t ++;
			if(maxx == i) printf("%d ",t),t = 0;
		}
		puts("");
	}
	return 0;
}


