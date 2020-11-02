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

set<int> ha,sa,hb,sb;

int work(set<int> &h,set<int> &s) {
    int ans = 0;
    for(int x : h) {
        auto it = s.lower_bound(x);
        if(it == s.end()) continue;
        ans ++;
        s.erase(it);
    }
    return ans;
}

int a[SZ],b[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= m;i ++) b[i] = read();
        ha.clear(); hb.clear();
        sa.clear(); sb.clear();
        for(int i = 1;i <= n;i ++) {
            int x = read();
            if(x == 1) ha.insert(a[i]);
            else sa.insert(a[i]);
        }
        for(int i = 1;i <= m;i ++) {
            int x = read();
            if(x == 1) hb.insert(b[i]);
            else sb.insert(b[i]);
        }
        int ans = work(ha,sb) + work(hb,sa);
        printf("%d\n",ans);
    }
}
