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
	while(a <= '9' && a >= '0') { n = n *10 +a - '0'; a = getchar(); }
	if(flag) n = -n;
	return n;
}

int l[SZ],r[SZ],n,k,ans[SZ];

deque<int> q;

int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		for(int i = 1;i <= n;i ++) l[i] = read(),r[i] = read();
		
		for(int i = 1,t = 1;i <= n;i ++)
		{
			t = max(t,l[i]);
			if(t > r[i]) ans[i] = 0;
			else ans[i] = t,t ++;
		}
		for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

