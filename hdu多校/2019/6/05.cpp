#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const LL INF = 1e18 + 10;
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

struct seg {
    int l,r;
    LL a,b,c,d;
}tree[2010 * 4];

void update(int p) {
    seg &o = tree[p];
    seg &o1 = tree[p << 1];
    seg &o2 = tree[p << 1 | 1];

    o.a = max(o2.a,o1.a+o2.c);
    o.b = max(max(o2.b,o1.b),o1.a+o2.d);
    o.c = o2.c + o1.c;
    o.d = max(o1.d,o1.c+o2.d);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].a = 0;
        tree[p].b = 0;
        tree[p].c = 0;
        tree[p].d = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void change(int p,int x,LL d) {
    if(tree[p].l == tree[p].r) {
        tree[p].c += d; tree[p].d += d;
        return ;
    }
    int mid = tree[p].l + tree[p].r >>1;
    if(x <= mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(p);
}

LL get_max(seg a) {
    LL ans = max(max(a.a,a.b),max(a.c,a.d));
    return ans;
}

vector<pll> V[2010];

int X[SZ],Y[SZ],W[SZ];
int lshx[SZ],lshy[SZ];

int main() {
    int T = read();
    while(T --) {
        int K = read();
        lshx[0] = lshy[0] = 0;
        for(int i = 1;i <= K;i ++) {
            int x = read(),y = read(),w = read();
            lshx[++ lshx[0]] = x;
            lshy[++ lshy[0]] = y;
            X[i] = x; Y[i] = y; W[i] = w;
        }
        sort(lshx+1,lshx+1+lshx[0]); lshx[0] = unique(lshx+1,lshx+1+lshx[0])-lshx-1;
        sort(lshy+1,lshy+1+lshy[0]); lshy[0] = unique(lshy+1,lshy+1+lshy[0])-lshy-1;
        int n = lshx[0],m = lshy[0];
        for(int i = 1;i <= n;i ++) V[i].clear();
        for(int i = 1;i <= K;i ++) {
            int x = lower_bound(lshx+1,lshx+1+lshx[0],X[i])-lshx;
            int y = lower_bound(lshy+1,lshy+1+lshy[0],Y[i])-lshy;
            V[x].push_back(make_pair(y,W[i]));
        }
        /*
            for(int i = 1;i <= n;i ++,puts(""))
            for(int j = 1;j <= m;j ++) {
                printf("%lld ",a[i][j]);
            }
*/


        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
            build(1,1,m);
            for(int j = i;j <= n;j ++) {
                for(pll p : V[j]) {
            //        cout << p.first << " " << p.second << endl;
                    change(1,p.first,p.second);
                }
                ans = max(ans,get_max(tree[1]));
            }
        }

        printf("%lld\n",ans);
    }
}

/**

*/
