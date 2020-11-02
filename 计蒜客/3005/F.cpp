#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

struct BIT {
    LL tree[SZ];
    int n;

    void add(int x,LL d) {
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }

    LL ask(int x) {
        x = min(x,n);
        LL ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= n;i ++) tree[i] = 0;
    }
}tr;

LL a[SZ];
vector<int> g[SZ];

struct haha {
    int id,b,k;
};

vector<haha> ask[SZ];

int fa[SZ],deep[SZ];

void dfs1(int u,int f) {
    fa[u] = f;
    deep[u] = deep[f] + 1;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs1(v,u);
    }
}

LL ans[SZ];

void dfs(int u) {
  //  for(haha p : ask[u]) printf("%d %d %d %d\n",u,p.id,p.k,p.b);
    for(haha p : ask[u]) {
        ans[p.id] -= p.b * (tr.ask(deep[u]+p.k) - tr.ask(deep[u]-1));
    }
    tr.add(deep[u],a[u]);
    for(int v : g[u]) {
        if(v == fa[u]) continue;
        dfs(v);
    }
    for(haha p : ask[u]) {
        ans[p.id] += p.b * (tr.ask(deep[u]+p.k) - tr.ask(deep[u]-1));
    }
}


int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
    }
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs1(1,0);

    int q = read();
    int tot = 0;
    for(int i = 1;i <= q;i ++) {
        int x = read(),k = read();
        while(x && k>=0) {
            ask[x].push_back((haha){i,1,k});
            if(k-2>=0&&fa[x]) ask[x].push_back((haha){i,-1,k-2});
            x = fa[x]; k --;
        }
    }
    tr.init(n);
    dfs(1);
    for(int i = 1;i <= q;i ++) printf("%lld\n",ans[i]);
}
