#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3000100;
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

vector<LL> g[3];
set<LL> s;

void add(LL a,vector<LL> &g) {
    g.clear();
    if(a == 1) { g.push_back(1); return ; }
    LL x;
    for(x = 1;x <= 1e18/a;x *= a) g.push_back(x);
    if(x<=1e18) g.push_back(x);
}

int main() {
    int T = read();
    while(T --) {
        s.clear();
        LL a,b,c,L,R;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&L,&R);
        add(a,g[0]); add(b,g[1]); add(c,g[2]);
        s.insert(L-1);
        s.insert(R+1);
        for(LL x : g[0])
            for(LL y : g[1])
                for(LL z : g[2]) {
                    LL d = x+y+z;
                    if(d>=L&&d<=R)
                        s.insert(d);
                }
        LL ans = 0;
        for(auto it = s.begin();it != s.end();it ++) {
            auto i = it; i ++;
            if(i == s.end()) break;
            ans = max(ans,*i-*it-1);
        }
        cout << ans << endl;
    }
}

