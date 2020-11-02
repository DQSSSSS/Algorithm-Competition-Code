#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 20000010;
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

bool vis[SZ];
int pri[SZ],tot = 0;
int phi[SZ];
LL sum[SZ];

void init(int n){
	phi[1] = 1;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                phi[m] = phi[i] * pri[j];
                break;
            }
            else {
                phi[m] = phi[i] * (pri[j] - 1);
            }
		}
	}
	for(int i = 1;i <= n;i ++)
		sum[i] = sum[i - 1] + (i & 1 ? phi[i] / 2 : phi[i]);
}

int main() {
	int T = read();
	init(2e7);
	while(T --) {
		int n = read();
        printf("%lld\n",sum[n]);
	}
}

