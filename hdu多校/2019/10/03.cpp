#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

LL work(vector<int>& g) {
    if(g.size() == 0) return 0;
    if(g.size() == 1) return g[0] * 1000000ll;
    LL B12 = 1000000000000ll,B6 = 1000000;
    LL now = g[0] * 1000000ll;
    LL no = (1000000 - g[0]) * B6,ans = 0;
    for(int i = 1;i < g.size();i ++) {
        LL x = g[i];
        now = x*no+(1000000-x)*now;
        no = no * (1000000-x);
        for(int j = 1;j <= 6;j ++) now /= 10,no /= 10;
        ans = max(ans,now);
        if(now < ans) return ans;
//        printf("%012lld %012lld\n",now,no);
    }
//    printf("%012lld\n",now);
    return now;
}

int main() {
    int T = read();
    while(T --) {
        int n = read();
        vector<int> g;
        LL flag = 0;
        for(int i = 1;i <= n;i ++) {
            int x,y;
            scanf("%d.%d",&y,&x);
            if(y == 1) flag = 1;
            g.push_back(x);
        }
        if(flag) { puts("1.000000000000000000"); continue; }
        LL t = work(g);
//        printf("%lld %lld\n",ans,t);
        printf("0.%lld\n",t);
    }
}
/**
233
4
0.100000 0.200000 0.300000 0.900000
4
0.900000 0.900000 0.900000 0.900000
4
0.100000 0.100000 0.100000 0.100000
4
0.400000 0.400000 0.400000 0.400000
*/
