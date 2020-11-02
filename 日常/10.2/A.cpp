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

bool use[SZ];
int a[SZ];

struct haha
{
    int pos;
};

priority_queue<haha> q;

bool operator <(haha x,haha y) { return a[x.pos] > a[y.pos];}


int main()
{
    freopen("A.in","r",stdin);
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++)
        if(a[i] < 0 && !use[i]) use[i] = 1,q.push((haha){i});
    int ans = 0;
    while(q.size())
    {
        int pos = q.top().pos; q.pop();
        ans ++;
        use[pos] = 0;
        if(a[pos] < 0)
        {
            int x = -a[pos];
            int l = pos == 1 ? n : pos - 1,r = pos == n ? 1 : pos + 1;
            a[pos] = x;
            a[l] -= x; a[r] -= x;
            if(!use[l] && a[l] < 0) use[l] = 1,q.push((haha){l});
            if(!use[r] && a[r] < 0) use[r] = 1,q.push((haha){r});
        }
    }
    printf("%d\n",ans);
    return 0;
}
