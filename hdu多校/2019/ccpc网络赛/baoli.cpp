#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e7 + 10;
const int INF = 1e9 + 10;
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

bool vis[SZ];
int pri[SZ / 10],tot,phi[SZ];
char mu[SZ];

void shai(int n) {
    mu[1] = 1;
    phi[1] = 1;
    for(register int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1,phi[i] = i - 1;
        for(register int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
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
}

int a[SZ];


int main() {
    freopen("3.in","r",stdin); freopen("std.out","w",stdout);
    shai(MAXN);
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        while(m --) {
            int l = read(),r = read();
            UI ans = 0;
            for(int i = l;i <= r;i ++) {
                for(int j = l;j <= r;j ++) {
                    int d = __gcd(a[i],a[j]);
                    ans += phi[d] * (a[i] / d * a[j]);
                }
            }
            printf("%u\n",ans);
        }
    }
}
