#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

int main() {
    int n = read();
    scanf("%s",s + 1);
    if(n < 5) return puts("0"),0;
    if(ok(1,5)) f[5][31] = 1;
    f[5][0] = 0;
    int ans = 0;
    for(int i = 6;i <= n;i ++) {
        for(int j = i-1;j >= i-4;j --) {

        }
    }
}
