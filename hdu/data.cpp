#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 1000000010;
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

int randlr(int l,int r) {
	return randint() % (r - l + 1) + l;
}

int a[233];

int main()
{
    freopen("in.in","w",stdout);
    srand(time(0));
    int T = 1;
    while(T --) {
    	int n = 103;
   		printf("%d\n",n);
		for(int i = 1;i <= n;i ++) {
			printf("%d ",randlr(1,100000));
		}
		puts("");
	}
    return 0;
}
