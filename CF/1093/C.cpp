#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
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

LL b[SZ],a[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n / 2;i ++) b[i] = read();
    LL L = 0,R = b[1];
    a[1] = 0,a[n] = b[1];
    for(int i = 2;i <= n / 2;i ++) {
        int i1 = i,i2 = n-i+1;
        a[i1] = max(L,b[i] - R);
        a[i2] = b[i] - a[i1];
        L = a[i1]; R = a[i2];
    }
    for(int i = 1;i <= n;i ++) printf("%lld ",a[i]);
    return 0;
}
