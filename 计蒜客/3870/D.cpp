#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
const int INF = 1e9 + 10;
const int mod = 100003;
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

namespace Math {
    inline int pw(int base, int p, const int mod) {
        static int res;
        for (res = 1; p; p >>= 1, base = static_cast<long long> (base) * base % mod) if (p & 1) res = static_cast<long long> (res) * base % mod;
        return res;
    }
    inline int inv(int x, const int mod) { return pw(x, mod - 2, mod); }
}

const int mod1 = 998244353, mod2 = 1004535809, mod3 = 469762049, G = 3;
const long long mod_1_2 = static_cast<long long> (mod1) * mod2;
const int inv_1 = Math::inv(mod1, mod2), inv_2 = Math::inv(mod_1_2 % mod3, mod3);
struct Int {
    int A, B, C;
    explicit inline Int() { }
    explicit inline Int(int __num) : A(__num), B(__num), C(__num) { }
    explicit inline Int(int __A, int __B, int __C) : A(__A), B(__B), C(__C) { }
    static inline Int reduce(const Int &x) {
        return Int(x.A + (x.A >> 31 & mod1), x.B + (x.B >> 31 & mod2), x.C + (x.C >> 31 & mod3));
    }
    inline friend Int operator + (const Int &lhs, const Int &rhs) {
        return reduce(Int(lhs.A + rhs.A - mod1, lhs.B + rhs.B - mod2, lhs.C + rhs.C - mod3));
    }
    inline friend Int operator - (const Int &lhs, const Int &rhs) {
        return reduce(Int(lhs.A - rhs.A, lhs.B - rhs.B, lhs.C - rhs.C));
    }
    inline friend Int operator * (const Int &lhs, const Int &rhs) {
        return Int(static_cast<long long> (lhs.A) * rhs.A % mod1, static_cast<long long> (lhs.B) * rhs.B % mod2, static_cast<long long> (lhs.C) * rhs.C % mod3);
    }
    inline int get() {
        long long x = static_cast<long long> (B - A + mod2) % mod2 * inv_1 % mod2 * mod1 + A;
        return (static_cast<long long> (C - x % mod3 + mod3) % mod3 * inv_2 % mod3 * (mod_1_2 % mod) % mod + x) % mod;
    }
} ;

#define maxn 131072

namespace Poly {
#define N (maxn << 1)
    int lim, s, rev[N];
    Int Wn[N | 1];
    inline void init(int n) {
        s = -1, lim = 1; while (lim < n) lim <<= 1, ++s;
        for (register int i = 1; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
        const Int t(Math::pw(G, (mod1 - 1) / lim, mod1), Math::pw(G, (mod2 - 1) / lim, mod2), Math::pw(G, (mod3 - 1) / lim, mod3));
        *Wn = Int(1); for (register Int *i = Wn; i != Wn + lim; ++i) *(i + 1) = *i * t;
    }
    inline void NTT(Int *A, const int op = 1) {
        for (register int i = 1; i < lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
        for (register int mid = 1; mid < lim; mid <<= 1) {
            const int t = lim / mid >> 1;
            for (register int i = 0; i < lim; i += mid << 1) {
                for (register int j = 0; j < mid; ++j) {
                    const Int W = op ? Wn[t * j] : Wn[lim - t * j];
                    const Int X = A[i + j], Y = A[i + j + mid] * W;
                    A[i + j] = X + Y, A[i + j + mid] = X - Y;
                }
            }
        }
        if (!op) {
            const Int ilim(Math::inv(lim, mod1), Math::inv(lim, mod2), Math::inv(lim, mod3));
            for (register Int *i = A; i != A + lim; ++i) *i = (*i) * ilim;
        }
    }
#undef N
}


vector<int> multiply(const vector<int> &a,const vector<int> &b) {
    static Int A[SZ],B[SZ];
    int n = a.size(),m = b.size();
    Poly::init(n+m);
    for(int i = 0;i < n;i ++) A[i] = Int(a[i]); for(int i = n;i < Poly::lim;i ++) A[i] = Int(0);
    for(int i = 0;i < m;i ++) B[i] = Int(b[i]); for(int i = m;i < Poly::lim;i ++) B[i] = Int(0);
    Poly::NTT(A), Poly::NTT(B);
    for (int i = 0; i < Poly::lim; ++i) A[i] = A[i] * B[i];
    Poly::NTT(A, 0);
    vector<int> ans; ans.resize(n+m-1);
    for (int i = 0; i < n + m - 1; ++i) {
        ans[i] = A[i].get();
    }
    return ans;
}

int a[SZ];

vector<int> work(int l,int r) {
    if(l == r) {
        vector<int> ans;
        ans.resize(2);
        ans[0] = 1;
        ans[1] = a[l];
        return ans;
    }

    int mid = l + r >> 1;
    vector<int> L = work(l,mid);
    vector<int> R = work(mid+1,r);
    vector<int> ans = multiply(L,R);
    /*printf("[%d,%d]\n",l,r);
    for(int i = 0;i < L.size();i ++) printf("%d ",L[i]); puts("");
    for(int i = 0;i < R.size();i ++) printf("%d ",R[i]); puts("");
    for(int i = 0;i < ans.size();i ++) printf("%d ",ans[i]); puts("");*/
    return ans;
}

LL ksm(LL a,LL b,LL p) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int fac[SZ],inv[SZ];

LL C(int n,int m) {
    return 1ll * fac[n] * inv[m] % mod * inv[n-m] % mod;
}

int main() {
    fac[0] = 1;
    for(int i = 1;i <= 1e5;i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    inv[100000] = ksm(fac[100000],mod-2,mod);
    for(int i = 1e5-1;i >= 0;i --) inv[i] = 1ll * inv[i+1] * (i+1) % mod;
    int n = read(),A = read(),Q = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = ksm(A,read(),mod);
    }

    vector<int> ans = work(1,n);

    //for(int i = 1;i <= n;i ++) printf("%d ",ans[i]); puts("");
    for(int i = 1;i <= n;i ++) {
        LL x = C(n,i) - ans[i];
        ans[i] = x * ksm(1-A,mod-2,mod) % mod;
        ans[i] += mod; ans[i] %= mod;
    }

    for(int i = 1;i <= Q;i ++) {
        int x = read();
        printf("%d\n",ans[x]);
    }
}

/**
3 2 233
3 1 1
1
*/
