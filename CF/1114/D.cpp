#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int a[SZ],f[5010][5010];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    n = unique(a + 1,a + 1 + n) - a - 1;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(a[i] == a[n - j + 1])
                f[i][j] = max(max(f[i-1][j],f[i][j-1]),f[i-1][j-1]+1);
            else
                f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    }
    int ans = n;
    for(int i = 1;i <= n;i ++)
        ans = min(ans,n-1-f[i][n-i-1]);
    cout << ans << endl;
}
