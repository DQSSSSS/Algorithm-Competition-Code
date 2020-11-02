#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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
LL phi[SZ],mu[SZ];

void shai(int n) {
	mu[1] = phi[1] = 1;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,mu[i] = -1,phi[i] = i - 1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
            	mu[m] = 0;
            	phi[m] = phi[i] * pri[j];
            	break;
            }
            else {
            	mu[m] = -mu[i];
            	phi[m] = phi[i] * (pri[j] - 1);
            }
        }
	}
	for(int i = 1;i <= n;i ++) mu[i] += mu[i - 1],phi[i] += phi[i - 1];
}

LL phi2[SZ],mu2[SZ];
int cnt = 0,use[SZ],N;

struct haha {
	LL first,second;
	haha(LL a,LL b) : first(a),second(b) {}
};

haha dfs(LL n) {
	if(n <= 17e5) return haha(phi[n],mu[n]);
	LL t = N / n;
	if(use[t] == cnt) return haha(phi2[t],mu2[t]);
    LL ansphi = n * (n + 1) / 2;
    LL ansmu = n >= 1;
    for(LL i = 2,r;i <= n;i = r + 1) {
    	r = n / (n / i);
        haha tmp = dfs(n / i);
        ansphi -= tmp.first * (r - i + 1);
        ansmu -= tmp.second * (r - i + 1);
    }
    use[t] = cnt;
    return haha(phi2[t] = ansphi,mu2[t] = ansmu);
}

int main() {
    shai(17e5);
    int T = read();
    while(T --) {
    	N = read();
    	cnt ++;
        haha ans = dfs(N);
        printf("%lld %lld\n",ans.first,ans.second);
    }
    return 0;
}
