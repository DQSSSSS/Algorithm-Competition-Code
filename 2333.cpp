#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

const int MOD = 998244353;
mt19937_64 rnd;

inline ll mmul(ll a, ll b, ll mod) {
  ll k = 1.0l * a * b / (1.0l * mod), t = a * b - k * mod;
  for (t -= mod; t < 0; t += mod) {}
  return t;
}

inline ll mpow(ll a, ll b, ll mod) {
  ll res = 1;
  for (; b; b >>= 1, a = mmul(a, a, mod)) (b & 1) && (res = mmul(res, a, mod));
  return res;
}

inline bool check(ll x, ll p) {
  if (!(x % p) || mpow(p % x, x - 1, x) != 1) return false;
  for (ll k = x - 1, t, px = p % x; ~k & 1;) {
    if (((t = mpow(px, k >>= 1, x)) != 1) && (t != x - 1)) return false;
    if (t == x - 1) return true;
  }
  return true;
}

inline bool Miller_Rabin(ll x) {
  if (x < 2) return false;
  static const int p[12] = {2, 3, 5, 7, 11, 13, 17, 19, 61, 233, 4567, 24251};
  for (int i = 0; i < 12; ++i) {
    if (x == p[i]) return true;
    if (!check(x, p[i])) return false;
  }
  return true;
}

inline ll rand64(ll x) { return rnd() % (x - 1) + 1; }

inline ll Pollar_rho(ll x, int y) {
  ll v0 = rand64(x), v = v0, d, s = 1;
  for (int t = 0, k = 1;;) {
    if (v = (mmul(v, v, x) + y) % x, s = mmul(s, abs(v - v0), x),
        v == v0 || s == 0)
      return x;
    if (++t == k) {
      if ((d = __gcd(s, x)) != 1) return d;
      v0 = v, k <<= 1;
    }
  }
}

LL factor[10010];
void find_factors(ll n,LL factor[]) {
  if (Miller_Rabin(n)) {
    factor[++ factor[0]] = n;
    return;
  }
  ll p = n;
  while (p >= n) p = Pollar_rho(p, rand64(n));
  find_factors(p,factor);
  find_factors(n / p,factor);
}

inline ll frac(ll e, ll k) {
  // Proc (e + 1 + i) / (1 + i), i = 0..k
  ll l0 = e + 1, r0 = e + k + 1;
  ll l1 = 1, r1 = k + 1;
  if (l0 <= r1) {
    ll l = l0, r = r1;
    l0 = r + 1, r1 = l - 1;
  }
  ll w0 = 1, w1 = 1;
  assert(r0 - l0 == r1 - l1);
  for (ll i = l0, j = l1; j <= r1; ++i, ++j)
    w0 = w0 * (i % MOD) % MOD, w1 = w1 * (j % MOD) % MOD;
  return w0 * mpow(w1, MOD - 2, MOD) % MOD;
}

int main() {
    int T = read();
    while(T --) {
        LL n = read(), k;// = read();
        factor[0] = 0;
        find_factors(n, factor);
        sort(factor + 1, factor + 1 + factor[0]);
        LL ans = 0;
        for(int i = 1,j = 1; i <= factor[0];i ++) {
            ans = max(ans,factor[i]);
        }
        if(ans == n) {
            puts("Prime");
        }
        else
            printf("%lld\n",ans);
    }
}

