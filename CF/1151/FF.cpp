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
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

double f[110][110];
int a[110];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    int A = 0,B = 0;
    for(int i = 1;i <= n;i ++) if(a[i] == 1) A ++;
    for(int j = n-A+1;j <= n;j ++) if(a[j] == 0) B ++;


    f[0][B] = 1;
    for(int i = 0;i < m;i ++) {
        for(int b = 0;b <= A;b ++) {
            double di = n * (n-1) / 2;
            double tmp = di;
            if(b < A) {
                f[i+1][b+1] += f[i][b] * (A-b) * (n-A-b) / di;
                tmp -= (A-b) * (n-A-b);
            }
            if(b > 0) {
                f[i+1][b-1] += f[i][b] * (b*b) / di;
                tmp -= b*b;
            }
            f[i+1][b] += f[i][b] * tmp / di;
        }
    }
    for(int i = 0;i <= 3;i ++,puts(""))
        for(int j = 0;j <= A;j ++)
            cout << f[i][j] << " ";
}
