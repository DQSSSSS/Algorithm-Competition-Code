#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const LL INF = 1000000000000000010ll;

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


int lcp[SZ],sa[SZ],rk[SZ],len;

bool cmp_sa(int *y,int a,int b,int k)
{
    int a1 = y[a],b1 = y[b];
    int a2 = a + k >= len ? -1 : y[a + k];
    int b2 = b + k >= len ? -1 : y[b + k];
    return a1 == b1 && a2 == b2;
}

int t1[SZ],t2[SZ],cc[SZ];

void get_sa(char s[])
{
    int *x = t1,*y = t2,m = 256;
    for(int i = 0;i < m;i ++) cc[i] = 0;
    for(int i = 0;i < len;i ++) ++ cc[x[i] = s[i]];
    for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
    for(int i = len - 1;~i;i --) sa[-- cc[x[i]]] = i;
    for(int k = 1;k < len;k <<= 1)
    {
        int p = 0;
        for(int i = len - k;i < len;i ++) y[p ++] = i;
        for(int i = 0;i < len;i ++) if(sa[i] >= k) y[p ++] = sa[i] - k;
        for(int i = 0;i < m;i ++) cc[i] = 0;
        for(int i = 0;i < len;i ++) ++ cc[x[y[i]]];
        for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
        for(int i = len - 1;~i;i --) sa[-- cc[x[y[i]]]] = y[i];
        swap(x,y); m = 1; x[sa[0]] = 0;

        for(int i = 1;i < len;i ++)
            x[sa[i]] = cmp_sa(y,sa[i - 1],sa[i],k) ? m - 1 : m ++;
        if(m >= len) break;
    }
}

void get_lcp(char s[])
{
    for(int i = 0;i < len;i ++) rk[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i = 0;i < len;i ++)
    {
        if(!rk[i]) continue;
        int j = sa[rk[i] - 1];
        if(h) h --;
        while(s[i + h] == s[j + h]) h ++;
        lcp[rk[i]] = h;
    }
}

char s[SZ];

int fa[SZ];
LL vx[SZ],vm[SZ],sz[SZ];

int find(int x)
{
    if(x == fa[x]) return x;
    int f = find(fa[x]);
    return fa[x] = f;
}

LL sum[SZ],ans[SZ];

vector<int> g[SZ];

int main()
{
    len = read();
    scanf("%s",s);
    get_sa(s); get_lcp(s);
    for(int i = 0;i < len;i ++)
        vm[rk[i]] = vx[rk[i]] = read(),fa[i] = i,sz[i] = 1;
/*
    for(int i = 0;i < len;i ++) printf("%3d",sa[i]); puts("");
    for(int i = 0;i < len;i ++) printf("%3d",vx[i]); puts("");
    for(int i = 0;i < len;i ++) printf("%3d",lcp[i]); puts("");
*/
    for(int i = 1;i < len;i ++)
        g[lcp[i]].push_back(i);

    LL tot = 0,maxn = -INF;
    for(int i = len - 1;i >= 0;i --)
    {
        for(int j = 0;j < g[i].size();j ++)
        {
            int a = g[i][j],b = g[i][j] - 1;
            int x = find(a),y = find(b);
            if(x != y)
            {
                fa[x] = y;
                tot += sz[x] * sz[y];
                maxn = max(maxn,max(vm[x] * vm[y],vx[x] * vx[y]));
                sz[y] += sz[x];
                vx[y] = max(vx[y],vx[x]);
                vm[y] = min(vm[y],vm[x]);
            }
        }
        sum[i] = tot,ans[i] = maxn;
    }
    for(int i = 0;i <= len - 1;i ++)
        printf("%lld %lld\n",sum[i],ans[i] == -INF ? 0ll : ans[i]);
    return 0;
}
