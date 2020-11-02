#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 10000010;
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

int pri[SZ],tot;
bool vis[SZ];
LL F[SZ],cnt[SZ],rst[SZ];

void shai(int n) {
	F[1] = cnt[1] = rst[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,F[i] = -1,cnt[i] = 1,rst[i] = 1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            int p = pri[j];
            if(i % p == 0) {
                cnt[m] = cnt[i] + 1;
				rst[m] = rst[i];
				F[m] = F[rst[m]] * (cnt[m] & 1 ? -1 : 1);
            	break;
            }
            else {
				cnt[m] = 1;
                rst[m] = i;
				F[m] = F[i] * F[p];
            }
        }
    }
    for(int i = 1;i <= n;i ++) F[i] += F[i - 1];
}

int main() {
    shai(1e7);
    int T = read();
    while(T --) {
        LL n = read(),m = read();
        if(n > m) swap(n,m);
        LL ans = 0;
        for(int i = 1,r;i <= n;i = r + 1) {
            r = min(n / (n / i),m / (m / i));
            ans += (F[r] - F[i - 1]) * (n / i) * (m / i);
        }
        printf("%lld\n",n * m - ans);
    }
    return 0;
}
