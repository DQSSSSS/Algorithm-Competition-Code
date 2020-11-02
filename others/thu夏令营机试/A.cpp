#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[SZ];

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        char s[2];
        int x,y;
        scanf("%s",s);
        x = read(),y = read();
        if(s[0] == 'A') a[x] += y;
        else a[x] -= y;
        a[x] = max(a[x],0);
        a[x] = min(a[x],(int)1e9);
    }
    for(int i = 1;i <= n;i ++) printf("%d\n",a[i]);
    return 0;
}
