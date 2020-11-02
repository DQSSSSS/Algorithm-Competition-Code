#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;

int randint()
{
	return rand() << 16 | rand();
}

LL randLL()
{
	return (LL)randint() << 32ll | (LL)randint();
}

const int mod = 100;
const int MOD = 1000000000;

int main()
{
	srand(time(0));
	int n = randint() % mod + 1;
	printf("%d\n",n);
	for(int i = 2;i <= n;i ++)
	{
		int u = i,v = randint() % (i - 1) + 1,c = randint() % mod;
		printf("%d %d %d\n",u,v,c);
	}
	int m = randint() % mod + 1;
	printf("%d\n",m);
	for(int i = 1;i <= m;i ++)
	{
		int a = randint() % n + 1;
		int b = randint() % n + 1;
		int c = randint() % n + 1;
		printf("%d %d %d\n",a,b,c);
	}	
	return 0;
}


