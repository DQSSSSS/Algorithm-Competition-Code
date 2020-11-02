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

int randlr(int l,int r) {
    return (rand() << 16 | rand()) % (r-l+1) + l;
}

int main() {
    freopen("H.in","w",stdout);
    srand(time(0));
    int n = randlr(1,500),m = randlr(1,500),q = randlr(1,50);
    printf("%d %d %d\n",n,m,q);
    for(int i = 1;i <= n;i ++) {
        int l = randlr(1,m);
        int r = randlr(1,m);
        if(l > r) swap(l,r);
        printf("%d %d\n",l,r);
    }
    for(int i = 1;i <= q;i ++) {
        int ln = randlr(1,n);
        int rn = randlr(1,n);
        if(ln > rn) swap(ln,rn);
        int lm = randlr(1,m);
        int rm = randlr(1,m);
        if(lm > rm) swap(lm,rm);
        printf("%d %d %d %d\n",ln,lm,rn,rm);
    }
}
