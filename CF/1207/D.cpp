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

pii a[SZ];
int fac[SZ];

LL work(pii a[],int n) {
    sort(a+1,a+1+n);
    LL ans = 1;
    for(int i = 1,j = 1;i <= n;i ++) {
        if(i == n || a[i].first != a[i+1].first) {
            ans = ans * fac[i-j+1] % mod;
            j = i + 1;
        }
    }
    //cout << ans << endl;
    return ans;
}

LL work2(pii a[],int n) {
    sort(a+1,a+1+n);
    LL ans = 1;
    int maxn = 0;
    for(int i = 1,j = 1;i <= n;i ++) {
        if(i == n || a[i].first != a[i+1].first) {
            vector<int> g;
            while(j <= i) g.push_back(a[j].second),j ++;
            int mn = 1e9;
            for(int x : g) mn = min(mn,x);
            if(mn < maxn) return 0;
            sort(g.begin(),g.end());
            for(int k = 0,kk = 0;k < g.size();k ++) {
                if(k+1 == g.size() || g[k] != g[k+1]) {
                    ans = ans * fac[k-kk+1] % mod;
                    kk = k + 1;
                }
            }
            for(int x : g) maxn = max(maxn,x);
        }
    }
    return ans;
}

int main() {
    int n = read();
    LL ans = 1;
    fac[0] = 1;
    for(int i = 1;i <= n;i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    ans = fac[n];
    for(int i = 1;i <= n;i ++) {
        a[i].first = read();
        a[i].second = read();
    }
    ans -= work(a,n);
    for(int i = 1;i <= n;i ++) {
        swap(a[i].first,a[i].second);
    }
    ans -= work(a,n);
    ans += work2(a,n);
    ans %= mod; ans += mod; ans %= mod;
    cout << ans << endl;
}
