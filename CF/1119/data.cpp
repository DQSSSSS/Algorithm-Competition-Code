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

int main() {
    freopen("F.in","w",stdout);
    int n = randlr(250000,250000),val = 10;
    printf("%d\n",n);
    for(int i = 2;i <= n/3;i ++)
        printf("%d %d %d\n",i,i-1,randlr(1,val));
    for(int i = n/3+1;i <= n;i ++) {
        printf("%d %d %d\n",i,randlr(1,i-1),randlr(1,val));
    }
}
