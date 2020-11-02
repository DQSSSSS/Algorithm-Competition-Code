#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
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
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a *a % mod;
        b >>= 1;
    }
    return ans;
}

LL ksm(LL a,LL b,LL mod) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a *a % mod;
        b >>= 1;
    }
    return ans;
}

LL BSGS(LL a,LL b,LL mod) { //a^x = b (% mod)
    a %= mod; b %= mod;
    if(a == 0 && b == 0) return 1;
    else if(a == 0) return -1;
    unordered_map<int,int> h;
    LL m = ceil(sqrt(mod));
    LL amni = ksm(a,mod - m - 1,mod);
    LL t = 1;
    h[t] = 0;
    for(int i = 1;i < m;i ++) {
        t = (t * a) % mod;
        if(t != 1 && !h[t])
            h[t] = i;
    }
    for(int i = 0;i <= m - 1;i ++) {
        LL ans = h[b];
        if(b == 1 || ans)
            return i * m + ans;
        b = (b * amni) % mod;
    }
    return -1;
}

void exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    LL t = x; x = y; y = t - a / b * y;
}

LL get_X(LL A,LL k,LL p) { // A=kx % p
    LL d = __gcd(k,p);
    A /= d; p /= d; k /= d;
    LL x,K;
    exgcd(k,p,x,K);
    return ((A*x%p)+p)%p;
}

int gen(int n,int k) { //n^(1/k)%p
    if(n == 0) return 0;
    int A = BSGS(5,n,mod);
    int x = ksm(5,get_X(A,k,mod-1));
    return x;
}

int getG(int p) {
    if(p == 2) return 1;
    vector<int> getGtmp;
    int x = p - 1;
    for(int i = 2;i <= x;i ++) if(x % i == 0) getGtmp.push_back(i);
    for(int k = 2;;k ++)
        for(int i = 0;i < getGtmp.size();i ++) {
            if(ksm(k,getGtmp[i],p) == 1) {
                if(getGtmp[i] == x)
                    return k;
                else break;
            }
        }
}

int main() {
    for(int i = 0;i <= 512;i ++) {
        if(1ll * i * i % 512 == 5) cout << i << endl;
    }
    int T = read();
    while(T --) {
        LL b = read(),c = read();
        LL delta = (b * b % mod - 4 * c % mod + mod) % mod;
        LL g = gen(delta,2);
        if(1ll * g * g % mod != delta) {
            printf("-1 -1\n");
        }
        else {
            LL x = (b + g) * ksm(2,mod-2) % mod;
            LL y = (b-x+mod) % mod;
            if(x>y) swap(x,y);
            printf("%lld %lld\n",x,y);
        }
    }
}
