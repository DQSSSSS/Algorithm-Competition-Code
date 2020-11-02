#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

int pri[SZ],tot = 0;
bool vis[SZ];

void shai(int n) {
	for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
        	vis[m] = 1;
            if(i % pri[j] == 0) break;
        }
	}
}

int main() {
    int T;
    scanf("%d",&T);
    shai(1e5);
    while(T --) {
    	ULL n;
    	scanf("%llu",&n);
        ULL f = 1,g = 1,m = n;
        for(ULL j = 1;pri[j] * pri[j] <= n;j ++) {
            ULL i = pri[j];
            if(n % i == 0) {
                ULL t1 = 1,t2 = 1,p = i;
                while(n % i == 0) n /= i,t1 += p * p,t2 ++,p *= i;
            	f *= t1; g *= t2;
            }
        }
        if(n != 1) {
            f *= 1llu + n * n;
            g *= 2;
        }
        printf("%llu\n",f - m * g);
    }
}
