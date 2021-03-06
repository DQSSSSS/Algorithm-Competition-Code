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

int a[SZ];

int main() {
    int n = read() * 2;
    for(int i = 1;i <= n;i ++) a[i] = read();
    sort(a+1,a+1+n);
    LL sum = 0;
    for(int i = 1;i <= n/2;i ++) sum += a[i];
    for(int i = n/2+1;i <= n;i ++) sum -= a[i];
    if(sum) {
        for(int i = 1;i <= n;i ++) printf("%d ",a[i]);
    }
    else puts("-1");
    return 0;
}
