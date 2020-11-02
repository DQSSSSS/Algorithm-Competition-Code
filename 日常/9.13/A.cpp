#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 300010;
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

bool operator <(haha a,haha b) { return a.v < b.v; }

priority_queue<haha> q;

int s[SZ],a[SZ];

int main()
{
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++)
        a[i] = read();
    for(int i = 1;i <= k;i ++)
        q.push((haha){a[i],i});
    LL ans = 0;

    for(int i = k + 1;i <= n + k;i ++)
    {
        if(i <= n)
            q.push((haha){a[i],i});
        ans += q.top().v * (i - q.top().id);
        s[q.top().id] = i;
        q.pop();
    }
    printf("%I64d\n",ans);
    for(int i = 1;i <= n;i ++)
        printf("%d ",s[i]);
    return 0;
}
