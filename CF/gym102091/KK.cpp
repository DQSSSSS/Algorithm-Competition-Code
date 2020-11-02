#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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

struct node {
    node *ch[2],*f;
    int sz,cnt,v;

    void maintain() { sz = cnt + ch[0] -> sz + ch[1] -> sz; }
    int cmp(int x) { if(x == v) return -1; return x < v ? 0 : 1;}
    int dir() { return f -> ch[1] == this; }
    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
}T[SZ], *root, *null;

int Tcnt = 0;

node* newnode(int x,node *f) {
    node *k = T + (++ Tcnt);
    k -> v = x;
    k -> ch[0] = k -> ch[1] = null;
    k -> sz = k -> cnt = 1;
    k -> f = f;
    return k;
}

void rotate(node *p) {
    node *fa = p -> f;
    int d = p -> dir();
    fa -> f -> setc(p,fa -> dir());
    fa -> setc(p -> ch[d ^ 1],d); fa -> maintain();
    p -> setc(fa,d ^ 1); p -> maintain();
    if(fa == root) root = p;
}

void splay(node *p,node *rt = null) {
    while(p -> f != rt) {
        if(p -> f -> f == rt) rotate(p);
        else {
            if(p -> dir() == p -> f -> dir())
                rotate(p -> f),rotate(p);
            else
                rotate(p),rotate(p);
        }
    }
}


void insert(node *p,int x) {
    if(root == null) { root = newnode(x,null); return ; }
    while(p != null) {
        p -> sz ++;
        int d = p -> cmp(x);
        if(d == -1) { p -> cnt ++; break; }
        if(p -> ch[d] == null) {
            p -> ch[d] = newnode(x,p);
            p = p -> ch[d];
            break;
        }
        p = p -> ch[d];
    }
    splay(p);
}

void erase(node *p,int x) {
    while(p != null) {
        p -> sz --;
        int d = p -> cmp(x);
        if(d == -1) { p -> cnt --; break; }
        p = p -> ch[d];
    }
    if(p -> cnt) return ;
    splay(p);
    if(p -> ch[0] == null) { root = p -> ch[1]; root -> f = null; return ; }
    if(p -> ch[1] == null) { root = p -> ch[0]; root -> f = null; return ; }
    p = p -> ch[0];
    while(p -> ch[1] != null) p = p -> ch[1];
    splay(p,root);
    p -> ch[1] = root -> ch[1]; p -> ch[1] -> f = p;
    p -> f = null; p -> maintain();
    root = p;
}

int ask_num(node *p,int k) {
    while(p != null) {
        int l = p -> ch[0] -> sz + 1;
        int r = p -> ch[0] -> sz + p -> cnt;
        if(l <= k && k <= r) return p -> v;
        if(k > r) k -= r,p = p -> ch[1];
        else p = p -> ch[0];
    }
    return -1;
}

void init() {
    null = newnode(-INF,null);
    null -> sz = null -> cnt = 0;
    root = null;
}

priority_queue<pii> q;

struct haha {
    int op,now,val,r;
}a[SZ];

int main() {
    //freopen("K.in","r",stdin);
   //freopen("K.out","w",stdout);
    int T = read(),cc = 0;
    while(T --) {
        int n = read();

        while(q.size()) q.pop();
        Tcnt = 0;
        init();

        printf("Case %d:\n",++ cc);
        for(int i = 1;i <= n;i ++) {
            a[i].op = read();
            if(a[i].op == 1) {
                a[i].now = read();
                a[i].val = read();
                a[i].r = read();
                insert(root,a[i].val);
                q.push(make_pair(-a[i].r,a[i].val));
            }
            else {
                a[i].now = read();
                a[i].val = read();
                while(q.size() && -q.top().first < a[i].now) {
                    erase(root,q.top().second); q.pop();
                }
                int ans = ask_num(root,a[i].val);
                printf("%d\n",ans);
            }
        }
    }
}
/**

*/

