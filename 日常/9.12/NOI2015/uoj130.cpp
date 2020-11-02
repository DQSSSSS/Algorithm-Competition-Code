#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 3000010;
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

LL a[SZ],k,n;

struct haha
{
    LL v,d;
};

bool operator <(haha a,haha b)
{
    if(a.v != b.v) return a.v > b.v;
    return a.d > b.d;
}

priority_queue<haha> q;

int main()
{
    n = read(),k = read();
    for(int i = 1;i <= n;i ++)
    {
        LL x = read();
        q.push((haha){x,0});
    }
    LL ans = 0;
    if((n - 1) % (k - 1))
    {
        LL val = 0,d = 0;
        for(int j = 1;j <= (n - 1) % (k - 1) + 1;j ++)
            val += q.top().v,d = max(d,q.top().d),q.pop();
        ans += val; q.push((haha){val,d + 1});
    }
    for(int j = 1;j <= (n - 1) / (k - 1);j ++)
    {
        LL val = 0,d = 0;
        for(int j = 1;j <= k;j ++)
            val += q.top().v,d = max(d,q.top().d),q.pop();
        ans += val; q.push((haha){val,d + 1});
    }
    printf("%lld\n%lld\n",ans,q.top().d);
    return 0;
}
