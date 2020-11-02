#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

int pri[SZ],tot,mu[SZ];
bool vis[SZ];

void shai(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
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
}

int a[SZ],num[SZ],cx[SZ];

int main() {
    shai(1e6);
    int n = read(),q = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    LL ans = 0;
    while(q --) {
        int x = read();
        if(cx[x]) {
            int d = 0;
            for(int i = 1;i * i <= a[x];i ++) {
                if(a[x] % i == 0) {
                    num[i] --;
                    d += mu[i] * num[i];
                    if(i*i!=a[x]) {
                        num[a[x]/i] --;
                        d += mu[a[x]/i] * num[a[x]/i];
                    }
                }
            }
            ans -= d;
            cx[x] = 0;
        }
        else {
            int d = 0;
            for(int i = 1;i * i <= a[x];i ++) {
                if(a[x] % i == 0) {
                    d += mu[i] * num[i];
                    num[i] ++;
                    if(i*i!=a[x]) {
                        d += mu[a[x]/i] * num[a[x]/i];
                        num[a[x]/i] ++;
                    }
                }
            }
            ans += d;
            cx[x] = 1;
        }
        printf("%lld\n",ans);
    }
}
