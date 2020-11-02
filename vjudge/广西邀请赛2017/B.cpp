#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 3e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

struct haha {
    int type,x,y,d;
}a[SZ];

int lsh[SZ];

struct seg {
    int l,r;
    vector<LL> g;
    vector<int> lsh;

    void change(int x,int w) {
        int id = lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin();
        id ++;
        for(int i = id;i < g.size();i += i & -i) g[i] |= 1ll<<w;
    }

    LL ask(int x) {
        if(lsh.size() == 0) return 0;
        if(lsh[0] > x) return 0;
        int id = upper_bound(lsh.begin(),lsh.end(),x)-lsh.begin()-1;
        id ++;
        LL ans = 0;
        for(int i = id;i > 0;i -= i & -i) ans |= g[i];
        return ans;
    }

}tree[SZ * 4];

void build(int p,int l,int r) {
   // printf("%d [%d,%d]\n",p,l,r);
    tree[p].l = l;
    tree[p].r = r;
    tree[p].g.clear();
    tree[p].lsh.clear();
    if(l >= r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void setpos(int p,int x,int id) {
    tree[p].lsh.push_back(id);
    if(tree[p].l == tree[p].r) return ;
    int mid = tree[p].l + tree[p].r >> 1;
    if(x<=mid) setpos(p<<1,x,id);
    else setpos(p<<1|1,x,id);
}

void rebuild(int p,int l,int r) {
    sort(tree[p].lsh.begin(),tree[p].lsh.end());
    int m = unique(tree[p].lsh.begin(),tree[p].lsh.end()) - tree[p].lsh.begin();
    tree[p].lsh.resize(m);
    tree[p].g.resize(m+1);
    if(l >= r) return ;
    int mid = l + r >> 1;
    rebuild(p<<1,l,mid);
    rebuild(p<<1|1,mid+1,r);
}

void change(int p,int x,int id,int w) {
   // printf("%d %d %d\n",p,id,w);
    tree[p].change(id,w);
    if(tree[p].l == tree[p].r) return ;
    int mid = tree[p].l + tree[p].r >> 1;
    if(x<=mid) change(p<<1,x,id,w);
    else change(p<<1|1,x,id,w);
}

LL ask(int p,int l,int r,int id) {
    if(l <= tree[p].l && tree[p].r <= r) {
       // printf("%d %d %lld\n",p,id,tree[p].ask(id));
        return tree[p].ask(id);
    }
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans |= ask(p<<1,l,r,id);
    if(mid < r) ans |= ask(p<<1|1,l,r,id);
    return ans;
}

int main() {
    int n = 0;
    while(1) {
        int opt = read();
        if(opt == 0 || opt == 3) {

            lsh[0] = 0;
            for(int i = 1;i <= n;i ++) {
                if(a[i].type == 1)
                    lsh[++ lsh[0]] = a[i].y;
                else {
                    lsh[++ lsh[0]] = a[i].x;
                    lsh[++ lsh[0]] = a[i].y+1;
                }
            }
            sort(lsh+1,lsh+1+lsh[0]); lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;
            for(int i = 1;i <= n;i ++) {
                if(a[i].type == 1)
                    a[i].y = lower_bound(lsh+1,lsh+1+lsh[0],a[i].y)-lsh;
                else {
                    a[i].x = lower_bound(lsh+1,lsh+1+lsh[0],a[i].x)-lsh;
                    a[i].y = lower_bound(lsh+1,lsh+1+lsh[0],a[i].y+1)-lsh-1;
                }
            }
            if(lsh[0] == 0) continue;

            build(1,1,lsh[0]);

            for(int i = 1;i <= n;i ++) {
                if(a[i].type == 1) {
                    setpos(1,a[i].y,a[i].x);
                }
            }

            rebuild(1,1,lsh[0]);

            for(int i = 1;i <= n;i ++) {
                if(a[i].type == 1) {
                    change(1,a[i].y,a[i].x,a[i].d);
                }
                else {
                    LL ans = ask(1,a[i].x,a[i].y,a[i].d);
                    int t = 0;
                    for(int j = 0;j <= 50;j ++) if(ans>>j&1) t++;
                    printf("%d\n",t);
                }
            }
            n = 0;
            if(opt == 3) break;
        }
        else if(opt == 1) {
            int x = read(),y = read(),c = read();
            a[++ n] = (haha){1,x,y,c};
        }
        else if(opt == 2) {
            int x = read(),y1 = read(),y2 = read();
            a[++ n] = (haha){2,y1,y2,x};
        }
    }
}
