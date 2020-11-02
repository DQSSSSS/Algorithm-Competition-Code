#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100000010;
const int INF = 1e9 + 10;
const int mod = 999911659;
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

LL dcnt[SZ];
int MAXN;
int mu[SZ],pmi[SZ],smu[SZ];
int pri[6000010],tot;
bool vis[SZ];

void shai(int n) {
    smu[1] = mu[1] = dcnt[1] = pmi[1] = 1;
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
                dcnt[m] = dcnt[i] * 2;
                pmi[m] = 1;
    		}
    	}
    	smu[i] = (mu[i] < 0 ? -mu[i] : mu[i]) + smu[i - 1];
    	dcnt[i] += dcnt[i - 1];
    }
}

LL sum_mu(LL n) {
	if(n <= MAXN) return smu[n];
    LL ans = 0;
    for(LL i = 1;i * i <= n;i ++)
    	ans += n / (i * i) * mu[i];
    return ans;
}

LL sum_dcnt(LL n) {
	if(n <= MAXN) return dcnt[n];
    LL ans = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
    	r = n / (n / i);
    	ans += n / i * (r - i + 1);
    }
    return ans;
}

LL solve(LL n) {
	LL ans = 0;
	for(LL i = 1,r;i <= n;i = r + 1) {
		r = n / (n / i);
		LL sm = sum_mu(r) - sum_mu(i - 1);
		LL sdcnt = sum_dcnt(n / i);
		ans += sm * sdcnt;
	}
    return ans;
}

LL a[10010];

int main() {
	int T = read();
	LL maxn = 0;
	for(int i = 1;i <= T;i ++) {
		a[i] = read();
		maxn = max(maxn,a[i]);
	}
	MAXN = pow(maxn,2.0/3) + 1;
    shai(MAXN);
    for(int i = 1;i <= T;i ++)
        printf("%lld\n",solve(a[i]));
	return 0;
}
