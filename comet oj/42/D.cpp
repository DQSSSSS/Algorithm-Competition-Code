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

int a[SZ];

int main() {
    for(int i = 0;i < 18;i ++) {
        a[read()] ++;
    }
    int ans = 0;
    for(int i = 1;i <= 13;i ++) {
        int x = a[i];
        x %= 2;
        ans += x;
    }
    cout << ans + a[0];

}
