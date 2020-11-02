#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

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

int c[20],a[10000010],ans[10000010];

int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        a[i] = read();
        c[a[i]] ++;
    }
    for(int i = 1;i <= 10;i ++)
        c[i] += c[i - 1];
    for(int i = n;i >= 1;i --)
        ans[c[a[i]] --] = a[i];
    for(int i = 1;i <= n;i ++)
        printf("%d\n",ans[i]);
    return 0;
}
