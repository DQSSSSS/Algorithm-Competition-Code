#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int n;
LL m,k;
LL a[SZ],X[SZ],Y[SZ];
char s[SZ];

int main() {
    int x = read(),y = read();
    int x2 = read(),y2 = read();

    int n = read();
    scanf("%s",s + 1);
    for(int i = 1,xx = 0,yy = 0;i <= n;i ++) {
        X[i] = X[i - 1];
        Y[i] = Y[i - 1];
        if(s[i] == 'U') Y[i] ++;
        if(s[i] == 'D') Y[i] --;
        if(s[i] == 'L') X[i] --;
        if(s[i] == 'R') X[i] ++;
    }

    LL l = -1,r = 1e18 + 5;
    while(r - l > 1) {
        LL mid = l + r >> 1;
        LL nx = x + mid / n * X[n] + X[mid % n];
        LL ny = y + mid / n * Y[n] + Y[mid % n];
        if(abs(nx-x2)+abs(ny-y2) <= mid) r = mid;
        else l = mid;
    }
    if(r == 1e18 + 5) r = -1;
    cout << r << endl;
    return 0;
}
