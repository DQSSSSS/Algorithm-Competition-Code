#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {-1,-1,1,1,-2,-2,2,2};
const int dy[] = {2,-2,-2,2,1,-1,-1,1};

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}


int main()
{
	int T = read(),cc = 0;
	int a[] = {1,9,41,109,205};
	while(T --)
	{
		unsigned long long ans,n = read();
		if(n <= 4) ans = a[n];
		else ans = 14 * n * n - 6 * n + 5;
		printf("Case #%d: %llu\n",++ cc,ans);
	}
	return 0;
}




