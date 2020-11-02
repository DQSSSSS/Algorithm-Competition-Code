#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
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
    int n = read(),k = read();
    if(n == 0) puts("Austin");
    else if(n <= k) puts("Adrien");
    else {
        if(n % 2 == 0) {
            if(k == 1) puts("Austin");
            else puts("Adrien");
        }
        else puts("Adrien");
    }
    return 0;
}
