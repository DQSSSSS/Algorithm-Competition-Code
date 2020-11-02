#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int SZ = 1000010;
const int INF = 1e7 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n;
priority_queue<LL> q;

struct haha
{
    LL val,ed;
}l[SZ];

bool cmp(haha a,haha b) { return a.ed < b.ed; }

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        l[i].val = read(),l[i].ed = read();
    sort(l + 1,l + 1 + n,cmp);
    int ans = 0;
    LL now = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(now + l[i].val <= l[i].ed)
            now += l[i].val,ans ++,q.push(l[i].val);
        else
        {
            if(q.empty()) continue;
            LL x = q.top(); q.pop(); now -= x;
            if(l[i].val < x)
                now += l[i].val,q.push(l[i].val);
            else
                q.push(x),now += x;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
1 1 -1 0 -1 -1 1

   -1  0  1
    1  2  1
-2 -1  0
 1  2  1
*/
