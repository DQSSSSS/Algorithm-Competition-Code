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

int n,k;
LL a[SZ];

multiset<LL> s;


bool can(LL x)
{
    for(int i = 1;i < k;i ++)
    {
        multiset<LL> :: iterator it = s.lower_bound(2 * x);
        if(it == s.end()) return false;
        x = *it;
        s.erase(it);
    }
    return true;
}

bool check(int mid)
{
    s.clear();
    for(int i = mid + 1;i <= n;i ++) s.insert(a[i]);
    for(int i = 1;i <= mid;i ++)
        if(!can(a[i])) return false;
    return true;
}

int div()
{
    int l = 1,r = n + 1;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main()
{
    int T = read();
    for(int cc = 1;cc <= T;cc ++)
    {
        n = read(),k = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        sort(a + 1,a + 1 + n);
        int ans = div();
        printf("Case #%d: %d\n",cc,ans);
    }
    return 0;
}
