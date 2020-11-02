#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const double INF = 1e10 + 10;
const int mod = 998244353;
const LD eps = 1e-6;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

const int BASE = 1e6+3;
const int MOD = 1e9+9;

ULL h[SZ],mi[SZ];

ULL getlr(int l,int r) {
    return h[r] - h[l-1] * mi[r-l+1];
}

set<ULL> get(int a[],int n) {
    for(int i = 1;i <= n;i ++) {
        h[i] = (h[i-1] * BASE + a[i]);
    }
    set<ULL> s;
    for(int i = 1;i <= n;i ++) {
        ULL x = getlr(1,i) + getlr(i+1,n) * mi[i];
      //  cout << i << " " << x << endl;
        s.insert(x);
    }
    return s;
}

int a[SZ];

int main(){
    mi[0] = 1;
    for(int i = 1;i <= 1e5;i++) mi[i] = mi[i-1] * BASE;
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) a[i] = read();

        set<ULL> s = get(a, n);
        reverse(a+1,a+1+n);
        set<ULL> t = get(a, n);

        for(auto p : t) s.insert(p);
        printf("%d\n",s.size());
    }
}
