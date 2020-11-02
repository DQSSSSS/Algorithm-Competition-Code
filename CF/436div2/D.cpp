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

vector<int> g;
int a[SZ],t[SZ],pre[SZ],now[SZ],use[SZ];

int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        a[i] = read();
        t[a[i]] ++;
    }
    for(int i = 1;i <= n;i ++)
        if(!now[a[i]]) now[a[i]] = i;
        else pre[i] = now[a[i]],now[a[i]] = i;

    int ans = 0;
    for(int i = 1;i <= n;i ++)
        if(t[i] == 0)
            g.push_back(i),ans ++;

    int p1 = 0,p2 = g.size() - 1,l = 1,r = n;
//    for(int i = 0;i < g.size();i ++) cout << g[i] << " "; puts("");
    while(l <= r && p1 <= p2)
    {
        while(l <= r && t[a[l]] <= 1) l ++;
        while(l <= r && t[a[r]] <= 1) r --;
        if(g[p1] < a[l])
        {
            t[a[l]] --; a[l] = g[p1 ++];
        }
        else
        {
            if(!use[a[l]]) use[a[l]] = 1;
            else t[a[l]] --,a[l] = g[p1 ++];
        }
        l ++;
    }
    printf("%d\n",ans);
    for(int i = 1;i <= n;i ++)
        printf("%d ",a[i]);
    return 0;
}
/*
5
5 4 3 3 3
*/
