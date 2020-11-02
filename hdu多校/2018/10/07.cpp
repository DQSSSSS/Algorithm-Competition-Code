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

int n;
int num[233],ans;
bool use[233];

void dfs(int d) {
    if(d == n + 1) {
    	bool flag = 0;
        for(int i = 1;i < n;i ++) {
            if((num[i] + 1) % n == num[i + 1]) {
				flag = 1;
				break;
            }
        }
        if((num[n] + 1) % n == num[1]) return ;
        if(!flag) ans ++;
        return ;
    }
    for(int i = 1;i < n;i ++){
    	if(!use[i]) {
    		use[i] = 1;
    		num[d] = i;
            dfs(d + 1);
            use[i] = 0;
    	}
    }
}

LL f[SZ],a[SZ];

int main() {
	f[0] = 1; f[1] = 0;
    for(int i = 2;i <= 100001;i ++) {
    	f[i] = (i - 1ll) * ((f[i - 1] + f[i - 2]) % mod) % mod;
	}
	a[0] = 1;
    for(int i = 1;i <= 100001;i ++) {
		a[i] = (f[i - 1] - a[i - 1]) % mod;
		a[i] += mod; a[i] %= mod;
	}
	int T = read();
	while(T --) {
		int n = read();
		printf("%lld\n",a[n]);
	}
	return 0;
}
/**
1 0 0 1 1  8 36
1 0 1 2 9 44 265
*/
