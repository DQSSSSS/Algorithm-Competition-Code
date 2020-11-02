#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const double PI = acos(-1);

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
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

bool vis[SZ];

void shai(int n) {
	vis[1] = 1;
	for(int i = 2;i * i <= n;i ++)
		for(int j = i * i;j <= n;j += i)
            vis[j] = 1;
}

void fwt(int *a,int n,int opt) {
    for(int i = 1;i < n;i <<= 1) {
        for(int p = i << 1,j = 0;j < n;j += p)
            for(int k = 0;k < i;k ++) {
                int x = a[j + k],y = a[i + j + k];
                a[j + k] = (x + y) % mod; a[i + j + k] = (x - y) % mod;
                if(opt == -1)
                	a[j + k] = 1ll * a[j + k] * 500000004 % mod,
                	a[i + j + k] = 1ll * a[i + j + k] * 500000004 % mod;
            }
    }
}

int a[SZ],ans[SZ],b[SZ];

int main() {
    shai(1e5);
    int n,m;
	while(~scanf("%d%d",&n,&m)) {
		int len = 1; while(len <= m) len <<= 1;
		for(int i = 0;i < len;i ++) ans[i] = 0;
		for(int i = 1;i <= m;i ++) ans[i] = !vis[i];
		fwt(ans,len,1);
		for(int i = 0;i < len;i ++) ans[i] = ksm(ans[i],n);
		fwt(ans,len,-1);
        ans[0] += mod; ans[0] %= mod;
        printf("%d\n",ans[0]);
	}
	return 0;
}
