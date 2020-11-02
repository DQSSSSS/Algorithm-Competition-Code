#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int C[2010][2010],a[SZ];

int main() {
    C[0][0] = 1;
    for(int i = 1;i <= 2000;i ++) {
        C[i][0] = 1;
        for(int j = 1;j <= i;j ++)
            C[i][j] = (C[i-1][j]+C[i-1][j-1]) % mod;
    }
    int k = read();
    for(int i = 1;i <= k;i ++) a[i] = read();
    LL ans = 1;
    for(int i = 1,m = 0;i <= k;i ++) {
        int n = a[i] - 1;
        ans = ans * C[m+n][n] % mod;
        m += a[i];
    }
    cout << ans << endl;
}
