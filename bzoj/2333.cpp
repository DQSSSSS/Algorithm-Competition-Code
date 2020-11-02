#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;


LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int fa[SZ];
int fad[SZ],faid[SZ],fam[SZ];
int delta[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
    {
        fa[i] = i;
        fad[i] = 0;
        fam[i] = read();
        faid[i] = i;
    }
    int m = read();
    while(m --)
    {
        char opt[3];
        scanf("%s",opt);
        if(opt[0] == 'U')
        {
            int x = read(),y = read();
            merge(x,y);
        }
        else if(opt[0] == 'A')
        {
            int x,y;
            if(opt[1] == '1') x = read(),y = read(),delta
        }
    }
}
