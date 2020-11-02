#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 6e5 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

struct segment {
    int l,r;
    vector<pii> v;
    vector<bool> b;
}tree[SZ * 4];

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void add(int p,int l,int r,pii x) {
    if(l <= tree[p].l && tree[p].r <= r) {
       // printf("(%d,%d) [%d,%d]\n",x.first,x.second,tree[p].l,tree[p].r);
        tree[p].v.push_back(x);
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) add(p<<1,l,r,x);
    if(mid < r) add(p<<1|1,l,r,x);
}

LL fa[SZ],sz[SZ][2];
int find(int x) { return x == fa[x] ? x : find(fa[x]); }
LL get_sz(int x) { return sz[x][0]+sz[x][1]; }
LL get_ans(int x) { return sz[x][0]*sz[x][1]; }

stack<pii> S;
LL ans = 0;

bool add(pii v) {
    int x = find(v.first),y = find(v.second);
    if(x == y) return false;
    if(get_sz(x) < get_sz(y)) swap(x,y);
    ans -= get_ans(x); ans -= get_ans(y);
    fa[y] = x;
    sz[x][0] += sz[y][0];
    sz[x][1] += sz[y][1];
    ans += get_ans(x);
    S.push(make_pair(x,y));
   // printf("add (%d,%d)\t(%d,%d)\n",x,y,v.first,v.second);
   // cout << ans << endl;
    return true;
}

void del() {
    if(!S.size()) return ;
    pii p = S.top(); S.pop();
    int x = p.first,y = p.second;
   // printf("del (%d,%d)\n",x,y);
    ans -= get_ans(x);
    sz[x][0] -= sz[y][0];
    sz[x][1] -= sz[y][1];
    ans += get_ans(x); ans += get_ans(y);
    fa[x] = x; fa[y] = y;
   // cout << ans << endl;
}

LL Ans[SZ];

void dfs(int p) {
    tree[p].b.resize(tree[p].v.size());
    //printf("[%d,%d]\n",tree[p].l,tree[p].r);
    for(int i = 0;i < tree[p].v.size();i ++) tree[p].b[i]=add(tree[p].v[i]);
    if(tree[p].l == tree[p].r) Ans[tree[p].l] = ans;
    else dfs(p<<1),dfs(p<<1|1);
    for(int i = tree[p].v.size()-1;i >= 0;i --) if(tree[p].b[i]) del();
}

pii a[SZ];
map<pii,int> mp;

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        int x = read(),y = read();
        a[i] = make_pair(x,y+3e5);
    }

    build(1,1,n);
    for(int i = 1;i <= n;i ++) {
        pii p = a[i];
        if(mp.count(p)) add(1,mp[p],i-1,p),mp.erase(p);
        else mp[p] = i;
    }
    for(auto it = mp.begin();it != mp.end();it ++)
        add(1,it->second,n,it->first);

    for(int i = 1;i <= 6e5;i ++) fa[i] = i,sz[i][i<=3e5] = 1;
    dfs(1);
    for(int i = 1;i <= n;i ++)
        printf("%I64d ",Ans[i]);
    return 0;
}
