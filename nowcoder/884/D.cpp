#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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

int main() {
    int T = read();
    while(T --) {
        LL n = read();
        if(n%3 == 0) { printf("%d %lld\n",1,n); continue; }
        vector<LL> g[2];
        int p = n%3-1;
        for(int i = 0;i < 62;i ++)
            if(n>>i&1) g[i&1].push_back(1ll<<i);
        if(g[p].size() >= 2) {
            printf("2 %lld %lld\n",n^g[p][0],n^g[p][1]);
        }
        else if(g[p].size() == 1) {
            printf("2 %lld %lld\n",n^g[p][0],g[p][0]^g[p^1][0]);
        }
        else {
            printf("2 %lld %lld\n",n^g[p^1][0]^g[p^1][1],g[p^1][0]^g[p^1][1]^g[p^1][2]);
        }
    }
}
/**
1001
*/
