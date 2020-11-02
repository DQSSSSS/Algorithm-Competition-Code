#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int tree[SZ],n;

void add(int x,int d) {
    for(int i = x;i <= n;i += i & -i) tree[i] += d;
}

int ask(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += tree[i];
    return ans;
}

int a[SZ],sum[SZ],use[SZ];

int main() {
    n = read();
    int numk = 0;
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        if(a[i] != -1) use[a[i]] = 1;
        else numk ++;
    }
    LL ans = 0;
    for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + (use[i] ? 0 : 1);
    for(int i = 1,s = 0;i <= n;i ++) {
        if(a[i] == -1) {
            (ans += s) %= mod;
        }
        else {
            (s += sum[a[i]]) %= mod;
        }
    }
    int tmp = 0;
    for(int i = n;i >= 1;i --) sum[i] = sum[i + 1] + (use[i] ? 0 : 1);
    for(int i = n,s = 0;i >= 1;i --) {
        if(a[i] == -1) {
            (ans += s) %= mod;
        }
        else {
            (s += sum[a[i]]) %= mod;
            (tmp += ask(a[i])) %= mod;
            add(a[i],1);
        }
    }
    (ans *= ksm(numk,mod - 2)) %= mod;
    (ans += 1ll * numk * (numk - 1) % mod * ksm(4,mod - 2) % mod) %= mod;
    (ans += tmp) %= mod;
    cout << ans << endl;
    return 0;
}
