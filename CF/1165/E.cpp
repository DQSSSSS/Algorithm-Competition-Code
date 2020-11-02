#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL a[SZ],b[SZ];

int main(){
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read() * i * (n-i+1);
    for(int i = 1;i <= n;i ++) b[i] = read();
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    LL ans = 0;
    for(int i = 1;i <= n;i ++) (ans += a[i]%mod*b[n-i+1]%mod)%=mod;
    cout << ans << endl;
}
