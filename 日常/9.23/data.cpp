#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;

typedef long long LL;
const int SZ = 310;
const int INF = 1000000010;
const LL mod = 1000000007;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int main()
{
	freopen("data.in","w",stdout);
	srand(time(0));
	int T = 5;
	while(T --)
	{
		int n = rand() % 7 + 1,m = rand() % 7 + 1;
		int pos = rand() % (n + 1);
		bool use1[10] = {};
		for(int i = 1;i <= n;i ++)
		{
			int x = rand() % 7;
			while(use1[x]) x = rand() % 7;
			use1[x] = 1;
			printf("%c",x + 'a');
		}
		printf(" %d ",pos);
		bool use2[10] = {};
		for(int i = 1;i <= m;i ++)
		{
			int x = rand() % 7;
			while(use2[x]) x = rand() % 7;
			use2[x] = 1;
			printf("%c",x + 'a');
		}
		puts("");
	}
	return 0;
}
