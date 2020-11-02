#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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


bool isp(int n) {
    if(n<=1) return false;
    for(int i = 2;i * i <= n;i ++) {
        if(n%i==0) return false;
    }
    return true;
}

int bl(int n) {
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(!isp(i)) continue;
        LL p = i,now = 1;
        for(LL k = 1;now * p <= n;k ++) {
            now *= p;
            (ans += n / now) %= mod;
        }
    }
    return ans;
}

int baoli(int n) {
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        (ans += bl(i)) %= mod;
    }
    return ans;
}

int main() {
    int n = read();
    cout << baoli(n) << endl;
}
