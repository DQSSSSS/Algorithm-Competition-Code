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

int b[SZ],p[SZ];
int tree[SZ],n;

int add(int x,int d) {
    for(int i = x;i <= n;i += i & -i) tree[i] += d;
}

int ask(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}


int main() {
    n = read();
    for(int i = 1;i <= n;i ++) p[read()] = i;
    for(int i = 1;i <= n;i ++) b[i] = p[read()];
    int ans = 0;
   // for(int i = 1;i <= n;i ++) cout << b[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) {
        int x = b[i];
        if(ask(x) != x - 1) {
            ans ++;
        }
        add(x,1);
    }
    cout << ans << endl;
}

