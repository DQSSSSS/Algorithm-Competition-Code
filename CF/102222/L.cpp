#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
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

int a[SZ];

struct haha {
    int l,r;
    pii ans;
    int add;
}tree[SZ * 4];

void mg(pii &a,pii b) {
    pii ans;
    ans.first = min(a.first,b.first);
    ans.second = 0;
    if(a.first == ans.first) ans.second += a.second;
    if(b.first == ans.first) ans.second += b.second;
    a = ans;
}

void update(int p) {
    tree[p].ans = tree[p<<1].ans;
    mg(tree[p].ans,tree[p<<1|1].ans);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    if(l == r) {
        tree[p].ans = make_pair(0,1);
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushc(int p,int d) {
    tree[p].add += d;
    tree[p].ans.first += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushc(p<<1,tree[p].add);
        pushc(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l<= tree[p].l && tree[p].r <= r) {
        pushc(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

pii ask(int p,int l,int r) {
    if(l<= tree[p].l && tree[p].r <= r) {
        return tree[p].ans;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    pii ans = make_pair(2e9,0);
    if(l <= mid) mg(ans,ask(p<<1,l,r));
    if(mid < r) mg(ans,ask(p<<1|1,l,r));
    return ans;
}

vector<int> g1[SZ],g2[SZ];
int R1[SZ],R2[SZ],nx[SZ];

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        map<int,int> mp;
        for(int i = n;i >= 1;i --) {
            int x = a[i];
            if(!mp.count(x)) nx[i] = 0;
            else nx[i] = mp[x];
            mp[x] = i;
        }

        stack<int> s1,s2;
        for(int i = n;i >= 1;i --) g1[i].clear(),g2[i].clear();
        for(int i = n;i >= 1;i --) {
            int x = a[i];
            while(s1.size() && a[s1.top()] < x) g1[i].push_back(s1.top()),s1.pop();
            R1[i] = s1.size() ? s1.top()-1 : n; s1.push(i);
            x = a[i];
            while(s2.size() && a[s2.top()] > x) g2[i].push_back(s2.top()),s2.pop();
            R2[i] = s2.size() ? s2.top()-1 : n; s2.push(i);
        }
/*
        for(int i = 1;i <= n;i ++) printf("%d ",R1[i]); puts("");
        for(int i = 1;i <= n;i ++) printf("%d ",R2[i]); puts("");
        for(int i = 1;i <= n;i ++) printf("%d ",nx[i]); puts("");
*/
        build(1,1,n);
        LL ans = 0;
        for(int l = n;l >= 1;l --) {
            for(int v : g1[l]) change(1,v,R1[v],-a[v]);
            change(1,l,R1[l],a[l]);
            for(int v : g2[l]) change(1,v,R2[v],a[v]);
            change(1,l,R2[l],-a[l]);
            if(nx[l] == 0) change(1,l,n,-1);
            else {
                change(1,l,nx[l]-1,-1);
            }

            pii p = ask(1,l,n);
            LL tmp = 0;
            if(p.first == -1) tmp = p.second;
           // printf("%d %d %d\n",l,p.first,p.second);
            ans += tmp;
        }

        printf("Case #%d: %lld\n",cc,ans);
    }
}
