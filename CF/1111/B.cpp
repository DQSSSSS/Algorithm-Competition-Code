#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

LL n,k,m;
LL a[SZ];

int main() {
    n = read(),k = read(),m = read();
    LL sum = 0;
    for(int i = 1;i <= n;i ++) a[i] = read(),sum += a[i];
    sort(a + 1,a + 1 + n);
    double ans = 0;
    for(int i = 0;i < n;i ++) {
        sum -= a[i];
        if(i > m) break;
        double tmp = (sum + min(m - i,k * (n - i))) * 1.0 / (n-i);
        ans = max(ans,tmp);
    }
    printf("%.10f\n",ans);
    return 0;
}

