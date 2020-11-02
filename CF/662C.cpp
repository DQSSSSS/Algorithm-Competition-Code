#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2500010;
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

int n,m;

int get_count(int x) {
	int ans = 0;
	for(int i = 0;i < n;i ++) ans += x >> i & 1;
    return ans;
}

void fwt(LL *a,int n,int opt) {
    for(int i = 1;i < n;i <<= 1) {
    	for(int p = i << 1,j = 0;j < n;j += p) {
			for(int k = 0;k < i;k ++) {
                LL x = a[j + k],y = a[i + j + k];
                a[j + k] = (x + y);
                a[i + j + k] = (x - y);
                if(opt == -1) a[j + k] /= 2,a[i + j + k] /= 2;
			}
    	}
    }
}

LL num[SZ],f[SZ];
char s[22][100010];

int main() {
    n = read(),m = read();
    for(int i = 0;i < n;i ++) scanf("%s",s[i]);
    for(int i = 0;i < m;i ++) {
        int x = 0;
        for(int j = 0;j < n;j ++)
			x |= (s[j][i] - '0') << j;
        num[x] ++;
    }
    for(int i = 0;i < (1 << n);i ++) f[i] = min(get_count(i),n - get_count(i));
    fwt(f,1 << n,1); fwt(num,1 << n,1);
    for(int i = 0;i < (1 << n);i ++) f[i] = 1ll * f[i] * num[i];
    fwt(f,1 << n,-1);
    LL ans = n * m + 1;
    for(int i = 0;i < (1 << n);i ++) ans = min(ans,f[i]);
    printf("%lld\n",ans);
    return 0;
}
