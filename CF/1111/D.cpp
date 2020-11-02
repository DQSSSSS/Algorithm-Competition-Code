#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

char s[SZ];
LL frac[SZ];

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL inv[SZ];

LL C(int n,int m) {
    return frac[n] * inv[m] % mod * inv[n - m] % mod;
}

int mp[233],n;
LL t[SZ];

LL f[SZ],Ans[233][233],g[SZ];

LL work(int x,int y) {
    for(int i = 0;i <= n / 2;i ++) g[i] = f[i];
    if(x == y) {
        for(int i = t[x];i <= n / 2;i ++) (g[i] -= g[i - t[x]]) %= mod;
    }
    else {
        for(int i = t[x];i <= n / 2;i ++) (g[i] -= g[i - t[x]]) %= mod;
        for(int i = t[y];i <= n / 2;i ++) (g[i] -= g[i - t[y]]) %= mod;
    }
    return (g[n / 2] + mod) % mod;
}

int main() {
    scanf("%s",s + 1);
    n = strlen(s + 1);
    for(int i = 'a';i <= 'z';i ++) mp[i] = i - 'a';
    for(int i = 'A';i <= 'Z';i ++) mp[i] = i - 'A' + 26;
    for(int i = 1;i <= n;i ++) {
        t[mp[s[i]]] ++;
    }

    frac[0] = 1;
    for(int i = 1;i <= 1e5;i ++) frac[i] = frac[i - 1] * i % mod;
    inv[100000] = ksm(frac[100000],mod - 2);
    for(int i = 1e5-1;i >= 0;i --) inv[i] = inv[i + 1] * (i + 1) % mod;

    LL W = frac[n/2] * frac[n/2] % mod;
    for(int i = 0;i < 52;i ++)
        W = W * inv[t[i]] % mod;

    f[0] = 1;
    for(int i = 0;i < 52;i ++)
        if(t[i])
            for(int j = n / 2;j >= t[i];j --)
                (f[j] += f[j - t[i]]) %= mod;

    for(int i = 0;i < 52;i ++)
        for(int j = i;j < 52;j ++)
            if(t[i] && t[j])
                Ans[i][j] = W * work(i,j) * 2 % mod;

    //for(int i = 0;i <= n / 2;i ++) cout << f[i] << " "; puts("");
    //cout << W << " " << f[n/2] << " " << work(0,2) << endl;

    int q = read();
    while(q --) {
        int x = read(),y = read();
        x = mp[s[x]],y = mp[s[y]];
        if(x > y) swap(x,y);
        //cout << x << " " << y << endl;
        printf("%lld\n",Ans[x][y]);
    }
    return 0;
}
