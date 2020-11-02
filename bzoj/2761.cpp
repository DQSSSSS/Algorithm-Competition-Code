#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

map<int,bool> mp;

int n,m,a[SZ],b[SZ];

int main()
{
    int T = read();
    while(T --)
    {
        mp.clear();
        n = read();
        int tot = 0;
        for(int i = 1;i <= n;i ++)
        {
            a[i] = read();
            if(mp[a[i]]) continue;
            else mp[a[i]] = 1,b[++ tot] = a[i];
        }
        for(int i = 1;i <= tot;i ++)
            printf("%d%c",b[i],i == tot ? '\n' : ' ');
    }
    return 0;
}
