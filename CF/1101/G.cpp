#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

int b[SZ];

void insert(int x) {
    for(int i = 30;i >= 0;i --) {
        if(x >> i & 1) {
            if(!b[i]) { b[i] = x; break; }
            x ^= b[i];
        }
    }
}

int main() {
    int n = read();
    int sum = 0;
    for(int i = 1;i <= n;i ++) {
        int x = read();
        sum ^= x;
        insert(sum);
    }
    if(sum == 0) puts("-1");
    else {
        int ans = 0;
        for(int i = 0;i <= 30;i ++) if(b[i]) ans ++;
        cout << ans << endl;
    }
}
