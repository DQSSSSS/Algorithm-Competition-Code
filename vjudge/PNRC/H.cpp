#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

int zu[22];

LL dfs(LL n,LL d,LL f) {
    if(n == 0 && d == 0) return 1;
    if(n < 0 || n >= 20*d) return 0;
    if(d == 1) return n % 2 == 0;
    LL ans = 0;
    for(int p = n%10;p < 20;p += 10) {
        ans += (zu[p]-f) * dfs((n-p*d-p)/10,d/100,0);
        f = 0;
    }
    return ans;
}

int main() {
    for(int i = 0;i <= 9;i ++)
        for(int j = 0;j <= 9;j ++)
            zu[i+j] ++;
    int T = read();
    while(T --) {
        LL n = read();
        LL ans = 0;
        for(LL d = 1;d <= n;d *= 10) {
            ans += dfs(n,d,1);
        }
        printf("%lld\n",ans);
    }
}

/**
8
1111
*/
