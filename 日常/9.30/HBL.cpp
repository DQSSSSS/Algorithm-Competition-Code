#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;

LL mod = 1e9+7;
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

int n,ans;

int use[1010][1010];

void dfs(int x,int y,int d)
{
    if(d == n + 1)
    {
        int tmp = 0;
        for(int i = 500 - n;i <= 500 + n;i ++)
            for(int j = 500 - n;j <= 500 + n;j ++)
                if(use[i][j]) tmp ++;
        ans += tmp;
        return ;
    }
    use[x + 1][y] ++;
    dfs(x + 1,y,d + 1);
    use[x + 1][y] --;

    use[x - 1][y] ++;
    dfs(x - 1,y,d + 1);
    use[x - 1][y] --;

    use[x][y + 1] ++;
    dfs(x,y + 1,d + 1);
    use[x][y + 1] --;

    use[x][y - 1] ++;
    dfs(x,y - 1,d + 1);
    use[x][y - 1] --;
}

int main()
{
    for(n = 0;n <= 20;n ++)
    {
        ans = 0;
        use[500][500] = 1;
        dfs(500,500,1);
        cout << (ans - (int)pow(4,n)) / 4 <<endl;
    }
    return 0;
}
/*

1,8,44,224,1068,4960,22416,99968,439212,1914208,8264208

*/
