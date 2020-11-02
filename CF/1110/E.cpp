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

LL a[SZ],b[SZ];

int main() {
    int n = read();
    LL a1 = 0,b1 = 0;
    for(LL i = 1,lst;i <= n;i ++) {
        LL x = read();
        if(i > 1) a[i-1] = x - lst;
        else a1 = x;
        lst = x;
    }
    for(LL i = 1,lst;i <= n;i ++) {
        LL x = read();
        if(i > 1) b[i-1] = x - lst;
        else b1 = x;
        lst = x;
    }
    sort(a+1,a+n);
    sort(b+1,b+n);
    if(a1 != b1) { puts("No"); return 0; }
    for(int i = 1;i < n;i ++) if(a[i] != b[i]) { puts("No"); return 0; }
    puts("Yes");
    return 0;
}
