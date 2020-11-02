#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;
const int mod = 1e9 + 7;

struct matrix {
    int a[6][6];
}f,ans;

matrix operator *(matrix &a,matrix &b) {
    matrix ans;
    memset(ans.a,0,sizeof ans.a);
    for(int i = 1;i <= 4;i ++){
        for(int j = 1;j <= 4;j ++) {
            for(int k = 1;k <= 4;k ++) {
                (ans.a[i][j] += 1ll * a.a[i][k] * b.a[k][j] % mod) %= mod;
            }
        }
    }
    return ans;
}

LL ask(LL n) {
    if(n == 1) return 1;
    if(n == 2) return 5;
    if(n == 3) return 11;
    if(n == 4) return 36;
    n -= 5;
    memset(f.a,0,sizeof f.a);
    f.a[1][1] = 1;
    f.a[1][2] = 5;
    f.a[1][3] = 1;
    f.a[1][4] = -1;

    f.a[2][1] = f.a[3][2] = f.a[4][3] = 1;

    ans = f;
    while(n) {
        if(n&1) ans = ans * f;
        f = f * f;
        n >>= 1;
    }
    LL A = 36ll * ans.a[1][1] % mod;
    (A += 11ll * ans.a[1][2] % mod) %= mod;
    (A += 5ll * ans.a[1][3] % mod) %= mod;
    (A += 1ll * ans.a[1][4] % mod) %= mod;
    A += mod; A %= mod;
    return A;
}

int main() {
    LL n;
    while(~scanf("%lld",&n)) {
        printf("%lld\n",ask(n));
    }
}


/**
781+281*4+95*2+36*3+11*2+5*3+1*2+1*3
2245+781*4+281*2+95*3+36*2+11*3+5*2+1*3+1*2
*/
