#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 3010;
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
struct haha
{
    int u,v,k,id,ans;
    void rd() { u = read(); v = read(); k = read(); }
}ask[SZ];

bool cmp1(haha a,haha b) { return a.u == b.u ? a.k < b.k : a.u < b.u; }
bool cmp2(haha a,haha b) { return a.id < b.id; }

int deep[SZ],to[SZ],ans[SZ];

int main()
{
    int n = read(),m = read(),q = read();
    for(int i = 1;i <= m;i ++)
    {
        int u = read(),v = read();
        if(!to[u] || v < to[u]) to[u] = v;
    }
    for(int i = 1;i <= q;i ++) ask[i].rd(),ask[i].id = i;
    sort(ask + 1,ask + 1 + q,cmp1);

    for(int i = 1;i <= q;i ++)
    {
        if(ask[i].u != ask[i - 1].u)
        {
            int u = ask[i].u,now = 1;
            memset(deep,0,sizeof(deep));
            while(u && !deep[u])
                deep[u] = now,ans[now] = u,u = to[u],now ++;
        }
        int v = ask[i].v,k = ask[i].k;
    //    printf("%d %d %d\n",ask[i].u,v,k);
        if(!deep[v] || k > deep[v]) ask[i].ans = -1;
        else ask[i].ans = ans[k];
    }
    sort(ask + 1,ask + 1 + q,cmp2);
    for(int i = 1;i <= q;i ++)
        printf("%d\n",ask[i].ans);
    return 0;
}
/*
5 5 5
1 2
2 3
3 4
4 5
5 1
2 1 1

*/
