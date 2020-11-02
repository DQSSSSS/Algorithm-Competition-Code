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

int a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 0;i < n;i ++) a[i] = read();
        int ans = 0;
        for(int S = 0;S < (1<<n);S ++) {
            int t = 0;
            for(int i = 0;i < n;i ++) {
                if(S >> i & 1) {
                    t ++;
                }
            }
            bool flag = 1;
            for(int i = 0;i < n;i ++) {
                if(S >> i & 1)
                    for(int j = i+1;j < n;j ++) {
                        if(S >> j & 1) {
                            if(__gcd(a[i],a[j]) != 1) flag = 0;
                        }
                    }
            }
            if(flag)
                ans = max(ans,t);
        }
        printf("%d\n",ans);
    }
}

