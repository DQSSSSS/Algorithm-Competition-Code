#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double,double> pii;
const int SZ = 1000010;
const double INF = 1e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};
const double eps = 1e-6;

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
		system("data.exe"); system("6248.exe"); system("6248-std.exe");
		if(!system("fc my.out std.out"))
		{
			printf("%d  :AC\n",t);
		}
		else
		{
			printf("%d   :WA\n",t);
			break;
		}
	}
	return 0;
}
