#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
const LD eps = 1e-8;
LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int b[SZ];

int main() {
    int n = read(),k = read();
    int ans = 0;
    for(int i = 1;i <= k;i ++) {
        int x = read();
        for(int j = x;j <= n;j += x) {
            b[j] ^= 1;
        }
        int tmp = 0;
        for(int j = 1;j <= n;j ++)
            tmp += b[j];
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}
