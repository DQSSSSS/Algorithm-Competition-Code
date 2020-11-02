#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e5 + 10;
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
int mu[SZ],pri[SZ],tot;
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
}
inline long long Mod(long long x,long long y,long long mod)
{
	long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
	return tmp<0 ? tmp+mod : tmp;
}

LL p;

LL sum2(LL n) {
    LL x = n,y = n + 1,z = 2 * n + 1;
    if(x % 2 == 0) x /= 2;
    else y /= 2;
    if(x % 3 == 0) x /= 3;
    else if(y % 3 == 0) y /= 3;
    else z /= 3;
    return Mod(Mod(x,y,p),z,p);
}
LL sum3(LL n) {
    LL x = n,y = n + 1;
    if(x % 2 == 0) x /= 2;
    else y /= 2;
    LL d = Mod(x,y,p);
    return Mod(d,d,p);
}


LL f1[SZ],f2[SZ];

int main() {
    shai(1e5);
    LL n;
    while(~scanf("%lld%lld",&n,&p)) {
        for(LL i = 1;i * i <= n;i ++) {
        	if(mu[i]) {
                LL d = Mod(i,i,p);
        		f1[i] = mu[i] * Mod(d,d,p);
                f2[i] = mu[i] * Mod(Mod(d,d,p),d,p);
    		}
    	}
    	LL ans1 = 0,ans2 = 0;
        for(LL i = 1;i * i <= n;i ++) {
            LL d = i * i;
            (ans1 += Mod(f1[i],sum2(n / d),p)) %= p;
            (ans2 += Mod(f2[i],sum3(n / d),p)) %= p;
        }
        ans1 = Mod(ans1,n + 1,p);
        LL ans = ans1 - ans2; ans %= p;
        ans += p; ans %= p;
		printf("%lld\n",ans);
    }
    return 0;
}
/**
1 1 1
2 5 9
3 14 36
4 14 36
5 39 161
6 75 377
7 124 720
8 124 720
9 124 720
10 224 1720
11 345 3051
12 345 3051
13 514 5248
14 710 7992
15 935 11367
16 935 11367
17 1224 16280
18 1224 16280
19 1585 23139
20 1585 23139
*/
