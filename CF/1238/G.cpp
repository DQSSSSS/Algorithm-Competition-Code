#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct haha {
    int t,a,b;
}a[SZ];

bool cmp(haha a,haha b) {
    return a.t < b.t;
}

LL work() {
    int n = read(),m = read(),c = read(),now = read();
    for(int i = 1;i <= n;i ++) {
        a[i].t = read();
        a[i].a = read();
        a[i].b = read();
    }
    a[++ n] = (haha){m,0,0};
    sort(a+1,a+1+n,cmp);

    priority_queue<pii> q;

    LL ans = 0;
    int lstt = 0;
    for(int i = 1;i <= n;i ++) {
        int dt = a[i].t - lstt;
        now -= dt;
        if(now < 0) {
            while(now < 0 && q.size()) {
                pii p = q.top(); q.pop();
                int u = -p.first;
                int rst = p.second;
                int use = min(rst,-now);
                ans += 1ll * use * u;
                now += use; rst -= use;
                if(rst) q.push(make_pair(-u,rst));
            }
            if(now < 0) return -1;
        }
        int you = min(a[i].a,c - now);
        q.push(make_pair(-a[i].b,you));

        lstt = a[i].t;
    }
    return ans;
}

int main() {
    int T = read();
    while(T --) {
        printf("%lld\n",work());
    }
}
