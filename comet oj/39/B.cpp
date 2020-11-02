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

LL ask(LL r,LL k) {
    if(k & 1) return r + 1;
    r ++;
    LL d = r / (k+1);
    return d * k + r - d * (k+1);
}

int main() {
    int T = read();
    while(T --) {
        LL l = read(),r = read(),k = read();
        printf("%lld\n",ask(r,k) - ask(l-1,k));
    }
    return 0;
}

/**

   1 1 2 3 5 8 13
k  0 1 2 3 4 5 6 7 8 9 10 11 12
1  1 1 1 1 1 1 1 1 1 1 1 1 1 1
2  1 1 0 1 1 0 1 1 0 1 1 0 1 1
3  1 1 1 1 1 1 1
4  1 1 1 1 0 1 1 1 1 0 1 1 1 1 0
*/

