#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 500010;
const LL INF = 2e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

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

int randint()
{
	return rand() << 16 | rand();
}

int randlr(int l,int r)
{
	return randint() % (r - l + 1) + l;
}

bool use[SZ];

int main()
{
    for(int t = 0;;t ++)
	{
        system("data.exe");
        system("force.exe");
        system("std.exe");
		if(!system("fc std.out force.out"))
		{
            printf("%d  :  AC\n",t);
		}
		else
		{
			printf("%d  :  WA\n",t);
			break;
		}
	}
	return 0;
}
