#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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
    void Read() {
        x = read(); y = read();
    }
};

struct Circle {
    Point o;
    int r;
}C[SZ];

struct ASK {
    Point P,Q;
    int ymin,ymax;
}ask[SZ];

vector<int> A[SZ],B[SZ];

/*
int stMax[22][SZ];
int stMin[22][SZ];

void get_max_st(int A[],int n) {
    for(int i = 1;i <= n;i ++) stMax[0][i] = A[i];
    for(int j = 1;j <= log2(n);j ++) {
        for(int i = 1;i+(1<<(j-1)) <= n;i ++) {
            stMax[j][i] = max(stMax[j-1][i],stMax[j-1][i+(1<<(j-1))]);
        }
    }
}

int ask_max(int l,int r) {
    int k = log2(r-l+1);
    return max(stMax[k][l],stMax[k][r-(1<<k)+1]);
}

void get_min_st(int A[],int n) {
    for(int i = 1;i <= n;i ++) stMin[0][i] = A[i];
    for(int j = 1;j <= log2(n);j ++) {
        for(int i = 1;i+(1<<(j-1)) <= n;i ++) {
            stMin[j][i] = min(stMin[j-1][i],stMin[j-1][i+(1<<(j-1))]);
        }
    }
}

int ask_min(int l,int r) {
    int k = log2(r-l+1);
    return min(stMin[k][l],stMin[k][r-(1<<k)+1]);
}
*/

struct Node {
    int l,r;
    vector<pii> a;
}tree[SZ * 4];

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        for(int i = 0;i < A[l].size();i ++)
            tree[p].a.push_back({B[l][i],A[l][i]});
        sort(tree[p].a.begin(),tree[p].a.end());
        vector<pii> tmp;
        for(int i = 0,j = 0;i < tree[p].a.size();i ++) {
            if(i+1 == tree[p].a.size() || tree[p].a[i+1].first != tree[p].a[i].first) {
                int x = tree[p].a[j].second;
                while(j <= i) {
                    x = max(x,tree[p].a[j].second);
                    j ++;
                }
                tmp.push_back({tree[p].a[i].first,x});
            }
        }
        tree[p].a = tmp;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);

    int pl = 0,pr = 0;
    while(pl < tree[p<<1].a.size() || pr < tree[p<<1|1].a.size()) {
        if(pl < tree[p<<1].a.size() && pr < tree[p<<1|1].a.size() && tree[p<<1|1].a[pr].first == tree[p<<1].a[pl].first) {
            tree[p].a.push_back({tree[p<<1].a[pl].first,max(tree[p<<1].a[pl].second,tree[p<<1|1].a[pr].second)});
            pl ++; pr ++;
        }
        else if(pl >= tree[p<<1].a.size() ||
           (pr < tree[p<<1|1].a.size() && tree[p<<1|1].a[pr] < tree[p<<1].a[pl]))
            tree[p].a.push_back(tree[p<<1|1].a[pr]),pr ++;
        else
            tree[p].a.push_back(tree[p<<1].a[pl]),pl ++;
    }
    for(int i = 1;i < tree[p].a.size();i ++) {
        tree[p].a[i].second = max(tree[p].a[i].second,tree[p].a[i-1].second);
    }
}

bool Ask(int p,int l,int r,int ymin,int ymax) {
    if(l <= tree[p].l && tree[p].r <= r) {
        auto it = upper_bound(tree[p].a.begin(),tree[p].a.end(),make_pair(ymin,2*INF));
        if(it == tree[p].a.begin()) return false;
        it --;
        if(it -> second >= ymax) return true;
        return false;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if(l <= mid) if(Ask(p<<1,l,r,ymin,ymax)) return true;
    if(mid < r) if(Ask(p<<1|1,l,r,ymin,ymax)) return true;
    return false;
}

int lsh[3000010];

int main() {
    int n = read(),q = read();
    for(int i = 1;i <= n;i ++){
        C[i].o.Read(); C[i].r = read();
        lsh[++ lsh[0]] = C[i].o.x;
    }
    for(int i = 1;i <= q;i ++) {
        ask[i].P.Read();
        ask[i].Q.Read();
        ask[i].ymin = read();
        ask[i].ymax = read();
    }
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0]) - lsh - 1;
    for(int i = 1;i <= n;i ++){
        C[i].o.x = lower_bound(lsh+1,lsh+1+lsh[0],C[i].o.x) - lsh;
        A[C[i].o.x].push_back(C[i].r + C[i].o.y);
        B[C[i].o.x].push_back(-C[i].r + C[i].o.y);
    }
   // for(int i = 1;i <= lsh[0];i ++) cout << A[i] << " "; puts("");
   // for(int i = 1;i <= lsh[0];i ++) cout << B[i] << " "; puts("");

//    get_max_st(A,lsh[0]);
 //   get_min_st(B,lsh[0]);

    build(1,1,lsh[0]);

    for(int i = 1;i <= q;i ++){
        int l = ask[i].P.x;// = lower_bound(lsh+1,lsh+1+lsh[0],ask[i].P.x) - lsh;
        int r = ask[i].Q.x;// = lower_bound(lsh+1,lsh+1+lsh[0],ask[i].Q.x) - lsh;
        if(l>r) swap(l,r);
        l = lower_bound(lsh+1,lsh+1+lsh[0],l) - lsh;
        r = upper_bound(lsh+1,lsh+1+lsh[0],r) - lsh - 1;

        if(Ask(1,l,r,ask[i].ymin,ask[i].ymax)) {
            puts("NO");
        }
        else {
            puts("YES");
        }
    }

}
/*
3 3
3 3 2
7 7 3
12 5 2
1 4 14 4 2 6
1 4 14 4 4 7
1 4 14 4 3 9
*/

