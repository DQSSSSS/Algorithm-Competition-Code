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

LL tree[SZ],lsh[SZ];

void add(int x,int d) {
    for(int i = x;i <= lsh[0];i += i&-i)
        tree[i] += d;
}

LL ask(int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i&-i)
        ans += tree[i];
    return ans;
}

pii a[SZ];

int main() {
    LL n = read(),m = read();
    n = read(),m = read();

    LL ans = 1ll * (n+1) * (m+1);

    for(int i = 1;i <= n;i ++) {
        a[i].first = read(),a[i].second = read();
        lsh[++ lsh[0]] = a[i].second;
    }
    sort(lsh + 1,lsh + 1 + lsh[0]);
    sort(a + 1,a + 1 + n);
    lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
    for(int i = n;i >= 1;i --) {
        a[i].second = lower_bound(lsh + 1,lsh + 1 + lsh[0],a[i].second) - lsh;
        ans += ask(a[i].second);
        add(a[i].second,1);
    }

    lsh[0] = 0;
    memset(tree,0,sizeof tree);
    for(int i = 1;i <= m;i ++) {
        a[i].first = read(),a[i].second = read();
        lsh[++ lsh[0]] = a[i].second;
    }
    sort(lsh + 1,lsh + 1 + lsh[0]);
    sort(a + 1,a + 1 + m);
    lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
    for(int i = m;i >= 1;i --) {
        a[i].second = lower_bound(lsh + 1,lsh + 1 + lsh[0],a[i].second) - lsh;
        ans += ask(a[i].second);
        add(a[i].second,1);
    }
    cout << ans << endl;
}
