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

LL p[SZ],mi[SZ],tot = 0;

int main() {
    LL n = read(),b = read();
    for(LL i = 2;i * i <= b;i ++) {
        if(b % i == 0) {
            tot ++;
            p[tot] = i;
            while(b % i == 0) b /= i,mi[tot] ++;
        }
    }
    if(b != 1) {
        p[++ tot] = b;
        mi[tot] = 1;
    }
    LL ans = 1e18;
    for(int i = 1;i <= tot;i ++) {
        LL x = 0,pp = p[i];
        for( ; ; ) {
            x += n / pp;
            if(pp > n / p[i]) break;
            pp *= p[i];
        }
        ans = min(ans,x/mi[i]);
    }
    cout << ans << endl;
    return 0;
}
