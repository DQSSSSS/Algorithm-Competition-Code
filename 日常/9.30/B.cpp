#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
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

int n;

struct haha
{
    int x,y,id;
}l[SZ];

bool cmp1(haha a,haha b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool cmp2(haha a,haha b) { return a.y == b.y ? a.x < b.x : a.y < b.y; }

LL dis(haha a,haha b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

LL work1()
{
    sort(l + 1,l + 1 + n,cmp1);
    LL ans = INF;
    puts("");
    for(int i = 1;i < n;i ++)
        cout << l[i].id << " " << l[i + 1].id << endl,ans = min(ans,dis(l[i],l[i + 1]));
    return ans;
}

LL work2()
{
    sort(l + 1,l + 1 + n,cmp2);
    LL ans = INF;
    for(int i = 1;i < n;i ++)
        cout << l[i].id << " " << l[i + 1].id << endl,ans = min(ans,dis(l[i],l[i + 1]));
    return ans;
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        l[i].x = read(),l[i].y = read(),l[i].id = i;
    printf("%lld %lld\n",work1(),work2());
    return 0;
}
