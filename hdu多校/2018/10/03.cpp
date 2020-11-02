#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 10000010;
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
UI mup[SZ],rst[SZ],cnt[SZ],f2[SZ],f3[SZ];

void init(){
	mup[1] = f2[1] = f3[1] = rst[1] = cnt[1] = 1;
	for(int i = 2;i <= 1e7;i ++) {
		if(!vis[i]) pri[++ tot] = i,mup[i] = i - 2,rst[i] = 1,cnt[i] = 1,f2[i] = i,f3[i] = i;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= 1e7;j ++) {
            vis[m] = 1;
            int p = pri[j];
            if(i % p == 0) {
            	rst[m] = rst[i];
                cnt[m] = cnt[i] + 1;
                int pk = m / rst[m];
                mup[m] = (pk - 2 * pk / p +  pk / (p * p)) * mup[rst[m]];
                f2[m] = cnt[m] % 2 == 1 ? f2[i] * p : f2[i];
                f3[m] = cnt[m] % 3 == 1 ? f3[i] * p : f3[i];
                break;
            }
            else {
                mup[m] = mup[i] * (p - 2);
                rst[m] = i;
                cnt[m] = 1;
                f2[m] = p * f2[i];
                f3[m] = p * f3[i];
            }
		}
	}
}

int main() {
	init();
	int T = read();
	while(T --) {
        UI A = read(),B = read(),C = read();
        UI ans = 0;
        for(int i = 1;i <= A;i ++) {
            ans += mup[i] * (A / i) * (B / f2[i]) * (C / f3[i]);
        }
        cout << (ans & ((1u << 30u) - 1u)) << endl;
	}
	return 0;
}
