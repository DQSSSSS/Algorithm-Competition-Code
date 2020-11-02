#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct BIT {
    LL tree[SZ];
    int n;

    void add(int x,int d) {
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }

    LL ask(int x) {
        LL ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    void add(int l,int r,int d) {
        add(l,d);
        add(r+1,-d);
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= n;i ++) tree[i] = 0;
    }
}tr;

struct haha {
    int x,y,id,b;
}b[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        int x = read();
        g[x].push_back(i);
    }
    for(int i = 1;i <= m;i ++) {

    }
}
