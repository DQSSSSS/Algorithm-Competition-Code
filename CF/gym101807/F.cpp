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

int X[SZ],Y[SZ],b[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n/2;i ++) X[i] = read(),Y[i]  = read();
    for(int i = 1;i <= n;i ++) {
        int x = read(),y = read(),z = read();
        b[i] = x;
    }
    for(int i = 1;i <= n/2;i ++) {
        if(b[X[i]] < b[Y[i]]) swap(X[i],Y[i]);
    }
    for(int i = 1;i <= n;i ++) {
        int ans1 = 0,ans2 = 0;
        for(int j = 1;j <= n;j ++) {
            if(b[j] > b[i] + 3) ans1 ++;
            if(b[j] >= b[i]) ans2 ++;
        }
        ans1 ++;
        int fen = b[i];
       // cout <<ans1 << " " << ans2 << endl;
        for(int j = 1;j <= n/2;j ++) {
            int x = b[X[j]],y = b[Y[j]];

            if(X[j] == i || Y[j] == i) {
                int r = X[j]^Y[j]^i;
                if(b[r] < fen && b[r] >= fen-3) ans2 ++;
                continue;
            }

            if(x == fen + 3) {
                if(y == fen + 1
                   || y == fen + 2
                   || y == fen + 3) ans1 ++;
            }

            if(x == fen - 1) {
                if(y == fen - 1) ans2 += 2;
                else ans2 ++;
            }
            else if(x < fen-1 && x >= fen-3) {
                ans2 ++;
            }
            else if(x >= fen) {
                if(y <= fen-1 && y >= fen-3) ans2 ++;
            }
           // cout << j << " [" << ans2 << endl;
        }
        printf("%d %d\n",ans1,ans2);
    }
}
