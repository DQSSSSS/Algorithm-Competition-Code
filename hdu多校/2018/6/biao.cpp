#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

int a[233],ans = 0,n,m;

void dfs(int d,int now) {
    if(d == m + 1) {
    	if(now) return ;
    	int ans = 0;
        for(int i = 1;i <= m;i ++)
    		ans = __gcd(ans,a[i]);
        if(ans == 1) ::ans ++;
        return ;
    }
    for(int i = 0;i <= now;i ++) {
    	a[d] = i;
    	dfs(d + 1,now - i);
    }
}

int main() {
    for(n = 1;n <= 100;n ++)
    	for(m = n;m <= n;m ++) {
    		ans = 0;
            dfs(1,n);
    		printf("%d,",ans);
    	}
}
