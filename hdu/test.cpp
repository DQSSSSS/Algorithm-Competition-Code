#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double,double> pii;
const int SZ = 1000010;
const LL INF = 1000000010;
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

int randint()
{
	return rand() << 16 | rand();
}

int main()
{
	freopen("input.txt","w",stdout);
	srand(time(0));
	int T = 10;
	cout << T <<endl;
	while(T --)
	{
		int n = 1e4,m = 1e4;
		cout << n << " " << m << endl;
		for(int i = 1;i <= n;i ++)
		{
			int l = randint() % i + 1,r = i,a = rand() % 1000 + 1,b = rand() % 1000 + 1;
			printf("%d %d %d %d\n",l,r,a,b);
		}
	}
	return 0;
}
