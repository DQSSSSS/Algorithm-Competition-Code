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

LL L[11],R[11]

LL f(int n,int k) {
    if(n == 1) {
        int ll = max(1,L[1]);
        int rr = min(n,R[1]);
        return max(0,rr-ll+1);
    }
    return f(n-L[i],k-1) - f(n-R[i]-1,k-1);
}

LL work() {
    for(int i = 1;i <= 4;i ++) {
        if(L[i] > R[i]) return 0;
    }
    LL ans =
}

int main() {
    int T = read();
    while(T --) {
        for(int i = 1;i <= 4;i ++) {
            L[i] = read();
            R[i] = read();
        }
        printf("%lld\n",work());
    }
}
