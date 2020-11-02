#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 1e7 + 19;
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
    freopen("data.in","w",stdout);
    int n = 1000,q = 1000;
    printf("%d\n%d\n",n,q);
    for(int i = 1;i <= q;i ++) {
        int opt = randlr(1,6),x,val;
        switch(opt) {
        case 1:
            x = randlr(1,n);
            val = randlr(-20,20);
            printf("%d %d %d\n",opt,x,val);
            break;
        case 2:
            val = randlr(-20,20);
            printf("%d %d\n",opt,val);
            break;
        case 3:
            val = randlr(-20,20);
            printf("%d %d\n",opt,val);
            break;
        case 4:
            val = randlr(-20,20);
            printf("%d %d\n",opt,val);
            break;
        case 5:
            x = randlr(1,n);
            printf("%d %d\n",opt,x);
            break;
        case 6:
            printf("%d\n",opt);
        }
    }
    puts("1\n0 1");
}
