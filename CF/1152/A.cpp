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


int main() {
    int n = read(),m = read();
    int ji1 = 0,ji2 = 0,ou1 = 0,ou2 = 0;
    for(int i = 1;i <= n;i ++) {
        int x = read();
        if(x & 1) ji1 ++;
        else ou1 ++;
    }
    for(int i = 1;i <= m;i ++) {
        int x = read();
        if(x & 1) ji2 ++;
        else ou2 ++;
    }
    cout << min(ji1,ou2) + min(ou1,ji2) << endl;
    return 0;
}
