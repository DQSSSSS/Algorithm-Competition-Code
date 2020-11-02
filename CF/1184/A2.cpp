#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
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

int n;
char a[SZ];
int f[SZ];

void work(int d) {
    for(int i = 0;i < d;i ++) {
        int tot = 0;
        for(int j = i;j < n;j += d) {
            if(a[j] == '1') tot ++;
        }
        if(tot & 1) { f[d] = 0; return ; }
    }
    f[d] = 1;
}

int main() {
    n = read();
    scanf("%s",a);
    for(int d = 1;d <= n;d ++) {
        if(n % d == 0) {
            work(d);
        }
    }

    int ans = 0;
    for(int k = 1;k < n;k ++) {
        ans += f[__gcd(k,n)];
    }

    bool flag = 0;
    for(int i = 0;i < n;i ++) if(a[i] == '1') flag = 1;
    if(!flag) ans ++;
    cout << ans << endl;
}
