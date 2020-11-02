#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;

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
    LL v;
    int id;
};

vector<haha> to[SZ],bk[SZ];
int s[SZ],t[SZ];

int main()
{
    n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++)
    {
        int x = read(),f = read(),t = read(),c = read();
        if(f == 0) bk[x].push_back((haha){c,t});
        if(t == 0) to[x].push_back((haha){c,f});
    }
    LL ans = 0,tot = 0;
    for(int l = 2;l <= 1000000;l ++)
    {
        int r = l + k - 1;

    }
    return 0;
}
