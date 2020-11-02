#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
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

int n;
int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
bool is[SZ];

int main()
{
    n = read();
    for(int i = 1;i <= 10000;i ++) fa[i] = i;
    for(int i = 1;i <= n;i ++)
    {
        int a = read(),b = read();
        int x = find(a),y = find(b);
        if(x == y) is[x] = 1;
        else
        {
            if(x > y) swap(x,y);
            is[y] |= is[x];
            fa[x] = y;
        }
    }
    for(int i = 1;i <= 10000;i ++)
    {
        int x = find(i);
        if(is[x]) continue;
        if(x == i) { printf("%d\n",i - 1); return 0; }
    }
    printf("%d",10000);
    return 0;
}
