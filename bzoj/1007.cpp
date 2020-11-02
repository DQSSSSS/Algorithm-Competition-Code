#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
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

struct haha
{
    double k,b;
    int id;
}l[SZ];

bool cmp(haha a,haha b)
{
    return a.k == b.k ? a.b > b.b : a.k < b.k;
}

bool cmp2(int a,int b)
{
    return l[a].id < l[b].id;
}

int S[SZ];

double calc(int i,int j)
{
    double k1 = l[i].k,k2 = l[j].k;
    double b1 = l[i].b,b2 = l[j].b;
    return (b2 - b1) / (k1 - k2);
}

int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
        l[i].k = read(),l[i].b = read(),l[i].id = i;
    sort(l + 1,l + 1 + n,cmp);
    int top = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(top < 2) { S[++ top] = i; continue; }
        if(l[i].k == l[i - 1].k) continue;
        while(top >= 2 && calc(i,S[top]) <= calc(S[top],S[top - 1]))
            top --;
        S[++ top] = i;
    }
    sort(S + 1,S + 1 + top,cmp2);
    for(int i = 1;i <= top;i ++)
        printf("%d ",l[S[i]].id);
    return 0;
}
