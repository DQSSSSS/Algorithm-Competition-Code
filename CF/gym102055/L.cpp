#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int tot,pri[SZ];
bool vis[SZ];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}

bool ispri(LL x) {
    for(LL i = 2;i * i <= x;i ++)
        if(x % i == 0) return false;
    return true;
}

pll get(LL n) {
    for(int i = 1;i <= tot;i ++) {
        if(n - pri[i] <= 0) break;
        if(ispri(n-pri[i])) {
            return make_pair(pri[i],n-pri[i]);
        }
    }
    return make_pair(0,0);
}

int main() {
    cout << ispri((1ll<<30)+3);
    shai(1e6);
    int T = read(),cc = 0;
    while(T --) {
        LL n = read();
        printf("Case %d: ",++ cc);
        if(n <= 11) { puts("IMPOSSIBLE"); continue; }
        if(n % 2 == 0) {
            printf("2 2 2 2 ");
            pll ans = get(n-8);
            printf("%lld %lld\n",ans.first,ans.second);
        }
        else {
            printf("2 2 2 3 ");
            pll ans = get(n-9);
            printf("%lld %lld\n",ans.first,ans.second);
        }
    }
}

