#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e6 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int f[SZ],vis[SZ];

int main() {
    f[1] = 0;
    for(int n = 2;n <= 10000;n ++) {
        for(int i = 0;i <= n;i ++) vis[i] = -1;
        for(int i = 1;i < n;i ++) {
            if(n % i == 0) {
                vis[f[n-i]] = 1;
            }
        }
        for(int i = 0;;i ++) {
            if(vis[i] == -1) { f[n] = i; break; }
        }
    }
    for(int i = 1;i <= 10000;i ++) {
        int x = i;
        int t = 0;
        while(x % 2 == 0) x /= 2, t ++;
        assert(t == f[i]);
//        printf("%3d%3d\n",i,f[i]);
    }
}

