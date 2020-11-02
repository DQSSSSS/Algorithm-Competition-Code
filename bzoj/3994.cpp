#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

bool vis[SZ];
int pri[SZ],tot = 0;
const int MAXN = 1e5;
LL dcnt[SZ],mu[SZ],pmi[SZ];

void shai(int n) {
	mu[1] = dcnt[1] = pmi[1] = 1;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,mu[i] = -1,dcnt[i] = 2,pmi[i] = 1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
            	mu[m] = 0;
				pmi[m] = pmi[i] + 1;
                dcnt[m] = dcnt[i] / (pmi[i] + 1) * (pmi[m] + 1);
            	break;
            }
            else {
            	mu[m] = -mu[i];
            	pmi[m] = 1;
            	dcnt[m] = dcnt[i] * 2;
            }
        }
	}
	for(int i = 1;i <= n;i ++) mu[i] += mu[i - 1],dcnt[i] += dcnt[i - 1];
}

int main() {
    shai(MAXN);
    int T = read();
    while(T --) {
    	int n = read(),m = read();
    	if(n > m) swap(n,m);
        LL ans = 0;
        for(int i = 1,r;i <= n;i = r + 1) {
            r = min(n / (n / i),m / (m / i));
			ans += (mu[r] - mu[i - 1]) * dcnt[n / i] * dcnt[m / i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
