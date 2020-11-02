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

int pri[SZ],val[SZ];

struct haha
{
    int id,v;
};

bool operator <(haha a,haha b) { return a.v == b.v ? a.id < b.id : a.v > b.v; }

vector<haha> g[SZ];

int main()
{
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++)
    {
        pri[i] = read();
        int x,y;
        while(~scanf("%d",&x) && ~x) scanf("%d",&y),g[i].push_back((haha){x,y});
    }
    for(int i = 1;i <= n;i ++)
    {
        if(g[i].empty()) continue;
        sort(g[i].begin(),g[i].end());
        if(g[i][0].v < pri[i]) continue;
        if(g[i].size() == 1 || g[i][1].v < pri[i]) { val[g[i][0].id] += min(g[i][0].v,(int)(pri[i] * 1.1)); continue; }
        val[g[i][0].id] += min(g[i][0].v,(int)(g[i][1].v * 1.1));
    }
    int q = read();
    while(q --)
    {
        int x = read();
        printf("%d\n",val[x]);
    }
    return 0;
}
