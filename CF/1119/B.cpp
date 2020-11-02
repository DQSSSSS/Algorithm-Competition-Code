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

int a[SZ],b[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();

    int ans = 1;
    for(int k = 2;k <= n;k ++) {
        for(int j = 1;j <= k;j ++) b[j] = a[j];
        sort(b + 1,b + 1 + k);
        LL sum = 0;
        for(int i = k;i >= 1;i -= 2) {
            sum += b[i];
        }
        if(sum > m) break;
        else ans = k;
    }
    cout << ans << endl;
    return 0;
}

