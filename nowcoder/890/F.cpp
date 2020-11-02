#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

const int N = 3e5+100;

struct seg {
    int l,r,mx;
}tree[N * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].mx = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void change(int p,int x,int d) {
    if(tree[p].l == tree[p].r) {
        tree[p].mx = d;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(p);
}


struct haha {
    int x,y;
}a[SZ];

int n,R,r[SZ],c[SZ];

map<pii,int> mp;

int ask(int x,int y) {
    int ans = r[x] + c[y];
    for(int i = -1;i <= 1;i ++) {
        for(int j = -1;j <= 1;j ++) {
            if(mp.count(make_pair(x+i*R,y+j*R)))
                ans -= mp[make_pair(x+i*R,y+j*R)];
        }
    }
    return ans;
}

vector<int> nodeList[N];

void add_node(int y) {
    for(int x : nodeList[y]) {
        change(1,x-R,-INF);
        change(1,x,-INF);
        change(1,x+R,-INF);
    }
}

void del(int y) {
    for(int x : nodeList[y]) {
        change(1,x-R,r[x-R]);
        change(1,x,r[x]);
        change(1,x+R,r[x+R]);
    }
}

int main() {
    n = read(),R = read();
    for(int i = 1;i <= n;i ++) {
        a[i].x = read()+R+10;
        a[i].y = read()+R+10;
        r[a[i].x-R] ++; r[a[i].x] ++; r[a[i].x+R] ++;
        c[a[i].y-R] ++; c[a[i].y] ++; c[a[i].y+R] ++;
        mp[make_pair(a[i].x,a[i].y)] ++;
        nodeList[a[i].y].push_back(a[i].x);
    }
    int ans = 0;
    for(int p = 1;p <= n;p ++) {
        for(int i = -1;i <= 1;i ++) {
            for(int j = -1;j <= 1;j ++) {
                int k1 = a[p].x + i * R;
                int k2 = a[p].y + j * R;
                ans = max(ans,ask(k1,k2));
            }
        }
    }
    build(1,1,N);
    for(int i = 1;i <= N;i ++) {
        change(1,i,r[i]);
    }
    for(int i = R;i + R <= N;i ++) {
        add_node(i-R); add_node(i); add_node(i+R);
        ans = max(ans,tree[1].mx + c[i]);
        del(i-R); del(i); del(i+R);
    }
    cout << ans << endl;
}
