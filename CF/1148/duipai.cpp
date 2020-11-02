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
	while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if  (flag) n = -n;
	return n;
}

int main()
{
	for(int t = 0;;t ++)
	{
		system("data.exe");
		//system("GG.exe");
		if(system("G.exe")!= 0) break;
		printf("%d\n",t);
		/*if(!system("fc my.out std.out"))
		{
			printf("%d : AC\n",t);
		}
		else
		{
			printf("%d : WA\n",t);
			break;
		}*/
	}
	return 0;
}

