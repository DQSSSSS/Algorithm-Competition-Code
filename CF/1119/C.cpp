#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e3 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ][SZ],b[SZ][SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            a[i][j] = read();

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            b[i][j] = read();

    for(int i = 2;i <= n;i ++)
        for(int j = 2;j <= m;j ++)
            if(a[i][j] != b[i][j]) {
                a[i][j] ^= 1;
                a[i][1] ^= 1;
                a[1][j] ^= 1;
                a[1][1] ^= 1;
            }
    bool flag = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(a[i][j] != b[i][j])
                flag = 1;
    if(flag) puts("No");
    else puts("Yes");
    return 0;
}


