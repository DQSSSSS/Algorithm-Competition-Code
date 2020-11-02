#include<bits/stdc++.h>
#include<windows.h>
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

mt19937 rd(GetTickCount());

int randlr(int l,int r) {
    return rd() % (r-l+1) + l;
}

int a[SZ],L[SZ],R[SZ];

int main() {
    freopen("H.in","w",stdout);
    int T = 200;
    printf("%d\n",T);
    while(T --) {
        int n = randlr(1,10);
        printf("%d\n",n);
        for(int i = 1;i <= n;i ++) printf("%d ",a[i] = randlr(1,3)); puts("");
    }
}
