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
    freopen("H.in","w",stdout);
    int n = randlr(1,6000);
    int k = randlr(1,30);
    int B = 10;
    printf("1\n%d %d\n",n,k);
    for(int i = 1;i <= n;i ++) {
        int l = randlr(1,B-1);
        int r = randlr(l+1,B);
        printf("%d %d\n",l,r);
    }
}
