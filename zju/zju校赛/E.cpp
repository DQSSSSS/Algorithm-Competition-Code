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

LL a[SZ],b[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) b[i] = read();
        bool flag = 0;
        for(int i = 1;i <= n;i ++) {
            if(b[i] >= a[i]) continue;
            LL x = a[i] - b[i];
            for(int j = i + 1;j <= n && x;j ++) {
                LL d = min(b[j],x);
                b[j] -= d;
                x -= d;
            }
            if(x) { flag = 1; break; }
        }
        puts(flag ? "No" : "Yes");
    }
}

