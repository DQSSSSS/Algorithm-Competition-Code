#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 500010;
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

string s[110];

int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        cin >> s[i];
        bool flag = 0;
        for(int j = 0;j < i;j ++)
            if(s[j] == s[i]) { flag = 1; break; }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
