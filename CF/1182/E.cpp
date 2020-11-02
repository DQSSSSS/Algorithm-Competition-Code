#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL ksm(LL a,LL b,LL mod) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans %mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

const int g = 5;

LL BSGS(LL a,LL b,LL mod) { //a^x = b (% mod)
    a %= mod; b %= mod;
    if(a == 0 && b == 0) return 1;
    else if(a == 0) return -1;
    map<LL,LL> hash;
    LL m = ceil(sqrt(mod));
    LL amni = ksm(a,mod - m - 1,mod);
    LL t = 1;
    hash[t] = 0;
    for(int i = 1;i < m;i ++) {
        t = (t * a) % mod;
        if(t != 1 && !hash[t])
            hash[t] = i;
    }
    for(int i = 0;i <= m - 1;i ++) {
        LL ans = hash[b];
        if(b == 1 || ans)
            return i * m + ans;
        b = (b * amni) % mod;
    }
    return -1;
}

struct matrix {
    int n,m,num[6][6];
    void print() {
        printf("%d %d\n",n,m);
        for(int i = 1;i <= n;i ++,puts("")) {
            for(int j = 1;j <= m;j ++) {
                printf("%10d",num[i][j]);
            }
        }
    }
}a,f;

matrix operator *(const matrix &a,const matrix &b) {
    matrix ans;
    ans.n = a.n;
    ans.m = b.m;
    memset(ans.num,0,sizeof ans.num);
    for(int i = 1;i <= a.n;i ++) {
        for(int j = 1;j <= b.m;j ++) {
            for(int k = 1;k <= a.m;k ++) {
                (ans.num[i][j] += 1ll * a.num[i][k] * b.num[k][j] % (mod-1)) %= mod-1;
            }
        }
    }
    return ans;
}

matrix ksm(matrix a,LL b) {
    matrix ans = a;
    while(b) {
        if(b&1) ans = a * ans;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    LL n = read();
    a.n = 1; a.m = 5;
    a.num[1][3] = BSGS(g,read(),mod);
    a.num[1][2] = BSGS(g,read(),mod);
    a.num[1][1] = BSGS(g,read(),mod);
    a.num[1][4] = 2;
    a.num[1][5] = 2;

    f.n = f.m = 5;
    f.num[4][1] = BSGS(g,read(),mod);
    for(int i = 1;i <= 3;i ++) f.num[i][1] = 1;
    f.num[1][2] = 1;
    f.num[2][3] = 1;
    f.num[4][4] = 1;
    f.num[5][5] = 1;
    f.num[5][4] = 1;

   // a.print();
   // f.print();

    n -= 4;
    f = ksm(f,n);
    //f.print();
    a = a * f;

    cout << ksm(g,a.num[1][1],mod);
}
