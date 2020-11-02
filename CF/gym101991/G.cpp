#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int st[SZ][22],lg[SZ];

void get_st(int a[],int n) {
    for(int i = 1;i <= n;i ++) st[i][0] = a[i];
    for(int j = 1;j <= lg[n];j ++)
        for(int i = 1;i <= n;i ++)
            if(i + (1<<j) - 1 <= n)
                st[i][j] = __gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int get_gcd(int l,int r) {
    int k = lg[r-l+1];
    return __gcd(st[l][k],st[r-(1<<k)+1][k]);
}

struct seg {
    int l,r;
    LL add,sum;
}tree[SZ * 4];

void update(int p) {
    tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    tree[p].sum = 0;
    if(l == r) {
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushadd(int p,LL d) {
    tree[p].sum += (tree[p].r - tree[p].l + 1) * d;
    tree[p].add += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,LL d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushadd(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1|1,l,r,d);
    update(p);
}

LL Ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans += Ask(p << 1,l,r);
    if(mid < r) ans += Ask(p << 1|1,l,r);
    return ans;
}

struct hehe {
    int L,r1,r2;
};

vector<hehe> itv[SZ * 22];

struct haha {
    int l,r,d,id;
}ask[SZ];

bool cmp(haha a,haha b) {
    if(a.d == b.d) return a.l < b.l;
    return a.d < b.d;
}

map<int,int> mp;

LL ans[SZ];
int a[SZ];

int main() {
    freopen("gcdrng.in","r",stdin);

    for(int i = 1;i <= 1e5;i ++) lg[i] = log2(i);

    int T = read(),tot = 0;
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        get_st(a,n);

        for(int i = 1;i <= tot;i ++) itv[i].clear();
        mp.clear();
        tot = 0;

        for(int i = 1;i <= n;i ++) {
            int x = i;
            while(x <= n) {
                int l = x,r = n + 1,now = get_gcd(i,x);
                while(r - l > 1) {
                    int mid = l + r >> 1;
                    if(get_gcd(i,mid) != now) r = mid;
                    else l = mid;
                }
                if(!mp[now]) mp[now] = ++ tot;
           //     cout << i << " " << now << " : " << x << " " << l << endl;
                itv[mp[now]].push_back((hehe){i,x,l});
                x = l + 1;
            }
        }

        for(int i = 1;i <= m;i ++) {
            ask[i].l = read(),ask[i].r = read();
            ask[i].d = read(),ask[i].id = i;
        }
        sort(ask + 1,ask + 1 + m,cmp);

        build(1,1,n);
        for(int i = 1,lst = 1;i <= m;i ++) {
            if(i == m || ask[i].d != ask[i+1].d) {
                int id = mp[ask[i].d];
                for(hehe x : itv[id]) {
                    change(1,x.r1,x.r2,1);
                }
                int l = 0;
                for(int j = lst;j <= i;j ++) {
                    while(l < itv[id].size() && itv[id][l].L < ask[j].l)
                        change(1,itv[id][l].r1,itv[id][l].r2,-1),l ++;
                    ans[ask[j].id] = Ask(1,ask[j].l,ask[j].r);
                }
                while(l < itv[id].size())
                    change(1,itv[id][l].r1,itv[id][l].r2,-1),l ++;

                lst = i + 1;
            }
        }

        for(int i = 1;i <= m;i ++) printf("%lld\n",ans[i]);
    }
}



