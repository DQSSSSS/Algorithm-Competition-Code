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
    freopen("in.txt","w",stdout);
    srand(time(0));
    int n = randint() % 1000 + 1;
    printf("%d\n",n);
    for(int i = 1;i <= n;i ++)
    {
        int x = randint() % 100 + 1;
        int y = randint() % 100 + 1;
        printf("%d %d\n",x,y);
    }
    return 0;
}
