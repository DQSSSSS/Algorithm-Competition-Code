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


set<int> S;

int main()
{
    int n = read();
    S.insert(INF); S.insert(-INF);
    int ans = 0;
    for(int i = 1;i <= n;i ++)
    {
        int x = read();
        if(i == 1) { ans += x; S.insert(x); continue; }
        set<int> :: iterator s = S.lower_bound(x);
        set<int> :: iterator p = s; p --;
        ans += min(abs(*s - x),abs(*p - x));
        S.insert(x);
    }
    printf("%d",ans);
    return 0;
}
