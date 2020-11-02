#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int g[SZ];

bool check(int n)
{
    sort(g + 1,g + 1 + n);
    //if(n == 1 && g[1]) return false;
    int sum = 0;
    for(int j = 1;j <= n;j ++)
    {
        sum += g[j];
        if(sum < j * (j - 1)) return false;
    }
    if(sum != n * (n - 1)) return false;
    return true;
}

int n,m;

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i ++)
        {
            int k;
            scanf("%d",&k);
            for(int j = 1;j <= k;j ++)
                scanf("%d",&g[j]);
            puts(check(k) ? "T" : "F");
        }
    }
    return 0;
}
