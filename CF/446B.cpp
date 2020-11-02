#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

priority_queue<LL> c,r;
LL a[SZ],b[SZ];
LL R[SZ],C[SZ];

int main() {
    LL n = read(),m = read(),k = read(),p = read();
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++) {
            int x = read();
            R[i] += x;
            C[j] += x;
        }
    for(int i = 1;i <= n;i ++) r.push(R[i]);
    for(int i = 1;i <= k;i ++) {
        LL rx = r.top(); r.pop(); r.push(rx-p*m);
        a[i] = a[i-1] + rx;
    }
    for(int i = 1;i <= m;i ++) c.push(C[i]);
    for(int i = 1;i <= k;i ++) {
        LL cx = c.top(); c.pop(); c.push(cx-p*n);
        b[i] = b[i-1] + cx;
    }
    LL ans = -1e18;
    for(int i = 0;i <= k;i ++)
        ans = max(ans,a[i]+b[k-i]-1ll*i*(k-i)*p);
    cout << ans << endl;
}
