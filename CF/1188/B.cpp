#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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

int a[SZ],b[SZ];

int main() {
    int n = read(),p = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) {
        int x = a[i];
        b[i] = 1ll * x * x % p * x % p * x % p - 1ll * k * x % p;
        b[i] %= p;
        b[i] += p;
        b[i] %= p;
    }
    sort(b+1,b+1+n);
    LL ans = 0;
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || b[i+1] != b[i]) {
            LL x = i-lst+1;
            ans += x * (x-1) / 2;
            lst = i + 1;
        }
    }
    cout << ans << endl;
}
