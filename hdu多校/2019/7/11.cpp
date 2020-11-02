#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

struct haha {
    int x,a,q;
}a[SZ];

int A[SZ],B[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),q = read();
        for(int i = 1;i <= n;i ++) {
            int r = read(),s = read();
            a[i].x = read(),a[i].a = read(); a[i].q = 1ll * r * ksm(s,mod-2) % mod;
        }
        A[1] = 1; B[1] = a[1].a * ksm(a[1].p,mod-2);
        int x = 0,y = 0;
        for(int i = 2;i <= n;i ++) {

        }
    }
}
