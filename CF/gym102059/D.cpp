#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 2000100;
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

struct haha {
    int l,r;
}a[SZ];

vector<int> g[SZ],add[SZ],D[SZ];
int n,m,A[SZ],rd[SZ],B[SZ];

set<pii> s;
queue<int> q;

bool check() {
    for(int i = 1;i <= n;i ++) {
        if(rd[i] == 0) q.push(i);
    }
    int sum = 0,maxd = 0;
    while(q.size()) {
        int x = q.front(); q.pop();
        B[++ sum] = x;
        for(int v : g[x]) {
            if(-- rd[v] == 0) {
                q.push(v);
            }
        }
    }
    if(sum != n) return false;

    for(int i = 1;i <= sum;i ++) {
        int x = B[i];
        for(int v : g[x]) {
            a[v].l = max(a[v].l,a[x].l+1);
        }
    }
    for(int i = sum;i >= 1;i --) {
        int x = B[i];
        for(int v : g[x]) {
            a[x].r = min(a[x].r,a[v].r-1);
        }
    }

    for(int x = 1;x <= n;x ++) {
        add[a[x].l].push_back(x);
    }
    for(int i = 1;i <= n;i ++) {
        for(int x : add[i]) s.insert(make_pair(a[x].r,x));
        if(s.empty()) return false;
        auto it = s.begin();
        if(it -> first < i) return false;
        A[i] = it -> second;
        s.erase(it);
    }
    return true;
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i].l = read(),a[i].r = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        rd[y] ++;
    }
    if(check()) {
        for(int i = 1;i <= n;i ++) printf("%d\n",A[i]);
    }
    else {
        puts("-1");
    }
    return 0;
}
