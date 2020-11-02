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

int mu[SZ];
int Sr[SZ];
int pri[SZ];
bool vis[SZ];

void shai(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ pri[0]] = i,mu[i] = -1;
        for(int j = 1,m;j <= pri[0] && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                mu[m] = 0;
            }
            else {
                mu[m] = -mu[i];
            }
        }
    }
}

int Sqrt(LL n) {
    if(n <= 0) return 0;
    return sqrt(n);
}

void add(int &a,const int &b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int work(int n,int m,LL r,int b) {
    int ans = 0;
    for(int d = 1;d <= min(n,m);d ++) {
        int tmp = 0;
        for(int i = 1;i <= n / d;i ++) {
            int k = min(m / d,Sqrt(r/(1ll*d*d)-1ll*i*i));
           // printf("%d %d %lld\n",d,i,k);
            if(b == 1) add(tmp,k);
            else if(b == 2) add(tmp,1ll * d * i * k % mod);
            else {
                k = 1ll * k * (k+1) / 2 % mod;
                add(tmp,1ll * d * i * d % mod * k % mod);
            }
        }
        add(ans,tmp*mu[d]);
    }
    return ans;
}

LL ask(LL n,LL m,LL r) {
    if(r <= 0) return 0;
    LL ans = (n-1) * m % mod + (m-1) * n % mod;
    n --,m --;
    LL w1 = work(n,m,r,1);
    LL w2 = work(n,m,r,2);
    LL w3 = work(m,n,r,2);
    LL w4 = work(n,m,r,3);
    LL tmp = 2 * ((n+1)*(m+1)%mod*w1 % mod - (m+1)*w2 % mod - (n+1)*w3 % mod + w4);
    //printf("%lld %lld %lld %lld %lld %lld\n",w1,w2,w3,w4,tmp,ans);
    return (tmp + ans) % mod;
}

int main() {
    //freopen("A.in","r",stdin);
    shai(1e5);
    LL n = read(),m = read(),l = read(),r = read();
    LL ans = ask(n,m,r*r) - ask(n,m,l*l-1);
    ans %= mod; ans += mod; ans %= mod;
    cout << ans << endl;
}

/*
100000 100000 1 100000
*/
