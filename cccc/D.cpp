#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n; 
}

string s[100010];

int main()
{
	int n = 0;
	while(cin >> s[++ n]); n -= 2;
	if(n >= 14)
	{
		printf("%s and %s are inviting you to dinner...",s[2].c_str(),s[14].c_str());
	}
	else if(n < 2)
	{
		puts("Momo... No one is for you ...");
	}
	else
	{
		printf("%s is the only one for you...",s[2].c_str());
	}
	return 0;
}



