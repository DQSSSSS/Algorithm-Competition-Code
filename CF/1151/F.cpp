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

struct mat {
    LL a[110][110];
    int n,m;
}f,me;

mat operator *(const mat &A,const mat &B) {
    mat ans;
    memset(ans.a,0,sizeof ans.a);
    ans.n = A.n,ans.m = B.m;
    for(int i = 0;i < A.n;i ++) {
        for(int j = 0;j < B.m;j ++) {
            for(int k = 0;k < A.m;k ++) {
                (ans.a[i][j] += A.a[i][k] * B.a[k][j] % mod) %= mod;
            }
        }
    }
    return ans;
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

mat ksm(mat a,LL b) {
    mat ans;
    ans.n = a.n,ans.m = a.m;
    memset(ans.a,0,sizeof ans.a);
    for(int i = 0;i < ans.n;i ++) ans.a[i][i] = 1;
    while(b) {
        if(b&1) ans = a * ans;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int a[110];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    int A = 0,B = 0;
    for(int i = 1;i <= n;i ++) if(a[i] == 1) A ++;
    for(int j = n-A+1;j <= n;j ++) if(a[j] == 0) B ++;

    me.n = A+1,me.m = 1;
    f.n = A+1,f.m = A+1;

    me.a[B][0] = 1;

    for(int b = 0;b <= A;b ++) {
        LL di = 1ll * n * (n-1) / 2 % mod,tmp = di;
        if(b < A) {
            f.a[b+1][b] = 1ll * (A-b) * (n-A-b) % mod * ksm(di,mod-2) % mod;
            (tmp -= 1ll* (A-b) * (n-A-b) % mod) %= mod;
        }
        if(b > 0) {
            f.a[b-1][b] = (b*b) % mod * ksm(di,mod-2) % mod;
            (tmp -= 1ll * b*b % mod) %= mod;
        }
        tmp += mod; tmp %= mod;
        f.a[b][b] = tmp * ksm(di,mod-2) % mod;
    }


    f = ksm(f,m);

    me = f * me;
    LL ans = me.a[0][0];
    ans += mod;
    ans %= mod;
    cout << ans << endl;
}
