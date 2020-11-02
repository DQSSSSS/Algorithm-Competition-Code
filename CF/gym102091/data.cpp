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
    freopen("K.in","w",stdout);
    puts("10");
    int T = 10;
    while(T --) {
        int n = randlr(100000,100000);
        printf("%d\n",n);
        int st = 1;
        int maxtime = 1;
        for(int i = 1;i <= n;i ++) {
            int op = randlr(1,5);
            if(op <= 4) {
                int l = randlr(st,maxtime);
                int r = randlr(l,maxtime);
                int val = randlr(1,1e6);
                st = max(st,l);
                printf("1 %d %d %d\n",l,val,r);
            }
            else {
                int l = randlr(st,maxtime);
                int k = randlr(1,n);
                st = max(st,l);
                printf("2 %d %d\n",l,k);
            }
        }
    }
}
