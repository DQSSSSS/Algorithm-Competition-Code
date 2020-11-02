#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ],b[SZ],p[SZ],pri[SZ],vis[SZ];

int main() {
    int n = read(),x = read();
    for(int i = 1,j = 0;i < (1<<n);i ++) {
        if(i == x) continue;
        else {
            if(x < (1<<n)) {
                int ii = x ^ i;
                if(ii < i) a[++ a[0]] = i;
            }
            else a[++ a[0]] = i;
        }
    }
    for(int i = a[0];i >= 2;i --) a[i] ^= a[i-1];

    printf("%d\n",a[0]);
    for(int i = 1;i <= a[0];i ++) printf("%d ",a[i]);
    return 0;
}



