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

int C[2010][2010];

void init(int n) {
    C[0][0] = 1;
    for(int i = 1;i <= n;i ++) {
        C[i][0] = 1;
        printf("%3d: ",i);
        for(int j = 1;j <= i;j ++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % 3;
            if(C[i][j] == 0) printf("1 ");
            else printf("  ");
        }
        puts("");
    }
}

int main() {
    freopen("Fbiao.txt","w",stdout);
    init(100);
}
