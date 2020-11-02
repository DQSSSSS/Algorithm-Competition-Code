#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
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

int nx[SZ],a[SZ],pos[SZ],n;

struct haha
{
    int l,r,id;
}q[SZ];

bool cmp(haha a,haha b) { return a.l < b.l; }

int bits[SZ];

int ask(int x)
{
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += bits[i];
    return ans;
}

void add(int x,int d)
{
    if(x == 0) return ;
    for(int i = x;i <= n;i += i & -i)
        bits[i] += d;
}

int ans[SZ];

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = n;i >= 1;i --)
        nx[i] = pos[a[i]],pos[a[i]] = i;
    int m = read();
    for(int i = 1;i <= m;i ++)
        q[i].l = read(),q[i].r = read(),q[i].id = i;
    sort(q + 1,q + 1 + m,cmp);

    for(int i = 0;i <= 1e6;i ++)
        if(pos[i])
            add(pos[i],1);
    for(int i = 1,j = 1;i <= m;i ++)
    {
        while(j < q[i].l) add(j,-1),add(nx[j],1),j ++;
        ans[q[i].id] = ask(q[i].r) - ask(q[i].l - 1);
    }
    for(int i = 1;i <= m;i ++) printf("%d\n",ans[i]);
    return 0;
}
