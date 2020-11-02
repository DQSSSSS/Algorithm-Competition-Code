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

int main() {
    int b = read(),k = read(),ans = 0;
    for(int i = 1;i <= k;i ++) a[i] = read();
    int mi = 1;
    for(int i = 1;i <= k;i ++) {
        ans = (ans + a[k-i+1] * mi % 2) % 2;
        mi = mi * b % 2;
    }
    if(ans) puts("odd");
    else puts("even");
    return 0;
}
