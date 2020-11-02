#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 500010;
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

double g[20][20];

double get_ans1()
{
    double ans = 1;
    int x = -1;
    char a = getchar();
    while(233)
    {
        bool flag = 0;
        while(a < '0' || a > '9') { if(ans == '\n') { flag = 1; break; } a = getchar(); }
        if(flag) break;
        int y = 0;
        while(a >= '0' && a <= '9') y = y * 10 + a - '0',a = getchar();
        //cout << x << " " << y << endl;
        if(~x) ans *= g[x][y];
        if(a == '\n') break;
        x = y;
    }

    return ans;;
}

double get_ans2()
{
    int x = read();
    return 1.0 / (1 - g[x][x]);
}

int main()
{
    for(int i = 1;i <= 4;i ++)
        for(int j = 1;j <= 4;j ++)
            scanf("%lf",&g[i][j]);
    printf("%.8f\n",get_ans1());
    printf("%.8f\n",get_ans1());
    printf("%.8f\n",get_ans2());
    printf("%.8f\n",get_ans2());
    return 0;
}
