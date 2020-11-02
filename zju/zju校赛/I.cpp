#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const LL mod = 1e9 + 7;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    a%=mod;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

unordered_map<LL,LL> f,g,h,vis;

LL w[55],G[55],n,m;

void dfs(LL S) {
    if(vis[S]) return ;
    vis[S] = 1;
    LL fans = 0,gans = 0,hans = 0;
    for(LL i = 0;i < n;i ++){
        if(S >> i & 1) {
            LL nxt = S^(1ll<<i); /// not select
            dfs(nxt);
            (fans += f[nxt]) %= mod;
            (gans += g[nxt]) %= mod;
            (hans += h[nxt]) %= mod;

            nxt = S&G[i]; /// select
            dfs(nxt);
            (fans += f[nxt]) %= mod;
            (gans += w[i]%mod*g[nxt]%mod) %= mod;
            (hans += w[i]%mod*w[i]%mod*h[nxt]%mod) %= mod;

            break;
        }
    }
    f[S] = fans;
    g[S] = gans;
    h[S] = hans;
}

int main() {
    n = read(),m = read();
    for(int i = 0;i < n;i ++) w[i] = read() % mod;
    for(int i = 1;i <= m;i ++) {
        LL x = read() - 1,y = read() - 1;
        G[x] |= 1ll << y;
        G[y] |= 1ll << x;
    }
    vis[0] = 1; f[0] = 1; g[0] = 1; h[0] = 1;
    LL msk = (1ll<<n)-1;
    for(LL i = 0;i < n;i ++) G[i] = msk & ~G[i],G[i] ^= (1ll<<i);
    dfs(msk);
    LL ans = h[msk] * ksm(f[msk],mod-2)%mod -
        ksm(g[msk]*ksm(f[msk],mod-2)%mod,2);
    ans %= mod; ans += mod; ans %= mod;
    cout << ans << endl;
}
/**
40 8
3 6 1 10 9 3 5 4 7 6 3 6 1 10 9 3 5 4 7 6 3 6 1 10 9 3 5 4 7 6 3 6 1 10 9 3 5 4 7 6
1 2
2 3
3 4
5 2
1 4
5 6
1 25
3 7


3 2
1 1 1
1 2
1 3


3 0
8 8 8

5 5
2147483647 2147483647 2147483647 2147483647 2147483647
1 2
2 3
3 4
5 2
1 4



*/
