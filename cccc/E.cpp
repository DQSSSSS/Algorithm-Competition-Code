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

int main()
{
	puts("I\n \nL\no\nv\ne\n \nG\nP\nL\nT");
	return 0;
}




