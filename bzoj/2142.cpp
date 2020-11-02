#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
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

int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
           		break;
            }
            else {
            }
		}
    }
}

LL ksm(LL a,LL b,LL mod) {
    LL ans = 1;
    while(b) {
    	if(b & 1) ans = ans * a % mod;
    	a = a * a % mod;
    	b >>= 1;
    }
    return ans;
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
    	if(b & 1) ans = ans * a;
    	a = a * a;
    	b >>= 1;
    }
    return ans;
}

LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
    	x = 1; y = 0;
    	return a;
    }
    LL d = exgcd(b,a%b,x,y);
    LL t = x;
    x = y; y = t - a / b * y;
    return d;
}

pii dfs(int n,LL p,LL mod) {
	pii ans = make_pair(1,0);
	if(n <= mod) {
        for(int i = 1;i <= n;i ++) {
        	int x = i;
            while(x % p == 0) ans.second ++,x /= p;
            (ans.first *= x) %= mod;
        }
	}
	else {
    	LL m = n / mod * mod / p;
        pii tmp = dfs(m,p,mod);
        for(int i = 1;i <= mod;i ++) {
            if(i % p == 0) continue;
            (ans.first *= i) %= mod;
        }
        ans.first = ksm(ans.first,n / mod,mod);
        ans.second = n / mod * mod / p;
        for(int i = n - n % mod + 1;i <= n;i ++) {
            int x = i;
            while(x % p == 0) ans.second ++,x /= p;
            (ans.first *= x) %= mod;
        }
        (ans.first *= tmp.first) %= mod;
		ans.second += tmp.second;
	}
	return ans;
}

LL work(LL m[],LL a[],int n) {
    LL M = m[1],A = a[1],x,y;
    for(int i = 2;i <= n;i ++) {
    	LL d = exgcd(M,m[i],x,y);
        if((a[i] - A) % d) return -1;
        x *= (a[i] - A) / d;
        LL t = m[i] / d; x = (x % t + t) % t;
        A = M * x + A; M = M / d * m[i]; A %= M;
    }
	return (A += M) %= M;
}

LL M[SZ],a[SZ],P[SZ];
LL p,n,m,c[SZ];

int main() {
	shai(1e5);
    p = read(); n = read(); m = read();
    LL sum = 0;
    for(int i = 1;i <= m;i ++) c[i] = read(),sum += c[i];
    if(n < sum) { puts("Impossible"); return 0; }
    c[++ m] = n - sum;
    for(int i = 1;i <= tot;i ++) {
        if(p % pri[i] == 0) {
			P[++ P[0]] = pri[i];
			M[++ M[0]] = 1;
        	while(p % pri[i] == 0) p /= pri[i],M[M[0]] *= pri[i];
        }
    }
    if(p != 1) {
		P[++ P[0]] = p;
		M[++ M[0]] = p;
    }
    for(int i = 1;i <= P[0];i ++) {
        pii ans = dfs(n,P[i],M[i]);
        LL mi = M[i] == 2 ? 1 : M[i] / P[i] * (P[i] - 1);
        for(int j = 1;j <= m;j ++) {
        	pii tmp = dfs(c[j],P[i],M[i]);
            (ans.first *= ksm(tmp.first,mi - 1,M[i])) %= M[i];
            ans.second -= tmp.second;
        }
        a[i] = ans.first * ksm(P[i],ans.second,M[i]) % M[i];
    }
    printf("%lld\n",work(M,a,P[0]));
    return 0;
}
