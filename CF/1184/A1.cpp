#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
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

int main() {
    LL r = read() - 1;
    for(LL i = 1;i * i <= r;i ++) {
        if(r % i == 0) {
            LL x = i;
            if(r / x - x - 1 > 0 && (r / x - x - 1) % 2 == 0) {
                cout << x << " " << (r / x - x - 1) / 2 << endl;
                return 0;
            }
        }
    }
    puts("NO");
}
