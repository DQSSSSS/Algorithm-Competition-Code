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

int n,m;

struct haha {
    char o[5];
    char t[2][5];
    int x[2];
}a[1010];

int work(int S) {
    int A[22] = {0},B[1010] = {0};
    for(int i = 0;i < n;i ++)
        A[i+1] = (S >> i & 1);
    for(int i = 1;i <= m;i ++) {
        if(a[i].o[1] == 'a') {
            int *p1 = a[i].t[0][0] == 'a' ? A : B;
            int *p2 = a[i].t[1][0] == 'a' ? A : B;
            B[i] = max(p1[a[i].x[0]],p2[a[i].x[1]]);
        }
        else {
            int *p1 = a[i].t[0][0] == 'a' ? A : B;
            int *p2 = a[i].t[1][0] == 'a' ? A : B;
            B[i] = min(p1[a[i].x[0]],p2[a[i].x[1]]);
        }
    }
    return B[m];
}

LL fac[22],f[22];

int main() {
    fac[0] = 1;
    for(LL i = 1;i <= 15;i ++) fac[i] = fac[i-1] * i;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 1;i <= m;i ++) {
            scanf("%s%s%d%s%d",a[i].o,a[i].t[0],&a[i].x[0],a[i].t[1],&a[i].x[1]);
        }
        for(int i = 1;i <= n;i ++) f[i] = 0;
        for(int S = 0;S < (1<<n);S ++) {
            int x = work(S);
            if(x == 1) {
                int one = __builtin_popcount(S);
                int zero = n - one;
                int k = zero + 1;
                f[k] += fac[one] * fac[zero];
            }
        }
        LL ans = 0;
        for(int i = 1;i <= n;i ++) ans += f[i];
        printf("%lld\n",ans);
    }
}
