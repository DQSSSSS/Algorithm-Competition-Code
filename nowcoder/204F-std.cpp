#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1<<18;
const int g = 3;
const int NUM = 20;
ll wn[NUM], fac[maxn], fac_inv[maxn], pow2[maxn];
ll a[maxn], b[maxn];
 
ll qpow(ll x, ll n){
    ll res = 1;
    while(n){
        if(n&1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
 
ll inv(ll x){
    return qpow(x, mod-2);
}
 
void init(){
    fac[0] = 1, fac_inv[0] = 1, pow2[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = fac[i-1] * i % mod;
    for(int i = 1; i < maxn; i++) fac_inv[i] = inv(fac[i]);
    for(int i = 1; i < maxn; i++) pow2[i] = pow2[i-1] * 2 % mod;
    for(int i = 0; i < NUM; i++){
        wn[i] = qpow(g, (mod-1)/(1 << i));
    }
}
 
void change(ll x[], int len){
    int i, j, k;
    for(i = 1, j = len/2; i < len-1; i++){
        if(i < j) swap(x[i], x[j]);
        k = len/2;
        while(j >= k) j -= k, k /= 2;
        if(j < k) j += k;
    }
}
 
void fft(ll a[], int len, int on){
    change(a, len);
    int i = 0;
    for(int h = 2; h <= len; h <<= 1){
        i++;
        ll _wn = wn[i];
        for(int j = 0; j < len; j += h){
            ll w = 1;
            for(int k = j; k < j + h/2; k++){
                ll u = a[k] % mod;
                ll t = w*a[k+h/2] % mod;
                a[k] = (u+t) % mod;
                a[k+h/2] = ((u-t)%mod + mod) % mod;
                w = w*_wn % mod;
 
            }
        }
    }
    if(on == -1){
        for(int i = 1; i < len/2; i++) swap(a[i], a[len-i]);
        ll inv_len = inv(len);
        for(int i = 0; i < len; i++) a[i] = a[i] * inv_len % mod;
    }
}
 
void conv(ll a[], ll b[], int n){
    int len = 1;
    while(len < n*2) len <<= 1;
    fft(a, len, 1);
    fft(b, len, 1);
    for(int i = 0; i < len; i++) a[i] = a[i] * b[i] % mod;
    fft(a, len, -1);
}
 
 
int main(){
    int n;
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i] = a[i] * fac[i] % mod;
    }
    conv(a, b, n);
    for(int i = 0; i < n; i++){
        printf("%lld ", ((a[n-1+i] * pow2[i])%mod * fac_inv[i] % mod) % mod);
    }
    printf("\n");
}
