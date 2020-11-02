#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
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

map<int,bool> mp;

int main() {
    int T = read();
    LL ans = 0,lx = 0,ly = 0,flag = 1;
    while(T --) {
        LL x = read(),y = read();
        LL tmp = min(x,y)-max(lx,ly) + 1;
        if(mp[max(lx,ly)]) tmp --;
        if(mp[min(x,y)]) tmp --;
        if(tmp > 0)
            mp[min(x,y)] = mp[max(lx,ly)] = 1;
        ans += max(0ll,tmp);
        lx = x;
        ly = y;
    }
    cout << ans << endl;
}
/**
5
0 0
1 1
2 2
3 3
4 4
*/
