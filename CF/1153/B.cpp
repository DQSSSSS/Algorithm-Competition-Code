#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

int a[110],b[110],c[110][110],ans[110][110];

int main() {
    int n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) b[i] = read();
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            c[i][j] = read();
            ans[i][j] = min(a[j],b[i]);
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(c[i][j])
                printf("%d ",ans[i][j]);
            else
                printf("%d ",0);
        }
        puts("");
    }
}
