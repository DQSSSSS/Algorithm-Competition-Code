#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

LL a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        LL d = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        sort(a+1,a+1+n);
        for(int i = 1;i <= n;i ++) a[i] -= (i-1)*d;
        LL ans = 0,start = 0;
        for(int i = 1;i <= n;i ++) {
            LL x = max(a[i],0ll);
            ans += x - a[i];
            a[i] = x;
        }
        multiset<LL> s;
        for(int i = 1;i <= n;i ++) {
            LL x = a[i];
            s.insert(x); s.insert(x);
            start += x;
            while(s.size() > i) {
                s.erase(prev(s.end()));
            }
        }
        LL lst = 0,now = -n;
        for(LL x : s) {
            start += now * (x - lst);
            now ++; lst = x;
        }
        ans += start;
        printf("%lld\n",ans);
    }
}
/*
2
4 1
0 0 0 0
4 10
1 100 5 10
*/
