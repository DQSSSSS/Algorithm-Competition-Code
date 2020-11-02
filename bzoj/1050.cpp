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

struct edge
{
    int f,t,d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d < b.d; }

int n,m,fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int gcd(int a,int b) { return b == 0 ? a : gcd(b,a % b); }

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= m;i ++)
        l[i].f = read(),l[i].t = read(),l[i].d = read();
    int s = read(),t = read();

    sort(l + 1,l + 1 + m,cmp);
    int maxn = 30000,minn = 1,d;
    for(int i = 1;i <= m;i ++)
    {
        for(int j = 1;j <= n;j ++) fa[j] = j;
        int tmp = -1;
        for(int j = i;j <= m;j ++)
        {
            int x = find(l[j].f),y = find(l[j].t);
            if(x != y)
            {
                fa[x] = y;
                if(find(s) == find(t)) {tmp = j; break;}
            }
        }
        if(tmp == -1) break;
        if((double)maxn / minn > (double)l[tmp].d / l[i].d)
            maxn = l[tmp].d,minn = l[i].d;
    }
    if(maxn != 30000)
    {
        d = gcd(maxn,minn);
        if(minn == d)
            printf("%d\n",maxn / d);
        else
            printf("%d/%d\n",maxn / d,minn / d);
    }
    else puts("IMPOSSIBLE");
    return 0;
}
