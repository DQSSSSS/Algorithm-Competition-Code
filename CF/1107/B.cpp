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

int get(int x) {
    int ans = 0;
    while(x) ans += x % 10,x /= 10;
    return ans;
}

int S(int x) {
    while(x >= 10) {
        x = get(x);
    }
    return x;
}

int main() {
    int T = read();
    while(T --) {
        LL k = read(),x = read();
        cout << x + k * 9 - 9 << endl;
    }
    return 0;
}
