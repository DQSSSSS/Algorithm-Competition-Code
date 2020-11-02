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
const int SZ = 500010;
const LL INF = 1000000010;
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

int ans,a[20],s[20];


void dfs(int pos,int d)
{
    if(pos + d > 4) pos ++,d = 1;
    if(pos == 4)
    {
        bool flag = 0;
        for(int i = 1;i <= 4;i ++)
            if(a[i] != s[i])
                { flag = 1; break; }
        if(!flag) ans ++;
        return ;
    }
    s[pos] += 3;
    dfs(pos,d + 1);
    s[pos] -= 3;

    s[pos] ++; s[pos + d] ++;
    dfs(pos,d + 1);
    s[pos] --; s[pos + d] --;

    s[pos + d] += 3;
    dfs(pos,d + 1);
    s[pos + d] -= 3;
}


int main()
{
    int T = read();
    for(int cc = 1;cc <= T;cc ++)
    {
        ans = 0;
        for(int i = 1;i <= 4;i ++) a[i] = read();
        dfs(1,1);
        printf("Case #%d: ",cc);
        if(ans == 0) puts("Wrong Scoreboard");
        else if(ans == 1) puts("Yes");
        else puts("No");
    }
    return 0;
}
