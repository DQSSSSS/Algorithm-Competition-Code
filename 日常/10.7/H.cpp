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


vector<int> g1[SZ],g2[SZ];
bool use[SZ];
int mst[SZ];

bool work()
{
    s = n + m + 1,e = n + m + 2;
    int sum = 0;
    for(int i = 1;i <= m;i ++)
        insert(i + n,e,1);
    for(int i = 1;i <= n;i ++)
        insert(s,i,g1[i].size()),sum += g1[i].size();
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            for(int k = 0;k < g1[i].size();k ++)
                if(g1[i][k] == mst[j])
                    insert(i,j + n,1);
    if(dinic() == sum)
        ans = 
}

void dfs(int pos)
{
    if(pos == m + 1)
    {
        work();
        return ;
    }
    if(!g2[pos].size()) dfs(pos + 1);
    if(g2[pos].size() == 1) mst[pos] = g2[pos][0],dfs(pos + 1);
    if(g2[pos].size() == 2)
    {
        mst[pos] = g2[pos][0],dfs(pos + 1);
        mst[pos] = g2[pos][1],dfs(pos + 1);
    }
    return ;
}

int main()
{
    int T = read();
    for(int cc = 1;cc <= T;cc ++)
    {
        ans = 0;
        memset(head,0,sizeof(head));
        n = read(),m = read();
        for(int i = 1;i <= n;i ++)
        {
            int k = read(),x;
            while(k --) x = read(),g1[i].push_back(x);
        }
        for(int i = 1;i <= m;i ++)
        {
            int k = read(),x;
            while(k --) x = read(),g2[i].push_back(x);
        }
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
