#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 332748118;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ],use[SZ],b[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),use[i] = 0;
        for(int i = 1;i <= n+1;i ++) b[i] = use[i] = 0;

        set<pii> s;
        for(int i = n;i >= 1;i --) {
            if(s.size()) {
                auto it = s.lower_bound(make_pair(a[i],i));
                if(it != s.end()) {
                    b[i] = it -> second;
                }
                else b[i] = n + 1;
            }
            s.insert(make_pair(a[i],i));
        }

        int x = a[1],len1 = 1,pos = 1;
        use[1] = 1;
        while(pos) {
            pos = b[pos];
            x = a[pos]; len1 ++;
            use[pos] = 1;
        }

        bool flag = 0;
        for(int i = 1,x = -1;i <= n;i ++) {
            if(!use[i]) {
                if(a[i] <= x) { flag = 1; break; }
                x = a[i];
            }
        }

        if(flag) puts("-1");
        else printf("%d\n",abs(len1-(n-len1)));
    }
}
