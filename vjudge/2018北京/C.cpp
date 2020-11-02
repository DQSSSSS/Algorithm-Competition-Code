#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

int preG[SZ];
const int MAXN = 1e7;
int mu[100100];
bool vis[100100];
int pri[100100];

void preWork(int n) {
    for(int x = 1;x * x <= n;x += 2) {
        for(int y = 2;x * x + y * y <= n;y += 2) {
            if(__gcd(x,y) == 1)
                preG[x*x+y*y] ++;
        }
    }
    for(int i = 1;i <= n;i ++) preG[i] += preG[i-1];

    n = 100000;
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ pri[0]] = i,mu[i] = -1;
        for(int j = 1,m;j <= pri[0] && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                mu[m] = 0;
            }
            else {
                mu[m] = -mu[i];
            }
        }
    }
}

LL G(int n) {
    if(n <= MAXN) return preG[n];
    LL ans = 0;
    for(int d = 1;d * d * 2 <= n;d ++) {
        int tmp = 0;
        int d2 = d*d,m = n/d2;
        for(int x = 1,lim = sqrt(n-d*d)/d;x*x <= m;x ++) {
            while(lim*lim+x*x > m) lim --;
            if((d*x)&1) tmp += lim / 2;
            else tmp += lim;
        }
        ans += mu[d] * tmp;
    }
    return ans / 2;
}

int main() {
   // freopen("C.in","r",stdin);
    preWork(MAXN);
    int T = read();
    while(T --) {
        int n = read();
        LL ans = 0;
        for(int i = 1,r;i <= n;i = r + 1) {
            r = n / (n / i);
            ans += G(n / i) * (r-i+1);
        }
        printf("%lld\n",ans);
    }
}
/**
3080075432
*/
