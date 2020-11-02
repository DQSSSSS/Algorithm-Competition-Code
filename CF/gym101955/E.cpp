#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;
typedef pair<LL,LL> pll;
const int SZ = 1e5 + 10;
const LL INF = 1e18;
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

const int dx[4] = {1,-1,1,-1};
const int dy[4] = {-1,1,1,-1};

struct segmenttree {
    struct segment {
        int l,r;
        pil mx[2];
        pil mn[2];
        segment() {
            mx[0] = mx[1] = make_pair(0,-INF);
            mn[0] = mn[1] = make_pair(0,INF);
        }
        void print() {
            printf("----\n");
            for(int i = 0;i < 2;i ++) printf("(%d,%lld) ",mx[i].first,mx[i].second); puts("");
            for(int i = 0;i < 2;i ++) printf("(%d,%lld) ",mn[i].first,mn[i].second); puts("");
        }
    }tree[SZ * 4];

    segment update(const segment &b,const segment &c) {
        segment ans = b;
        ans.l = b.l; ans.r = c.r;
        for(int i = 0;i < 2;i ++) {
            if(c.mx[i].first == ans.mx[0].first) {
                ans.mx[0].second = max(ans.mx[0].second,c.mx[i].second);
            }
            else if(c.mx[i].first == ans.mx[1].first) {
                ans.mx[1].second = max(ans.mx[1].second,c.mx[i].second);
            }
            else {
                if(ans.mx[0].second < c.mx[i].second) ans.mx[1] = ans.mx[0],ans.mx[0] = c.mx[i];
                else if(ans.mx[1].second < c.mx[i].second) ans.mx[1] = c.mx[i];
            }
            if(ans.mx[0].second < ans.mx[1].second) swap(ans.mx[0],ans.mx[1]);
        }

        for(int i = 0;i < 2;i ++) {
            if(c.mn[i].first == ans.mn[0].first) {
                ans.mn[0].second = min(ans.mn[0].second,c.mn[i].second);
            }
            else if(c.mn[i].first == ans.mn[1].first) {
                ans.mn[1].second = min(ans.mn[1].second,c.mn[i].second);
            }
            else {
                if(ans.mn[0].second > c.mn[i].second) ans.mn[1] = ans.mn[0],ans.mn[0] = c.mn[i];
                else if(ans.mn[1].second > c.mn[i].second) ans.mn[1] = c.mn[i];
            }
            if(ans.mn[0].second > ans.mn[1].second) swap(ans.mn[0],ans.mn[1]);
        }
        return ans;
    }

    void build(int p,int l,int r) {
        tree[p].l = l;
        tree[p].r = r;
        for(int i = 0;i < 2;i ++) {
            tree[p].mx[i] = make_pair(0,-INF);
            tree[p].mn[i] = make_pair(0,INF);
        }
        if(l == r) {
            return ;
        }
        int mid = l + r >> 1;
        build(p<<1,l,mid); build(p<<1|1,mid+1,r);
    }

    void change(int p,int x,LL v,int c) {
        if(tree[p].l == tree[p].r) {
            tree[p].mx[0] = make_pair(c,v);
            tree[p].mn[0] = make_pair(c,v);
            return ;
        }
        int mid = tree[p].l + tree[p].r >> 1;
        if(x <= mid) change(p<<1,x,v,c);
        else change(p<<1|1,x,v,c);
        tree[p] = update(tree[p<<1],tree[p<<1|1]);
    }

    segment ask(int p,int l,int r) {
        if(l <= tree[p].l && tree[p].r <= r) {
            return tree[p];
        }
        int mid = tree[p].l + tree[p].r >> 1;
        segment ans;
        if(l <= mid) ans = update(ans,ask(p<<1,l,r));
        if(mid < r) ans = update(ans,ask(p<<1|1,l,r));
        return ans;
    }

    LL ask(int l,int r) {
        segment s = ask(1,l,r);
       // s.print();
        LL ans = 0;
        for(int i = 0;i < 2;i ++) {
            for(int j = 0;j < 2;j ++) {
                if(s.mn[i].first == 0) continue;
                if(s.mx[j].first == 0) continue;
                if(s.mn[i].first != s.mx[j].first) {
                    ans = max(ans,s.mx[j].second - s.mn[i].second);
                }
            }
        }
        return ans;
    }
}tr[4];

LL X[SZ],Y[SZ];
int Z[SZ];

void change(int i,LL x,LL y,int z) {
    for(int k = 0;k < 4;k ++) {
        LL v = dx[k] * x + dy[k] * y;
        tr[k].change(1,i,v,z);
    }
}

LL ask(int l,int r) {
    LL ans = 0;
    for(int k = 0;k < 4;k ++) {
        ans = max(ans,tr[k].ask(l,r));
    }
    return ans;
}

int main(){
    int T = read(),cc = 0;
    while(T --) {
        LL n = read(),m = read();
        for(int i = 0;i < 4;i ++) tr[i].build(1,1,n);
        for(int i = 1;i <= n;i ++) {
            LL x = read(),y = read(),z = read();
            change(i,x,y,z);
            X[i] = x; Y[i] = y; Z[i] = z;
        }
        printf("Case #%d:\n",++ cc);
        for(int i = 1;i <= m;i ++) {
            int opt = read();
            if(opt == 1) {
                int k = read();
                LL x = read(),y = read();
                X[k] += x; Y[k] += y;
                change(k,X[k],Y[k],Z[k]);
            }
            else if(opt == 2) {
                int k = read(),c = read();
                Z[k] = c;
                change(k,X[k],Y[k],Z[k]);
            }
            else {
                int l = read(),r = read();
                printf("%lld\n",ask(l,r));
            }
        }
    }
}

/**
233
1000000000000000000 1000000000000000000 1
*/

