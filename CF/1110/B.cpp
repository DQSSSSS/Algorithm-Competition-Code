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

int a[SZ];
pii b[SZ];
bool use[SZ];

int main() {
    int n = read(),m = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 2;i <= n;i ++) {
        b[i-1] = make_pair(-(a[i]-a[i-1]+1),i-1);
    }
    sort(b+1,b+n);
    for(int i = 1;i <= k-1;i ++) use[b[i].second] = 1;
    int ans = a[n]-a[1]+1;
    for(int i = 1,f = 0;i < n;i ++) {
        if(use[i]) {
            ans -= a[i+1]-a[i] - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/**
4 100 4
20 30 75 80

*/
