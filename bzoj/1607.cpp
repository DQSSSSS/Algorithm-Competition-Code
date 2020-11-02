#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar();  }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int val[SZ];

int t[SZ],ans[SZ],n;

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        val[i] = read(),t[val[i]] ++;
    for(int i = 1;i <= 1e6;i ++)
        if(t[i])
            for(int j = i;j <= 1e6;j += i)
                ans[j] += t[i];
    for(int i = 1;i <= n;i ++)
        printf("%d\n",ans[val[i]] - 1);
    return 0;
}
