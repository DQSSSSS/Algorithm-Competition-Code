#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000100;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

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

LL get_ni(int x) {
	return ksm(x,mod - 2);
}

const int MAXN = 1e6;
int pri[SZ],tot;
bool vis[SZ];
int mu[SZ],smu[SZ];

void shai(int n = MAXN) {
	mu[1] = 1; tot = 0;
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
	for(int i = 1;i <= n;i ++) smu[i] = (smu[i - 1] + mu[i]) % mod;
}

int C[110][110],B[110];

void pre() {
    shai();
    C[0][0] = 1;
    for(int i = 1;i <= 60;i ++) {
        C[i][0] = 1;
        for(int j = 1;j <= i;j ++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    B[0] = 1;
    for(int i = 1;i <= 60;i ++) {
 		int tmp = 0;
 	   	for(int j = 0;j < i;j ++)
    		(tmp += 1ll * C[i + 1][j] * B[j] % mod) %= mod;
        B[i] = -1ll * get_ni(i + 1) * tmp % mod;
   	}
}

LL get_mu(int n) {
	if(n <= MAXN) return mu[n];
    LL ans = 1;
    for(int i = 1;pri[i] * pri[i] <= n;i ++) {
        int p = pri[i];
        if(n % p == 0) {
        	int t = 0;
        	while(n % p == 0) n /= p,t ++;
            if(t > 1) return 0;
            ans = -ans;
        }
    }
    if(n != 1) ans = -ans;
    return ans;
}

unordered_map<int,LL> mu2,mi[55];

LL get_musum(int n) {
	if(n <= MAXN) return smu[n];
    if(mu2[n]) return mu2[n];
    LL ans = 1;
    for(int i = 2,r;i <= n;i = r + 1) {
    	r = n / (n / i);
        (ans -= get_musum(n / i) * (r - i + 1) % mod) %= mod;
    }
    return mu2[n] = ans;
}

LL get_mi(int n,int k) {
    if(mi[k][n]) return mi[k][n];
    LL ans = 0,tmp = 1;
    for(int i = 1;i <= k + 1;i ++) {
    	(tmp *= n + 1) %= mod;
        (ans += 1ll * C[k + 1][i] * B[k + 1 - i] % mod * tmp % mod) %= mod;
    }
    (ans *= get_ni(k + 1)) %= mod;
    if(k == 0) ans --;
    return mi[k][n] = ans;
}

LL baoli(int n,int A,int k) {
    LL ans = 0;
    for(int d = 1;d <= n;d ++) {
        if(A % d == 0) {
            (ans += get_mu(d) * get_mi(n / d,k) % mod) %= mod;
        }
    }
    return ans;
}

int main() {
    pre();
   // int x,k;
   // while(cin >> x >> k) cout << get_mi(x,k) << endl;
    int T = read(),cc = 0;
    while(T --){
		int m = read(),n = read();
		int A = 0,k = 0;
		for(int i = 1;i <= m;i ++) {
            int x = read();
            if(x == -1) k ++;
			else A = __gcd(A,x);
		}
		LL ans = 0;
		if(A == 0) {
			for(int i = 1,r;i <= n;i = r + 1) {
				r = n / (n / i);
				(ans += ((get_musum(r) - get_musum(i - 1)) % mod) * get_mi(n / i,k) % mod) %= mod;
			}
		}
		else {
			for(int d = 1;d * d <= A;d ++) {
				if(A % d == 0) {
                    if(d <= n)
	                    (ans += get_mu(d) * get_mi(n / d,k) % mod) %= mod;
                    if(d * d != A && A / d <= n)
				        (ans += get_mu(A / d) * get_mi(n / (A / d),k) % mod) %= mod;
				}
			}
		}
		ans %= mod; ans += mod; ans %= mod;
       	printf("Case #%d: %lld\n",++ cc,ans);
       	//printf("%lld\n",baoli(n,A,k));
    }
    return 0;
}
