#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
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

map<int,int> mp;

int a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        mp.clear();
        int minn = 1e9;
        for(int i = 1;i <= n;i ++) {
            int x = a[i] = read();
            minn = min(minn,x);
            for(int j = 2;j * j <= x;j ++) {
                if(x%j==0) {
                    int t = 0;
                    while(x%j==0) x/=j,t++;
                    mp[j] = max(mp[j],t);
                }
            }
            if(x != 1) mp[x] = max(mp[x],1);
        }

        if(mp.size() == 1) {
            int x = mp.begin()->second;
            if(x!=n) { puts("-1"); continue; }
            LL ans = 1; x ++;
            while(x--) ans *= mp.begin()->first;
            printf("%lld\n",ans);
            continue;
        }

        LL ys = 1,ans = 1;
        bool flag = 0;
        for(auto it = mp.begin();it != mp.end();it ++) {
            ys *= (it -> second + 1);
            if(ys > n+2) { flag = 1; break; }
            int x = it -> second;
            while(x--) ans *= it->first;
        }
        if(ys != n+2) flag = 1;
        for(int i = 1;i <= n;i ++) if(a[i] == ans) flag = 1;
        if(flag) puts("-1");
        else {
            printf("%lld\n",ans);
        }
    }
}
