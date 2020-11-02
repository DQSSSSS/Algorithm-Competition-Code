#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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

mt19937 rd(time(0));

int randlr(int l,int r) {
    return rd() % (r-l+1) + l;
}

int a[SZ],L[SZ],R[SZ];

int main() {
    freopen("G.in","w",stdout);
    int n = randlr(1,10000),q = randlr(1,10000);
    printf("%d %d\n",n,q);
    for(int i = 1;i <= n;i ++) a[i] = i;
    for(int i = 1;i <= n;i ++) swap(a[i],a[randlr(i,n)]);
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
    for(int i = 1;i <= q;i ++) printf("%d ",L[i]=randlr(1,n)); puts("");
    for(int i = 1;i <= q;i ++) printf("%d ",R[i]=randlr(L[i],n)); puts("");
}
