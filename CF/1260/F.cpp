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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans %mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

struct seg {
    int l,r;
    pii add;
    pii sum;
}tree[SZ * 4];

void update(int p) {
    tree[p].sum.first = (tree[p<<1].sum.first + tree[p<<1|1].sum.first) % mod;
    tree[p].sum.second = (tree[p<<1].sum.second + tree[p<<1|1].sum.second) % mod;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = make_pair(0,0);
    tree[p].sum = make_pair(0,0);
    if(l == r) {
        return ;
    }
    int mid = l + r >>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushadd(int p,pii d) {
    int len = tree[p].r - tree[p].l + 1;
    (tree[p].sum.first += 1ll * d.first * len % mod ) %= mod;
    (tree[p].add.first += d.first) %= mod;
    (tree[p].sum.second += 1ll * d.second * len % mod) %= mod;
    (tree[p].add.second += d.second) %= mod;
}

void pushdown(int p) {
    if(tree[p].add != make_pair(0,0)) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = make_pair(0,0);
    }
}

void change(int p,int l,int r,pii d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushadd(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >>1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

pii ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >>1;
    pii ans = make_pair(0,0);
    if(l <= mid) {
        pii t = ask(p<<1,l,r);
        ans = t;
    }
    if(mid < r) {
        pii t = ask(p<<1|1,l,r);
        (ans.first += t.first) %= mod;
        (ans.second += t.second) %= mod;
    }
    return ans;
}

vector<int> g[SZ];

int sz[SZ],son[SZ];
int L[SZ],D[SZ];

void dfs_pre(int u,int fa) {
    sz[u] = 1;
    son[u] = 0;
    D[u] = D[fa] + 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs_pre(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}

vector<int> tmp;
int ans = 0;

struct hhhhh{
    int l,r;
}qj[SZ];

pii get_pii(int u,int b) {
    int x = 1ll * D[u] * L[u] * b % mod; x += mod; x %= mod;
    int y = 1ll * L[u] * b % mod; y += mod; y %= mod;
   // cout << u << " " << b << " " << x << " " << y << endl;
    return make_pair(x,y);
}

int get_ans(int u,int d) {
    pii ans = ask(1,qj[u].l,qj[u].r);
  //  printf("%d,%d\n",ans.first,ans.second);
    return (1ll * (D[u] - d) * ans.second % mod + ans.first) % mod
        * L[u] % mod;
}

void dfs2(int u,int fa) {
    tmp.push_back(u);
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs2(v,u);
    }
}
void dfs(int u,int fa,bool c) { //c:u是否是它父亲的重儿子。
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        if(v != son[u])
            dfs(v,u,0);
    }
    if(son[u]) dfs(son[u],u,1);
    (ans += get_ans(u,2*D[u])) %= mod;
   // cout << get_ans(u,2*D[u]) << endl;
   // printf("[%d,%d]\n",qj[u].l,qj[u].r);
    change(1,qj[u].l,qj[u].r,get_pii(u,1));
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == son[u]) continue;
        if(v == fa) continue;
        tmp.clear();
        dfs2(v,u);
        for(int v : tmp) (ans += get_ans(v,2*D[u])) %= mod;
        for(int v : tmp) change(1,qj[v].l,qj[v].r,get_pii(v,1));
    }
    if(!c) {
        tmp.clear();
        dfs2(u,fa);
        for(int v : tmp) change(1,qj[v].l,qj[v].r,get_pii(v,-1));
    }
}


int main() {
    int n = read();
    int sum = 1;
    for(int i = 1;i <= n;i ++) {
        qj[i].l = read();
        qj[i].r = read();
        int len = qj[i].r - qj[i].l + 1;
        L[i] = ksm(len,mod - 2);
        sum = 1ll * sum * len % mod;
    }
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    build(1,1,1e5);
    dfs_pre(1,0);
    ans = 0;
    dfs(1,0,0);
    //cout << ans <<endl;
    ans = 1ll * ans * sum % mod;
    ans += mod; ans %= mod;
    printf("%d\n",ans);
}
/*
2
1 5
1 4
1 2
*/
