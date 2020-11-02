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

int X[SZ],Y[SZ];

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) X[i] = read(),Y[i] = read();
        vector<pii> g;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                if(X[j] < X[i] && Y[j] > Y[i]) {
                    int dx = X[j] - X[i];
                    int dy = Y[j] - Y[i];
                    int d = __gcd(dx,dy);
                    dx /= d; dy /= d;
                    g.push_back(make_pair(dx,dy));
                }
            }
        }
        sort(g.begin(),g.end());
        int ans = unique(g.begin(),g.end())-g.begin() + 1;
        printf("Case #%d: %d\n",++ cc,ans);
    }
    return 0;
}
