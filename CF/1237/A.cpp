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

vector<int> g[SZ];
int use[SZ];

int main() {
    int n = read(),t = 0;
    for(int i = 1;i <= n;i ++) {
        int d = read();
        int x = abs(d);
        if(x&1) {
            int b = d < 0 ? -1 : 1;
            g[i].push_back(b * (x)/2);
            g[i].push_back(b * (x+1)/2);
        }
        else {
            g[i].push_back(d/2);
            g[i].push_back(d/2);
        }
        t += g[i][0];
    }

    for(int i = 1;i <= n;i ++) {
        int t2 = t - g[i][0] + g[i][1];
        if(abs(t) > abs(t2)) {
            use[i] = 1;
            t = t2;
        }
    }

    for(int i = 1;i <= n;i ++) {
        printf("%d\n",g[i][use[i]]);
    }

}
