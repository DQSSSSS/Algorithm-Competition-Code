#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const LL INF = 1e18 + 10;
const int mod = 1e9+7;
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

mt19937 rd(time(0));

int rdlr(int l,int r) {
    return rd()%(r-l+1)+l;
}

int main() {
    freopen("J.in","w",stdout);
    int T = 10;
    while(T --) {
        int m = rdlr(1,10);
        int n = rdlr(1,(1<<m)-1);
        printf("%d %d\n",n,m);
        for(int i = 1,lx,ly;i <= n;i ++) {
            int x = rdlr(1,m);
            printf("%d ",x);
        }
        puts("");
    }
}
