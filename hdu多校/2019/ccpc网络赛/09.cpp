#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read(),p = read();
        C[0][0] = 1;
        for(int i = 1;i <= 30;i ++) {
            C[i][0] = 1;
            for(int j = 1;j <= 30;j ++) {
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % p;
            }
        }
        mi[0] = 1;
        for(int i = 1;i <= 900;i ++) mi[i] = mi[i-1] * 2 % p;
        f[0][1][0][1][0] = 1;
        for(int i = 1;i <= n;i ++) {
            for(int j = )
        }
    }
}
