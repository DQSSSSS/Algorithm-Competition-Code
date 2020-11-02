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
const int SZ = 20010;
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

vector<LL> g[17000][20];
int n;
LL L,mp[20][20];

LL get_b(LL x)
{
    int ans = 0;
    for(int i = 0;i < n;i ++)
        if(x >> i & 1) ans ++;
    return ans;
}

int deep;

void dfs(int now,int S,int nd,LL dis)
{
    if(nd == deep)
    {
        g[S][now].push_back(dis);
        return ;
    }
    for(int i = 0;i < n;i ++)
    {
        if(S & (1 << i)) continue;
        dfs(i,S | (1 << i),nd + 1,dis + mp[now][i]);
    }
}

bool check()
{
    if((n & 1) == 0)
        for(int S1 = 0;S1 < (1 << n);S1 ++)
        {
            if((S1 & 1) == 0 || get_b(S1) != n / 2 + 1) continue;
            int S2 = ((1 << n) - 1) ^ S1 | 1;
            for(int p = 1;p < n;p ++)
                if(S1 & (1 << p))
                {
                    S2 ^= 1 << p;
                    for(int k = 1;k < n;k ++)
                        if(g[S1][k].size() && g[S2][k].size())
                            for(int i = 0;i < g[S1][k].size();i ++)
                                if(*lower_bound(g[S2][k].begin(),g[S2][k].end(),L - g[S1][k][i]) == L - g[S1][k][i])
                                    return true;
                    S2 ^= 1 << p;
                }
        }
    else
        for(int S1 = 0;S1 < (1 << n);S1 ++)
        {
            if((S1 & 1) == 0 || get_b(S1) != n / 2 + 1) continue;
            int S2 = ((1 << n) - 1) ^ S1 | 1;
            for(int k = 0;k < n;k ++)
                for(int k1 = 0;k1 < n;k1 ++)
                    if(k1 != k && g[S1][k].size() && g[S2][k1].size())
                        for(int i = 0;i < g[S1][k].size();i ++)
                            if(*lower_bound(g[S2][k1].begin(),g[S2][k1].end(),L - g[S1][k][i] - mp[k][k1]) == L - g[S1][k][i] - mp[k][k1])
                                return true;
        }
    return false;
}

int main()
{
    n = read();
    L = read();
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
            mp[i][j] = read();
    deep = n / 2 + 1;
    dfs(0,1,1,0);
    for(int S1 = 0;S1 < (1 << n);S1 ++)
    {
        if((S1 & 1) == 0 || get_b(S1) != n / 2 + 1) continue;
        for(int k = 1;k < n;k ++)
            sort(g[S1][k].begin(),g[S1][k].end());
    }
    if(check()) puts("possible");
    else puts("impossible");
    return 0;
}
//1 -> 2 -> 4 -> 3 -> 1
//  3    3    2    2
//1 -> 2 -> 3 -> 1
/*

*/
