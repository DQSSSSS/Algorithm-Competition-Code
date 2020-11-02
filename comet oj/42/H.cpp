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

int a[SZ],f[SZ][2];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    f[1][0] = 1; f[1][1] = 0;
    for(int i = 2;i <= n;i ++) {
        if(a[i-1] < a[i]) {
            f[i][0] = min(f[i-1][0],f[i-1][1]+1);
            f[i][1] = min(f[i-1][0],f[i-1][1]+1);
        }
        else if(a[i-1] > a[i]) {
            f[i][0] = min(f[i-1][0]+1,f[i-1][1]+1);
            f[i][1] = min(f[i-1][0],f[i-1][1]);
        }
        else {
            f[i][0] = min(f[i-1][0]+1,f[i-1][1]+1);
            f[i][1] = min(f[i-1][0],f[i-1][1]+1);
        }
    }
    int ans = min(f[n][0],f[n][1]);
  //  if(ans == 0) ans = 1;
    cout << ans << endl;
}

/***
5
5 4 3 2 1
*/
