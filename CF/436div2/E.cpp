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

int t[SZ],d[SZ],p[SZ],f[SZ],id[SZ];
vector<int> g[SZ],A;

int cmp(int a,int b) { return d[a] < d[b]; }

int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++) id[i] = i;
    for(int i = 1;i <= n;i ++)
    {
        t[i] = read(),d[i] = read() - 1,p[i] = read();
    }
    sort(id + 1,id + 1 + n,cmp);
    for(int x = 1;x <= n;x ++)
    {
        int i = id[x];
        for(int j = d[i];j >= t[i];j --)
        {
            if(f[j] < f[j - t[i]] + p[i])
            {
                f[j] = f[j - t[i]] + p[i];
                g[j] = g[j - t[i]];
                g[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= 2000;i ++)
    {
        if(f[i] > ans)
        {
            A = g[i];
            ans = f[i];
        }
    }
    printf("%d\n%d\n",ans,A.size());
    sort(A.begin(),A.end(),cmp);
    for(int i = 0;i < A.size();i ++)
        printf("%d ",A[i]);
    return 0;
}
/*
5
5 4 3 3 3

1
1 2 3
*/
