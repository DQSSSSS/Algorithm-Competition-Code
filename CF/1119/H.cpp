#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 998244353;
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
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int ni2 = ksm(2,mod-2);

void FWT_xor(LL *a,int N,int opt)
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
            {
                int X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y)%mod;a[i+j+k]=(X-Y+mod)%mod;
                if(opt==-1)a[j+k]=1ll*a[j+k]*ni2%mod,a[i+j+k]=1ll*a[i+j+k]*ni2%mod;
            }
}

LL f[SZ],g[SZ],h[SZ],S[SZ];

int main() {
    int n = read(),k = read();
    LL A = read(),B = read(),C = read();
    int sum = 0;
    for(int i = 1;i <= n;i ++) {
        int x = read(),y = read(),z = read();
        f[x^y] ++; g[x^z] ++; h[y^z] ++;
        sum ^= x;
    }
    FWT_xor(f,1<<k,1);
    FWT_xor(g,1<<k,1);
    FWT_xor(h,1<<k,1);

    LL a = (A + B + C) % mod;
    LL b = (A + B - C+mod) % mod;
    LL c = (A - B + C+mod) % mod;
    LL d = (A - B - C+mod*2) % mod;
    for(int i = 0;i < (1<<k);i ++) {
        LL x = (n + f[i] + g[i] + h[i]) % mod * ni2 % mod * ni2 % mod;
        LL y = (n + f[i] - 2 * x + mod*2) % mod * ni2 % mod;
        LL z = (n + g[i] - 2 * x + mod*2) % mod * ni2 % mod;
        LL w = (n - x - y - z + mod*3ll) % mod;
        S[i] = ksm(a,x) * ksm(b,y) % mod * ksm(c,z) % mod * ksm(d,w) % mod;
    }
    FWT_xor(S,1<<k,-1);
    for(int i = 0;i < (1<<k);i ++)
        printf("%lld ",S[i ^ sum]);
}
