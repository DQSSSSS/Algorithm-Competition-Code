#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const int INF = 1000000010;
const LL mod = 998244353;

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

map<LL,int> mp;
string s[SZ];
LL mi[30];

int main()
{
    int n = read();
    mi[0] = 1;
    for(int i = 1;i <= 10;i ++) mi[i] = mi[i - 1] * 233 % mod;
    for(int i = 1;i <= n;i ++)
    {
        cin >> s[i];
        for(int len = 1;len <= 9;len ++)
        {
            LL h = 0;
            for(int j = 0;j < len;j ++)
                (h += (LL)s[i][j] * mi[len - j - 1] % mod) %= mod;
            mp[h] ++;
            for(int j = 1;j < 9 - len + 1;j ++)
            {
                ((h -= s[i][j - 1] * mi[len - 1] % mod) += mod) %= mod;
                (h *= 233) %= mod;
                (h += s[i][j + len - 1]) %= mod;
                mp[h] ++;
            }
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int len = 1;len <= 9;len ++)
        {
            LL h = 0;
            for(int j = 0;j < len;j ++)
                (h += (LL)s[i][j] * mi[len - j - 1] % mod) %= mod;
            mp[h] --;
            for(int j = 1;j < 9 - len + 1;j ++)
            {
                ((h -= s[i][j - 1] * mi[len - 1] % mod) += mod) %= mod;
                (h *= 233) %= mod;
                (h += s[i][j + len - 1]) %= mod;
                mp[h] --;
            }
        }

        for(int len = 1;len <= 9;len ++)
        {
            LL h = 0;
            for(int j = 0;j < len;j ++)
                (h += (LL)s[i][j] * mi[len - j - 1] % mod) %= mod;
            if(!mp[h]) { cout << s[i].substr(0,len) << endl; break; }
            bool flag = 0;
            for(int j = 1;j < 9 - len + 1;j ++)
            {
                ((h -= s[i][j - 1] * mi[len - 1] % mod) += mod) %= mod;
                (h *= 233) %= mod;
                (h += s[i][j + len - 1]) %= mod;
                if(!mp[h]) { cout << s[i].substr(j,len) << endl; flag = 1; break; }
            }
            if(flag) break;
        }


        for(int len = 1;len <= 9;len ++)
        {
            LL h = 0;
            for(int j = 0;j < len;j ++)
                (h += (LL)s[i][j] * mi[len - j - 1] % mod) %= mod;
            mp[h] ++;
            for(int j = 1;j < 9 - len + 1;j ++)
            {
                ((h -= s[i][j - 1] * mi[len - 1] % mod) += mod) %= mod;
                (h *= 233) %= mod;
                (h += s[i][j + len - 1]) %= mod;
                mp[h] ++;
            }
        }
    }

    return 0;
}
