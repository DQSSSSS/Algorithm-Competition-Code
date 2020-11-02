#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e7 + 10;
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

const int MAXN = 1e7;
int pmi[SZ];
LL f[SZ],F[SZ],rst[SZ];
int pri[SZ / 10],tot;
bool vis[SZ];

void shai(int n = MAXN) {
	F[1] = f[1] = 0;
	rst[1] = pmi[1] = 1;
    for(register int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,f[i] = 1,pmi[i] = 1,F[i] = 1,rst[i] = 1;
    	for(register int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
				pmi[m] = pmi[i] + 1;
				rst[m] = rst[i];
				f[m] = max(f[i],1ll * pmi[m]);
				if(rst[m] == 1) F[m] = 1;
                else if(pmi[m] == f[rst[m]]) F[m] = -F[rst[m]];
                else F[m] = 0;
                break;
            }
            else {
                pmi[m] = 1;
				rst[m] = i;
                f[m] = f[i];
                if(f[i] == 1)
	                F[m] = -F[i];
	            else
	            	F[m] = 0;
            }
    	}
    }
    for(int i = 1;i <= n;i ++) F[i] += F[i - 1];
}
int main() {
    shai();
    int T = read();
    while(T --) {
        int n = read(),m = read();
        if(n > m) swap(n,m);
        LL ans = 0;
        for(int i = 1,r;i <= n;i = r + 1) {
            r = min(n / (n / i),m / (m / i));
            ans += 1ll * (F[r] - F[i - 1]) * (n / i) * (m / i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
