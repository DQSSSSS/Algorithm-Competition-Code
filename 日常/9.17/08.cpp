#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;
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

map<string,int> mp;

int main()
{
    mp["rat"] = 1;
    mp["ox"] = 2;
    mp["tiger"] = 3;
    mp["rabbit"] = 4;
    mp["dragon"] = 5;
    mp["snake"] = 6;
    mp["horse"] = 7;
    mp["sheep"] = 8;
    mp["monkey"] = 9;
    mp["rooster"] = 10;
    mp["dog"] = 11;
    mp["pig"] = 12;
    int T = read();
    while(T --)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int ans = mp[s2] - mp[s1];
        if(ans < 0) ans += 12;
        if(ans == 0) puts("12");
        else printf("%d\n",ans);
    }
    return 0;
}
