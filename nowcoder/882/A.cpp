#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int C[110][110];

int main() {
    C[0][0] = 1;
    for(int i = 1;i <= 100;i ++) {
        C[i][0] = 1;
        for(int j = 1;j <= i;j ++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }

    LL ans = 0;
    for(int i = 0;i <= 14;i ++) {
        ans += 1ll * C[14][i] * C[14][i];
    }

    cout << ans << endl;
}
