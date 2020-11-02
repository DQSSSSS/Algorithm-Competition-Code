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

multiset<int> s;

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) s.insert(read());
    int ans = 0;
    for(int i = 1;s.size();i ++) {
        auto it = s.lower_bound(i);
        if(it == s.end()) break;
        ans ++;
        s.erase(it);
    }
    cout << ans << endl;
}
