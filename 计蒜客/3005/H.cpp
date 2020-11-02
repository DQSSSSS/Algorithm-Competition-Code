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

const LL inv2 = 499122177;
const LL inv6 = 166374059;

struct LO {
    LL F1(LL n) {
        n %= mod;
        return n * (n+1) % mod * inv2 % mod;
    }
    LL F2(LL n) {
        n %= mod;
        return n * (n+1) % mod * (2*n+1) % mod * inv6 % mod;
    }
    LL solve(LL a,LL b,LL c,LL n) {
        LL f,g,h;
        if(a == 0) {
            n %= mod;
            f = (b/c%mod) * (n+1) % mod;
        }
        else if(a>=c || b>=c) {
            LL t = solve(a%c,b%c,c,n);
            f = (t + F1(n)*(a/c%mod)%mod + ((n+1)%mod)*(b/c%mod)%mod) % mod;
        }
        else {
            LL m = ((__int128)a*n+b)/c;
            LL t = solve(c,c-b-1,a,m-1);
            m %= mod;
            f = ((n%mod)*m%mod - t) % mod;
        }
        f += mod; f %= mod;
        return f;
    }
}lo;

int pri[SZ],tot;
bool vis[SZ];

LL w[SZ],gen,n; // 所有的 n/i 下取整
int id1[SZ],id2[SZ]; // w中对应数字的标号
LL sump0[SZ],sump1[SZ];
LL g0[SZ],g1[SZ]; // 计算完毕后为小于等于 w[i] 的所有质数的对应函数和

void shai(int n) {
    tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                break;
            }
        }
    }
    for(int i = 1;i <= tot;i ++) {
        sump0[i] = i; /// modify
        sump1[i] = (sump1[i-1] + pri[i]) % mod; /// modify
    }
}

int getid(LL x) {
    if(x <= gen) return id1[x];
    return id2[n/x];
}

int f1(LL x) {
    x %= mod;
    return x * (x+1) / 2 % mod;
}

int f2(LL x) {
    x %= mod;
    return x * (x+1) % mod * (2*x+1) % mod * inv6 % mod;
}

LL work(LL n) {
    gen = sqrt(n);
    shai(1e5);
    LL ans = 0;
    for(int i = 1;i <= tot && 1ll *pri[i] * pri[i] <= n;i ++) {
        LL p = pri[i],now = p;
        for(LL k = 2;now * p <= n;k ++) {
            now *= p;
            (ans += lo.solve(1,0,now,n)) %= mod;
        }
    }

    int m = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n/(n/i); w[++m] = n/i;
        g0[m] = w[m]-1; /// modify
        g1[m] = f1(w[m])-1; /// modify
        if(w[m] <= gen) id1[w[m]]=m;
        else id2[r]=m;
    }
    for(int j = 1;j <= tot;j ++) {
        LL p = pri[j];
        for(int i = 1;i<=m && p*p<=w[i];i ++) {
            int k = getid(w[i]/p);
            (g0[i] -= (g0[k] - sump0[j-1]) % mod) %= mod; /// modify
            (g1[i] -= p * (g1[k] - sump1[j-1]) % mod) %= mod; /// modify
        }
    }

    LL t1 = 0,t2 = 0,t3 = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n/(n/i);
        LL W = n / i % mod;
        (t1 += (W%mod) * (g0[getid(r)] - g0[getid(i-1)]) % mod) %= mod;
        (t2 += (W%mod) * (W%mod) % mod * (g1[getid(r)] - g1[getid(i-1)]) % mod) %= mod;
        (t3 += (W%mod) * (g1[getid(r)] - g1[getid(i-1)]) % mod) %= mod;
    }

    (ans += (n+1)%mod * t1 % mod) %= mod;
    (ans -= inv2 * t2 % mod) %= mod;
    (ans -= inv2 * t3 % mod) %= mod;
    ans += mod; ans %= mod;
    return ans;
}

int main() {
    n = read();
    printf("%lld\n",work(n));
}
