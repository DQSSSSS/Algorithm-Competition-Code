#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

LL work(LL n,LL m) {
    for(LL k = 0;;k ++) {
        if(((n^k)&(m^k)) == 0) return k;
    }
}

int main() {
    int T = read();
    while(T --) {
        LL n,m;
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",max(1ll,n&m));
    }
}
