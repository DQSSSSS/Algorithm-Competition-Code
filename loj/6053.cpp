#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

struct Min_25 {

    LL n;
    int gen; // sqrt(n)
    LL w[SZ]; // 所有的 n/i 下取整
    int id1[SZ],id2[SZ]; // w中对应数字的标号
    int sump[SZ];
    int g0[SZ],g1[SZ];

    bool vis[SZ];
    int pri[SZ],tot;
    void shai(int n) {
        tot = 0;
        for(int i = 2;i <= n;i ++) {
            if(!vis[i]) pri[++ tot] = i;
            for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
                vis[m] = 1;
                if(i%pri[j] == 0) break;
            }
        }
        for(int i = 1;i <= tot;i ++)
            sump[i] = (sump[i-1] + pri[i]) % mod;
    }

    int getid(LL x) {
        if(x <= gen) return id1[x];
        return id2[n/x];
    }

    int S(LL x,int y) {
        if(x <= 1 || pri[y] > x) return 0;
        int k = getid(x);
        int ans = (g1[k]-g0[k]-(sump[y-1]-y+1ll)) % mod;
        if(y == 1) ans += 2;
        for(int i = y;i <= tot && 1ll * pri[i] * pri[i] <= x;i ++) {
            LL p = pri[i];
            LL t1 = p,t2 = p*p;
            for(int e = 1;t2 <= x;e ++) {
                (ans += (S(x/t1,i+1) * (p^e) % mod + (p^(e+1)))%mod) %=mod;
                t1 *= p; t2 *= p;
            }
        }
        return ans;
    }

    int work(LL nn) {
        n = nn;
        gen = sqrt(n);
        shai(gen);
        int ni2 = 500000004;
        int m = 0;
        for(LL i = 1,r;i <= n;i = r + 1) {
            r = n/(n/i); w[++m] = n/i;
            g0[m] = (w[m]-1)%mod;
            g1[m] = ((w[m]%mod)*((w[m]+1)%mod)%mod*ni2%mod-1)%mod;
            if(w[m] <= gen) id1[w[m]]=m;
            else id2[r]=m;
        }
        for(int j = 1;j <= tot;j ++) {
            LL p = pri[j];
            for(int i = 1;i<=m && p*p<=w[i];i ++) {
                int k = getid(w[i]/p);
                (g0[i] -= (g0[k] - j + 1) % mod) %= mod;
                (g1[i] -= p * (g1[k] - sump[j-1]) % mod) %= mod;
            }
        }
        int ans = S(n,1) + 1;
        ans += mod; ans %= mod;
        return ans;
    }
}min25;

int main() {
    LL n = read();
    printf("%d\n",min25.work(n));
}
