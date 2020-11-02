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

int n,k,a[SZ];
char s[SZ];

int main()
{
	n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	scanf("%s",s + 1);
	for(int i = 1,l = 0;i < n;i ++)
	{
		if(s[i] == '1' && (i == 1 || s[i - 1] == '0')) l = i; 
		if(s[i] == '1' && (i == n - 1 || s[i + 1] == '0'))
		{
			int r = i + 1;
			sort(a + l,a + r + 1);
		}
	}
	bool flag = 0;
	for(int i = 1;i < n;i ++)
		if(a[i] > a[i + 1]) flag = 1;
	if(flag) puts("NO");
	else puts("YES");
	return 0;
}

