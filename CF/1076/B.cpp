#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

LL find(LL n) {
    for(LL i = 2;i * i <= n;i ++) {
        if(n % i == 0) {
            return i;
        }
    }
    return n;
}

LL my(LL n) {
    LL t = 0;
    while(n) {
        LL x = find(n);
        if(x == 2) {
            t += n / 2;
            break;
        }
        n -= x;
        t ++;
    }
    return t;
}

LL baoli(LL n) {
    LL t = 0;
    while(n) {
        n -= find(n);
        t ++;
    }
    return t;
}

int main() {;
    cout << my(read());
    return 0;
}
