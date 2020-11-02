#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2010;
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

unordered_map<int,int> mp;

int main() {
    int A = read(),B = read(),C = read();
    mp[1] = 0;
    int x = 1;
    for(int i = 1;i <= 200000;i ++) {
        x = (1ll*A*x+x%B) % C;
        if(mp.count(x)) {
            cout << i << endl;
            return 0;
        }
        mp[x] = 1;
    }
    puts("-1");
}
