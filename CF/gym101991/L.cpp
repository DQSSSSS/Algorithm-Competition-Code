#include <bits/stdc++.h>
using namespace std;

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

int a[SZ],use[SZ];

int main() {
    freopen("looking.in","r",stdin);
    int T = read();
    while(T --) {
        int n = read(),k = read();
        int ans = 0;
        for(int i = 1;i <= n;i ++) ans |= read();
        printf("%d\n",ans);
        /*int ans = 0;
        for(int k = 19;k >= 0;k --) {
            if(ans >> k & 1) continue;
            int maxn = 0,id = 0;
            for(int i = 1;i <= n;i ++) {
                if(use[i]) continue;
                if(a[i] >> k & 1) {
                    int x = a[i] & ((1<<(k+1))-1);
                    if(x > maxn) maxn = x,id = i;
                }
            }
        }*/
    }
}
