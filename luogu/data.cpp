#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

mt19937 rd(time(0));

int randlr(int l,int r) { return rd()%(r-l+1)+l; }

int main() {
    freopen("4198.in","w",stdout);
    int n = 100000;
    int m = 100000;
    printf("%d %d\n",n,m);
    for(int i = 1;i <= m;i ++) {
        int x = randlr(1,n);
        int y = randlr(1,2*n);
        printf("%d %d\n",x,y);
    }
}
