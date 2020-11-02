#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

int n;
LL a[SZ];

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    sort(a + 1,a + 1 + n);
    LL ans = 0;
    for(int i = 1;i <= n/2;i ++) ans += (a[i] + a[n-i+1]) * (a[i] + a[n-i+1]);
    cout << ans << endl;
}
