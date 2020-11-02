#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;

typedef unsigned long long ULL;
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

char s[SZ];

int main()
{
    scanf("%s",s);
    LL len = strlen(s);
    LL lx = 1,ly = 1,rx = 1ll << len,ry = 1ll << len;
    for(int i = 0;i < len;i ++)
    {
        LL d = (rx - lx + 1) / 2;
        if(s[i] == '0') rx -= d,ry -= d;
        if(s[i] == '1') ly += d,rx -= d;
        if(s[i] == '2') lx += d,ry -= d;
        if(s[i] == '3') lx += d,ly += d;
    //    cout << lx << " " << ly << " " << rx << " " << ry << endl;
    }
    printf("%I64d %I64d %I64d\n",len,ry - 1,rx - 1);
    return 0;
}
