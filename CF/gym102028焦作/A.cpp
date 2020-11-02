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

int main() {
    int T = read();
    while(T --) {
        int ans = 0;
        for(int i = 1;i <= 4;i ++) {
            int x = read();
            if(x) ans ++;
        }
        if(ans == 0) puts("Typically Otaku");
        else if(ans == 1) puts("Eye-opener");
        else if(ans == 2) puts("Young Traveller");
        else if(ans == 3) puts("Excellent Traveller");
        else puts("Contemporary Xu Xiake");
    }
}
