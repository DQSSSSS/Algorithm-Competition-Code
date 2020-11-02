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

map<int,int> mp,mp2;

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read(),k = read();
        mp.clear();
        mp2.clear();
        for(int i = 1;i <= n;i ++) {
            int x = read();
            mp[x] ++;
            if(i <= (n+1)/2) mp2[x] ++;
        }
        int ans = 0;
        for(auto it = mp.begin();it != mp.end();it ++) {
            ans += min(it -> second / k,mp2[it->first]);
        }
        printf("%d\n",ans);
    }
}

