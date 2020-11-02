#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

LL f[SZ],p[SZ],w[SZ];

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 1;i <= n;i ++) {
            p[i] = read();
            w[i] = read();
        }
        for(int i = 1;i <= 10000;i ++) f[i] = 1e18;
        f[0] = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = w[i];j <= 10000;j ++) {
                f[j] = min(f[j],f[j-w[i]]+p[i]);
            }
        }
        LL ans1=1e18,ans2;
        for(int i = m;i <= 10000;i ++) {
            if(f[i] <= ans1)
                ans1 = f[i],ans2 = i;
        }
        printf("%lld %d\n",ans1,ans2);
    }
}
