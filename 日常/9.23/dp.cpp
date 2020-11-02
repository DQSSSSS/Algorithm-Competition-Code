#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
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
	for(int t = 0;;t ++)
	{
		system("data.exe");
		system("10.exe");
		system("J.exe");
		if(!system("fc 10.out data.out"))
		{
			printf("%d  : AC\n",t);
		}
		else
		{
			printf("%d  : WA\n",t);
			break;
		}
	}
}
