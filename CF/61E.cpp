#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int tree[SZ],L[SZ],R[SZ],n,lsh[SZ],a[SZ];

void add(int x,int d) {
    for(int i = x;i <= n;i += i & -i) tree[i] += d;
}

int ask(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) lsh[i] = a[i] = read();
    sort(lsh + 1,lsh + 1 + n);
    int m = unique(lsh + 1,lsh + 1 + n) - lsh - 1;
    for(int i = 1;i <= n;i ++) a[i] = lower_bound(lsh + 1,lsh + 1 + n,a[i]) - lsh;
    for(int i = 1;i <= n;i ++) {
        L[i] = i - 1 - ask(a[i]);
        add(a[i],1);
    }
    for(int i = 1;i <= n;i ++) tree[i] = 0;
    LL ans = 0;
    for(int i = n;i >= 1;i --) {
        R[i] = ask(a[i]);
        add(a[i],1);
        ans += 1ll * R[i] * L[i];
    }
    cout << ans << endl;
}
