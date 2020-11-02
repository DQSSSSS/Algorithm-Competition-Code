#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

int C;

struct FF {

    struct BIT {
        int n;

        struct node {
            int l,r;
            int maxn;
        }tree[SZ << 2];

        void update(int p) {
            tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
        }

        void build(int p,int l,int r) {
            tree[p].l = l;
            tree[p].r = r;
            if(l == r) {
                tree[p].maxn = 0;
                return ;
            }
            int mid = l + r >> 1;
            build(p<<1,l,mid);
            build(p<<1|1,mid+1,r);
            update(p);
        }


        void change(int p,int x,int d) {
            if(tree[p].l == tree[p].r) {
                tree[p].maxn = d;
                return ;
            }
            int mid = tree[p].l + tree[p].r >> 1;
            if(x <= mid) change(p<<1,x,d);
            else change(p<<1|1,x,d);
            update(p);
        }

        int ask(int p,int val) {
            if(tree[p].l == tree[p].r) {
                if(tree[p].maxn < val) return INF;
                return tree[p].l;
            }
            if(tree[p<<1].maxn < val) return ask(p<<1|1,val);
            return ask(p<<1,val);
        }

        int ask(int val) {
            return ask(1,val);
        }

        void change(int x,int d) {
            change(1,x,d);
        }

        void init(int nn) {
            n = nn;
            build(1,1,n);
        }
    }bit;

    int ans, a[SZ];

    void add(int x) {
        int id = bit.ask(x);
        if(id == INF) {
            ans ++;
            bit.change(ans, C-x);
            a[ans] = C-x;
        } else {
            bit.change(id, a[id] - x);
            a[id] -= x;
        }
    }

    void init(int nn) {
        ans = 0;
        bit.init(nn);
        for(int i = 1;i <= nn;i ++) a[i] = 0;
    }

}ff;

struct BF {

    int ans;
    multiset<int> s;

    void add(int x) {
        auto it = s.lower_bound(x);
        if(s.empty() || it == s.end()) {
            ans ++;
            s.insert(C-x);
        } else {
            int t = *it - x;
            s.erase(it); s.insert(t);
        }
    }

    void init() {
        ans = 0;
        s.clear();
    }
}bf;

int main() {
    int T = read();
    while(T --) {
        int n = read();
        C = read();
        ff.init(n); bf.init();
        for(int i = 1;i <= n;i ++) {
            int x = read();
            ff.add(x);
            bf.add(x);
        }
        printf("%d %d\n",ff.ans,bf.ans);
    }
}
/*
2
2 2
1 1
5 10
5 8 2 5 9

*/
