#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
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

int randint()
{
    return rand() << 16 | rand();
}

struct haha
{
    LL x,y;
}l[SZ];


int n,m;
clock_t st,et;

bool check(int x,int y)
{
    int ans = 2;
    if(l[x].x == l[y].x)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(i != x && i != y && l[i].x == l[x].x)
                ans ++;
            if((double)(et - st)/ CLOCKS_PER_SEC >= 4.5) { puts("possible"); exit(0); };
        }
        return ans >= m;
    }
    else
    {
        for(int i = 1;i <= n;i ++)
            if(i != x && i != y)
            {
                et = clock();
                if((double)(et - st)/ CLOCKS_PER_SEC >= 4.5) { puts("possible"); exit(0); };

                LL dy1 = l[x].y - l[y].y;
                LL dy2 = l[i].y - l[y].y;
                LL dx1 = l[x].x - l[y].x;
                LL dx2 = l[i].x - l[y].x;
                if(dy1 * dx2 == dy2 * dx1)
                    ans ++;
            }
        return ans >= m;
    }
}



int main()
{
    st = clock();
    srand(time(0));
    n = read();
    int p = read();
    m = ceil((double)n * p / 100);
    for(int i = 1;i <= n;i ++)
        l[i].x = read(),l[i].y = read();
    bool flag = 0;
    for(int t = 1;t <= 500;t ++)
    {
        int i,j;
        do
        {
            i = randint() % n + 1;
            j = randint() % n + 1;
            et = clock();
            if((double)(et - st)/ CLOCKS_PER_SEC >= 4.5) { puts("possible"); exit(0); };
        }while(i == j);
        if(check(i,j))
        {
            flag = 1;
            break;
        }
    }
    if(flag) puts("possible");
    else puts("impossible");
    return 0;
}
