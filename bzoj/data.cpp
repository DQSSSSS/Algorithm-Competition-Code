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

int main()
{
    freopen("in.in","w",stdout);
    srand(time(0));
    int n = 5,m = 5;
    printf("%d %d\n",n,m);
    while(n --) {
    	int x = randint() % 10 + 1;
    	int y = randint() % 10 + 1;
        cout << x << " " << y <<endl;
    }
    while(m --) {
    	int opt = randint() % 2 + 1;
    	int x = randint() % 10 + 1;
    	int y = randint() % 10 + 1;
        cout << opt << " " << x << " " << y <<endl;
    }
    return 0;
}
