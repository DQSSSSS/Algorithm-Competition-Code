#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#include<set>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 500010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};


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


set<int> s[2];

int main()
{
    int n = read();
    int ans = 0;
    for(int i = 1;i <= n;i ++)
    {
        int id = read(),x = read();
        if(s[id ^ 1].empty())
            s[id].insert(x);

        set<int> :: iterator suf = s[id ^ 1].lower_bound(x);
        set<int> :: iterator pre = suf;
        int tmp = INF,flag = -1;

        if(pre != s[id ^ 1].begin())
        {
            pre --;
            if(tmp >= abs(*pre - x))
                tmp = abs(*pre - x),flag = 1;
        }

        if(suf != s[id ^ 1].end())
            if(tmp > abs(*suf - x))
                tmp = abs(*suf - x),flag = 0;

        if(flag == 0) s[id ^ 1].erase(suf);
        if(flag == 1) s[id ^ 1].erase(pre);
        if(tmp != INF)
            (ans += tmp) %= 1000000;
    }
    printf("%d\n",ans);
    return 0;
}
