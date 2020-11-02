#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
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

int pri[SZ];
int mu[SZ];
bool vis[SZ];

void shai(int n) {
    int tot = 0;
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                mu[m] = 0;
                break;
            }
            else {
                mu[m] = -mu[i];
            }
        }
    }
    for(int i = 1;i <= n;i ++) mu[i] += mu[i-1];
}

int k;

LL ask(int n,int m) {
    n /= k; m /= k;
    if(n > m) swap(n,m);
    LL ans = 0;
    for(int i = 1,r;i <= n;i = r + 1) {
        r = min(n / (n / i),m / (m / i));
        ans += 1ll * (mu[r] - mu[i-1]) * (n / i) * (m / i);
    }
    return ans;
}

int main() {
    shai(5e4);
    int T = read();
    while(T --) {
        int a = read(),b = read();
        int c = read(),d = read();
        k = read();
        printf("%lld\n",ask(b,d) - ask(a-1,d) - ask(b,c-1) + ask(a-1,c-1));
    }
}

