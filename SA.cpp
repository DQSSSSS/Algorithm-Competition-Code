#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int SZ = 1000010;

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


int lcp[SZ],sa[SZ],rank[SZ],len;


bool cmp(int *y,int a,int b,int k)
{
    int a1 = y[a],b1 = y[b];
    int a2 = a + k >= len ? -1 : y[a + k];
    int b2 = b + k >= len ? -1 : y[b + k];
    return a1 == b1 && a2 == b2;
}

int t1[SZ],t2[SZ],cc[SZ];

void get_sa(int s[])
{
    int *x = t1,*y = t2,m = 256;
    for(int i = 0;i < m;i ++) cc[i] = 0;
    for(int i = 0;i < len;i ++) ++ cc[x[i] = s[i]];
    for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
    for(int i = len - 1;~i;i --) sa[-- cc[x[i]]] = i;
    for(int k = 1;k < len;k <<= 1)
    {
        int p = 0;
        for(int i = len - k;i < len;i ++)  y[p ++] = i;
        for(int i = 0;i < len;i ++) if(sa[i] >= k) y[p ++] = sa[i] - k;
        for(int i = 0;i < m;i ++) cc[i] = 0;
        for(int i = 0;i < len;i ++) ++ cc[x[y[i]]];
        for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
        for(int i = len - 1;~i;i --) sa[-- cc[x[y[i]]]] = y[i];
        swap(x,y); m = 1; x[sa[0]] = 0;

        for(int i = 1;i < len;i ++)
            x[sa[i]] = cmp(y,sa[i - 1],sa[i],k) ? m - 1 : m ++;
        if(m >= len) break;
    }
}

void get_lcp(int s[])
{
    for(int i = 0;i < len;i ++) rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i = 0;i < len;i ++)
    {
        if(!rank[i]) continue;
        int j = sa[rank[i] - 1];
        if(h) h --;
        while(s[i + h] == s[j + h]) h ++;
        lcp[rank[i]] = h;
    }
}

int k;

bool check(int d)
{
    int x = 0;
    for(int i = 1;i < len;i ++)
    {
        if(lcp[i] >= d)
        {
            if(++ x >= k - 1) return true;
        }
        else x = 0;
    }
    return false;
}

int div()
{
    int l = 0,r = len + 1;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int s[SZ];

int main()
{
    len = read(),k = read();
    for(int i = 0;i < len;i ++)
        s[i] = read();
    get_sa(s); get_lcp(s);
    printf("%d\n",div());
    return 0;
}