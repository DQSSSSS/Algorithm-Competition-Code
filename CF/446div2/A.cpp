#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 100010;
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

pii a[SZ];
int n;
bool check()
{
    if(n <= 2) return true;
    LL sum = 0;
    for(int i = 1;i <= n - 2;i ++) sum += a[i].y;
    LL d = a[n - 1].x - a[n - 1].y + a[n].x - a[n].y;
    if(sum <= d) return true;
    return false;
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++) a[i].y = read();
    for(int i = 1;i <= n;i ++) a[i].x = read();
    sort(a + 1,a + 1 + n);
    puts(check() ? "YES" : "NO");
    return 0;
}
