#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 +a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

LL a[SZ];

int randint()
{
	return rand() << 16 | rand();
}

int rand(int l,int r)
{
	return randint() % (r - l + 1) + l;
}

int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int n = rand(1,1000),m = rand(1,1000);
	printf("%d %d\n",n,m);
	for(int i = 1;i <= n;i ++) cout << rand(0,1e6) << " "; puts("");
	for(int i = 1;i <= m;i ++)
	{
		int opt = rand(1,2),l = rand(1,n),r = rand(1,n);
		if(l > r) swap(l,r);
		if(opt == 2) printf("%d %d %d\n",opt,l,r);
		else printf("%d %d %d %d\n",opt,l,r,rand(1,1e6));
	}
	return 0;
}


