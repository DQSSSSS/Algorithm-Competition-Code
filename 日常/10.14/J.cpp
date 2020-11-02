#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;
LL k;

int head[SZ],nxt[SZ],to[SZ],tot = 1;

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

int bits[SZ];

void add(int x,int d)
{
    for(int i = x;i <= m;i += i & -i)
        bits[i] += d;
}

LL ask(int x)
{
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += bits[i];
    return ans;
}


LL a[SZ],lsh[SZ],ans;

int getid(LL x)
{
    return lower_bound(lsh + 1,lsh + 1 + m,x) - lsh;
}

int fa[SZ];

void dfs(int u,int fa)
{
    ans += ask(a[u] ? getid(k / a[u]) : m);

//    cout << u << " " << ans << endl;
//    for(int i = 1;i <= m;i ++) printf("%d ",ask(i)); puts("");

//    cout << u << " " << ask(getid(k / a[u])) << endl;
    add(getid(a[u]),1);
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v == fa) continue;
        dfs(v,u);
    }
    add(getid(a[u]),-1);
}

int main()
{
    int T = read();
    while(T --)
    {
        n = read(),k = read();

        tot = 1; ans = 0;
        for(int i = 0;i <= 2 * n;i ++) fa[i] = head[i] = bits[i] = lsh[i] = 0;

        for(int i = 1;i <= n;i ++)
        {
            a[i] = read();
            lsh[++ lsh[0]] = a[i];
            if(a[i]) lsh[++ lsh[0]] = k / a[i];
        }
        sort(lsh + 1,lsh + 1 + lsh[0]);
        m = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;

        for(int i = 1;i < n;i ++)
        {
            int x = read(),y = read();
            build(x,y);
            fa[y] = x;
        }
        for(int i = 1;i <= n;i ++)
            if(!fa[i])
                dfs(i,0);
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
233
6 1000000000000000000
1000000000000000000 1 2 3 4 5
1 2
1 3
3 4
3 5
5 6

*/
