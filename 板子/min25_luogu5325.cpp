#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e7 + 10;
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
// 此题：f(p^k)=p^k(p^k-1)
struct Min_25 {

    LL n;
    int gen; // sqrt(n)
    LL w[SZ]; // 所有的 n/i 下取整
    int id1[SZ],id2[SZ]; // w中对应数字的标号
    int sump[SZ],sump2[SZ]; // 前 i 个素数的和、平方和
    int g1[SZ],g2[SZ]; // 计算完毕后为小于等于 w[i] 的所有质数的对应函数和

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
        for(int i = 1;i <= tot;i ++) {
            sump[i] = (sump[i-1] + pri[i]) % mod; /// modify
            sump2[i] = (sump2[i-1] + 1ll*pri[i]*pri[i]%mod) % mod; /// modify
        }
    }

    int getid(LL x) {
        if(x <= gen) return id1[x];
        return id2[n/x];
    }

    int S(LL x,int y) {
        if(x <= 1 || pri[y] > x) return 0;
        int k = getid(x);
        int ans = (g2[k]-g1[k]-(sump2[y-1]-sump[y-1])) % mod; /// modify
        for(int i = y;i <= tot && 1ll * pri[i] * pri[i] <= x;i ++) {
            LL p = pri[i];
            LL t1 = p,t2 = p*p;
            for(int e = 1;t2 <= x;e ++) {
                (ans += (S(x/t1,i+1) * (t1 % mod)%mod * ((t1-1) % mod) % mod /// modify
                         + (t2%mod) * ((t2-1)%mod) % mod)%mod) %=mod;
                t1 *= p; t2 *= p;
            }
        }
        return ans;
    }

    int f1(LL x) {
        x %= mod;
        return x * (x+1) / 2 % mod;
    }

    int f2(LL x) {
        x %= mod;
        int ni6 = 166666668;
        return x * (x+1) % mod * (2*x+1) % mod * ni6 % mod;
    }

    int work(LL nn) {
        n = nn;
        gen = sqrt(n);
        shai(gen);
        int m = 0;
        for(LL i = 1,r;i <= n;i = r + 1) {
            r = n/(n/i); w[++m] = n/i;
            g1[m] = f1(w[m])-1; /// modify
            g2[m] = f2(w[m])-1; /// modify
            if(w[m] <= gen) id1[w[m]]=m;
            else id2[r]=m;
        }
        for(int j = 1;j <= tot;j ++) {
            LL p = pri[j];
            for(int i = 1;i<=m && p*p<=w[i];i ++) {
                int k = getid(w[i]/p);
                (g1[i] -= p * (g1[k] - sump[j-1]) % mod) %= mod; /// modify
                (g2[i] -= p * p % mod * (g2[k] - sump2[j-1]) % mod) %= mod; /// modify
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
