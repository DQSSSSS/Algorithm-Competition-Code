#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

struct Point {
    int x,y;
    Point() {}
    Point(int _x,int _y):x(_x),y(_y) {}
    Point operator -(Point o) { return Point(x-o.x,y-o.y); }
    LL operator ^(Point o) { return 1ll*x*o.y-1ll*y*o.x; }
};

struct Line {
    Point a,b;
    Line() {}
    Line(Point _a,Point _b): a(_a),b(_b) {}
};

int cmpk(Line A,Line B) {
    LL d = (A.b-A.a)^(B.b-B.a);
    if(d == 0) return 0;
    return d<0 ? 1 : -1;
}

int cmpval(Line A,Line B,LL x) {
    LL Adx = A.b.x - A.a.x;
    LL Bdx = B.b.x - B.a.x;
    LL l,r;
    if(Adx == 0 && Bdx == 0) {
        l = max(A.a.y,A.b.y);
        r = max(B.a.y,B.b.y);
    }
    else if(Adx == 0) {
        l = Bdx * max(A.a.y,A.b.y);
        r = ((x-B.b.x)*(B.b.y-B.a.y) + B.b.y * Bdx);
    }
    else if(Bdx == 0) {
        l = ((x-A.b.x)*(A.b.y-A.a.y) + A.b.y * Adx);
        r = Adx * max(B.a.y,B.b.y);
    }
    else {
        l = Bdx * ((x-A.b.x)*(A.b.y-A.a.y) + A.b.y * Adx);
        r = Adx * ((x-B.b.x)*(B.b.y-B.a.y) + B.b.y * Bdx);
    }
    if(l == r) return 0;
    return l<r?-1:1;
}

vector<Line> L;

struct seg {
    int l,r;
    int id;
}tree[SZ * 4];

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].id = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void add_line(int p,int id) {
    if(tree[p].l == tree[p].r) {
        if(tree[p].id == 0 ||
           cmpval(L[tree[p].id],L[id],tree[p].l) < 0 ||
           (cmpval(L[tree[p].id],L[id],tree[p].l) == 0 && tree[p].id > id) )
            tree[p].id = id;
        return ;
    }
    int mid = tree[p].l + tree[p].r >>1;
    if(tree[p].id == 0) tree[p].id = id;
    else {
        Line a = L[tree[p].id];
        Line b = L[id];
        if(cmpk(a,b) > 0) {
            if(cmpval(a,b,mid) < 0) add_line(p<<1|1,tree[p].id),tree[p].id = id;
            else add_line(p<<1,id);
        }
        else {
            if(cmpval(a,b,mid) < 0) add_line(p<<1,tree[p].id),tree[p].id = id;
            else add_line(p<<1|1,id);
        }
    }
}

void change(int p,int l,int r,int id) {
    if(l <= tree[p].l && tree[p].r <= r) {
        add_line(p,id);
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,id);
    if(mid < r) change(p<<1|1,l,r,id);
}

void update(int &ans,int t,int pos) {
    if(t == 0) return ;
    if(ans == 0) ans = t;
    if(cmpval(L[ans],L[t],pos) < 0 ||
       (cmpval(L[ans],L[t],pos) == 0 && ans > t)) ans = t;
}

int ask(int p,int x) {
    if(tree[p].l == tree[p].r) return tree[p].id;
    int mid = tree[p].l + tree[p].r >> 1,ans = tree[p].id;
    if(x <= mid) update(ans,ask(p<<1,x),x);
    else update(ans,ask(p<<1|1,x),x);
    return ans;
}

const int N = 40000;

int main() {
  //  freopen("4097.in","r",stdin);
  //  freopen("my.out","w",stdout);
    int m = read();
    L.resize(1);
    build(1,1,N);
    int lstans = 0;
    while(m --) {
        int opt = read();
        if(opt == 0) {
            int x = read();
            x = (x+lstans-1)%39989+1;
            printf("%d\n",lstans = ask(1,x));
        }
        else {
            int x0 = read(),y0 = read();
            int x1 = read(),y1 = read();
            x0 = (x0+lstans-1)%39989+1;
            y0 = (y0+lstans-1)%(1000000000)+1;
            x1 = (x1+lstans-1)%39989+1;
            y1 = (y1+lstans-1)%(1000000000)+1;
            if(x0>x1) swap(x0,x1),swap(y0,y1);
         //   printf("%d %d %d %d\n",x0,y0,x1,y1);
            L.push_back(Line(Point(x0,y0),Point(x1,y1)));
            change(1,x0,x1,L.size()-1);
        /*    double k = (1.0*y1-y0)/(x1-x0);
            double b = y1-x1*k;
            printf("%.3f\n",5*k+b);*/
        }
    }
}

/**
20
1 1 4 5 4
1 1 5 5 4
0 5
*/
