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

vector<LL> g;

int main() {
    int x = read();
    int t = 0;
    while(1) {
        int y = (x&-x)-1;
        if(__builtin_popcount(x) == 1) {
            t ++;
            g.push_back((LL)log2(y+1));
            break;
        }
        x ^= y;
        x ++;
        g.push_back((LL)log2(y+1));
        t += 2;
    }
    cout << t << endl;
    if(t) {
        for(int d : g)
            cout << d << " ";
    }
    return 0;
}

