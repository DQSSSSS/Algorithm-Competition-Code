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

multiset<int> s;
int l[SZ],r[SZ],c[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) l[i] = n + 1;
    for(int i = 1;i <= n;i ++) {
        int x = read();
        c[x] = 1;
        l[x] = min(l[x],i);
        r[x] = max(r[x],i);
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) if(c[i]) s.insert(r[i]);
    for(int i = 1;i <= n;i ++) if(c[i]) {
        auto it = s.find(r[i]); s.erase(it);
        it = s.end(); it --;
        ans = max(ans,*it - l[i]);
        s.insert(r[i]);
    }
    cout << ans << endl;
    return 0;
}
