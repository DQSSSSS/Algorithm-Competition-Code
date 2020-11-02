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
	for(int t = 1;;t ++)
	{
		system("datamaker.exe");
		system("17-9-5-2.exe");
		system("test.exe");
		if(!system("fc my.txt std.txt"))
		{
			printf("%d : AC\n",t);
		}
		else
		{
			
			printf("%d : WA\n",t);
			break;
		}
	}
	return 0;
}


