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
	freopen("haha5.in","w",stdout);
	srand(time(0));
    int T = 2;
    cout << T << endl;
    while(T --)
	{
        int n,m;
        n = 30000,m = 60000;
		printf("%d %d\n",n,m);
        for(int i = 1;i <= n;i ++) use[i] = 0;
        for(int i = 1;i <= n - 1;i ++)
            printf("%d %d %d\n",i,i + 1,randlr(0,2e9));
        for(int i = n;i <= m;i ++)
        {
            int u = randlr(1,n),v = randlr(1,n);
            while(u == v)
				u = randlr(1,n),v = randlr(1,n);
			printf("%d %d %d\n",u,v,randlr(0,2e9));
        }
        int k = 5;
        printf("%d\n",k);
        while(k --)
		{
            int u = randlr(1,n);
            while(use[u]) u = randlr(1,n);
            use[u] = 1;
            printf("%d ",u);
		}
		puts("");
	}
	return 0;
}
