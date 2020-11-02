#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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

int fac[SZ],n;

int main() {
    fac[0] = 1;
    for(int i = 1;i < mod;i ++) fac[i] = 1ll * i * fac[i-1] % mod;
    while(~scanf("%d",&n)) {
        int ans = n < mod ? fac[n] : 0;
        printf("%d\n",ans);
    }
}
