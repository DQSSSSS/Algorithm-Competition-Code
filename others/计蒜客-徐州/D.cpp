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

int MAXN = 1e5;
int mu[SZ],pri[SZ],tot,Smu[SZ];
bool vis[SZ];

void shai(int n = MAXN) {
	MAXN = n;
	mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                mu[m] = 0;
                break;
            }
            else {
				mu[m] = -mu[i];
            }
        }
    }
    for(int i = 1;i <= n;i ++) Smu[i] = Smu[i - 1] + mu[i];
}

unordered_map<int,LL> mu2,Smu2;

LL get_mu(LL n) {
    if(n <= MAXN) return mu[n];
    if(mu2[n]) return mu2[n] == -2 ? 0 : mu2[n];
	LL ans = 1;
    for(int i = 1;1ll * pri[i] * pri[i] <= n;i ++) {
    	LL p = pri[i];
        if(n % p == 0) {
            int t = 0;
            while(n % p == 0) n /= p,t ++;
            if(t >= 2) return mu2[n] = -2,0;
            ans = -ans;
        }
    }
    if(n != 1) ans = -ans;
    return mu2[n] = ans;
}

LL sum_mu(LL n) {
	//cout << n << endl;
    if(n <= MAXN) return Smu[n];
    if(Smu2[n]) return Smu2[n];
	LL ans = 1;
    for(LL i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        ans -= sum_mu(n / i) * (r - i + 1);
    }
    return Smu2[n] = ans;
}

unordered_map<LL,unordered_map<LL,LL> > mp;

LL dfs(LL m,LL n) {
	//cout << m << " haha " << n << endl;
    if(m == 0) return 0;
    if(n == 1) return sum_mu(m);
    if(mp[m][n]) return mp[m][n];
    LL ans = 0;
    for(LL d = 1;d * d <= n;d ++) {
       	if(n % d == 0) {
            ans += get_mu(d) * dfs(m / d,d);
            if(d * d != n) {
                ans += get_mu(n / d) * dfs(m / (n / d),n / d);
            }
       	}
    }
    return mp[m][n] = ans * get_mu(n);
}

LL baoli(LL m,LL n) {
    LL ans = 0;
    for(int i = 1;i <= m;i ++)
    	ans += get_mu(i * n);
   	return ans;
}

int main() {
    shai(1e7);
    LL m = read(),n = read();
    printf("%lld\n",dfs(m,n));
    //printf("%lld\n",baoli(m,n));
    return 0;
}
