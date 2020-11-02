#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 32e5 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const int MAXN = 32e5 + 3;

struct haha {
    int x1,x2,y1,y2;
    LL ans1,ans2;
}a[200010];

struct hh {
    int type,x,y,b,id;
}b[1600010],c[1600010];

bool cmp(hh a,hh b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.type < b.type;
}

LL A[1600010],B[1600010],AB[1600010];
int O[1600010],OO[4][1600010];
int lsh[1600010];

void add(LL tree[],int x,LL d) {
    for(int i = x;i <= lsh[0];i += i & -i) tree[i] += d;
}

LL ask(LL tree[],int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

void add(int tree[],int x,LL d) {
    for(int i = x;i <= lsh[0];i += i & -i) tree[i] += d;
}

LL ask(int tree[],int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

void cdq1(int l,int r) {
    if(l >= r) return ;
    int mid = l + r >> 1;
    cdq1(l,mid); cdq1(mid+1,r);
    for(int i = l;i <= mid;i ++) {
        if(b[i].type == 0) {
            add(O,b[i].y,b[i].b);
            add(A,b[i].y,lsh[b[i].x] * b[i].b);
            add(B,b[i].y,lsh[b[i].y] * b[i].b);
            add(AB,b[i].y,1ll * lsh[b[i].x] * lsh[b[i].y] * b[i].b);
        }
    }
    for(int i = mid + 1;i <= r;i ++) {
        if(b[i].type == 1) {
            int id = b[i].id;
            a[id].ans2 += b[i].b * (ask(O,b[i].y) * (lsh[b[i].x]+1) * (lsh[b[i].y]+1)
                - ask(B,b[i].y) * (lsh[b[i].x]+1) - ask(A,b[i].y) * (lsh[b[i].y]+1)
                + ask(AB,b[i].y));
        }
    }
    for(int i = l;i <= mid;i ++) {
        if(b[i].type == 0) {
            add(O,b[i].y,-b[i].b);
            add(A,b[i].y,-lsh[b[i].x] * b[i].b);
            add(B,b[i].y,-lsh[b[i].y] * b[i].b);
            add(AB,b[i].y,-1ll * lsh[b[i].x] * lsh[b[i].y] * b[i].b);
        }
    }
    int pl = l,pr = mid + 1,p = l;
    while(pl <= mid || pr <= r) {
        if(pr > r || (pl <= mid && b[pl].y < b[pr].y))
            c[p ++] = b[pl ++];
        else
            c[p ++] = b[pr ++];
    }
    for(int i = l;i <= r;i ++) b[i] = c[i];
}

void cdq2(int l,int r) {
    if(l >= r) return ;
    int mid = l + r >> 1;
    cdq2(l,mid); cdq2(mid+1,r);
    for(int i = l;i <= mid;i ++) {
        if(b[i].type % 2 == 0)
            add(OO[b[i].type>>1],b[i].y,1);
    }
    for(int i = mid + 1;i <= r;i ++) {
        if(b[i].type & 1) {
            int id = b[i].id;
            int x = b[i].type>>1;
            a[id].ans1 -= ask(OO[x],b[i].y);
        }
    }
    for(int i = l;i <= mid;i ++) {
        if(b[i].type % 2 == 0)
            add(OO[b[i].type>>1],b[i].y,-1);
    }
    int pl = l,pr = mid + 1,p = l;
    while(pl <= mid || pr <= r) {
        if(pr > r || (pl <= mid && b[pl].y < b[pr].y))
            c[p ++] = b[pl ++];
        else
            c[p ++] = b[pr ++];
    }
    for(int i = l;i <= r;i ++) b[i] = c[i];
}

int main() {
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        int tot = 0;
        for(int i = 1;i <= n;i ++) {
            a[i].x1 = read()+1; a[i].y1 = read()+1;
            a[i].x2 = read(); a[i].y2 = read();
            a[i].ans1 = 0;
            a[i].ans2 = 0;
            b[++ tot] = (hh){0,a[i].x1,a[i].y1,1,0};
            b[++ tot] = (hh){0,a[i].x1,a[i].y2+1,-1,0};
            b[++ tot] = (hh){0,a[i].x2+1,a[i].y1,-1,0};
            b[++ tot] = (hh){0,a[i].x2+1,a[i].y2+1,1,0};

            b[++ tot] = (hh){1,a[i].x1-1,a[i].y1-1,1,i};
            b[++ tot] = (hh){1,a[i].x1-1,a[i].y2,-1,i};
            b[++ tot] = (hh){1,a[i].x2,a[i].y1-1,-1,i};
            b[++ tot] = (hh){1,a[i].x2,a[i].y2,1,i};
        }
        lsh[0] = 0;
        for(int i = 1;i <= tot;i ++) {
            lsh[++ lsh[0]] = b[i].x;
            lsh[++ lsh[0]] = b[i].y;
        }
        sort(lsh+1,lsh+1+lsh[0]);
        lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;
        for(int i = 1;i <= tot;i ++) {
            b[i].x = lower_bound(lsh+1,lsh+1+lsh[0],b[i].x)-lsh;
            b[i].y = lower_bound(lsh+1,lsh+1+lsh[0],b[i].y)-lsh;
        }
        sort(b+1,b+1+tot,cmp);
        cdq1(1,tot);


        tot = 0;
        for(int i = 1;i <= n;i ++) {
            b[++ tot] = (hh){0 ,a[i].x2,a[i].y2,1,0};
            b[++ tot] = (hh){1 ,a[i].x1-1,a[i].y1-1,1,i};

            b[++ tot] = (hh){2 ,MAXN-a[i].x1+1,MAXN-a[i].y1+1,1,0};
            b[++ tot] = (hh){3 ,MAXN-a[i].x2,MAXN-a[i].y2,1,i};

            b[++ tot] = (hh){4 ,a[i].x2,MAXN-a[i].y1+1,1,0};
            b[++ tot] = (hh){5 ,a[i].x1-1,MAXN-a[i].y2,1,i};

            b[++ tot] = (hh){6 ,MAXN-a[i].x1+1,a[i].y2,1,0};
            b[++ tot] = (hh){7 ,MAXN-a[i].x2,a[i].y1-1,1,i};
        }
        lsh[0] = 0;
        for(int i = 1;i <= tot;i ++) {
            lsh[++ lsh[0]] = b[i].x;
            lsh[++ lsh[0]] = b[i].y;
        }
        sort(lsh+1,lsh+1+lsh[0]);
        lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;
        for(int i = 1;i <= tot;i ++) {
            b[i].x = lower_bound(lsh+1,lsh+1+lsh[0],b[i].x)-lsh;
            b[i].y = lower_bound(lsh+1,lsh+1+lsh[0],b[i].y)-lsh;
        }
        sort(b+1,b+1+tot,cmp);
        cdq2(1,tot);


        for(int i = 1;i <= n;i ++) {
            a[i].x1 = lower_bound(lsh+1,lsh+1+lsh[0],a[i].x1)-lsh;
            a[i].x2 = lower_bound(lsh+1,lsh+1+lsh[0],a[i].x2)-lsh;
            a[i].y1 = lower_bound(lsh+1,lsh+1+lsh[0],a[i].y1)-lsh;
            a[i].y2 = lower_bound(lsh+1,lsh+1+lsh[0],a[i].y2)-lsh;
        }
        for(int i = 1;i <= n;i ++) add(A,a[i].x2,1);
        for(int i = 1;i <= n;i ++) a[i].ans1 += ask(A,a[i].x1-1);
        for(int i = 1;i <= n;i ++) add(A,a[i].x2,-1);

        for(int i = 1;i <= n;i ++) add(A,a[i].x1,1);
        for(int i = 1;i <= n;i ++) a[i].ans1 += n-ask(A,a[i].x2);
        for(int i = 1;i <= n;i ++) add(A,a[i].x1,-1);

        for(int i = 1;i <= n;i ++) add(A,a[i].y2,1);
        for(int i = 1;i <= n;i ++) a[i].ans1 += ask(A,a[i].y1-1);
        for(int i = 1;i <= n;i ++) add(A,a[i].y2,-1);

        for(int i = 1;i <= n;i ++) add(A,a[i].y1,1);
        for(int i = 1;i <= n;i ++) a[i].ans1 += n-ask(A,a[i].y2);
        for(int i = 1;i <= n;i ++) add(A,a[i].y1,-1);

        for(int i = 1;i <= n;i ++)
            printf("%lld %lld\n",n-a[i].ans1-1,a[i].ans2
                   - (lsh[a[i].x2]-lsh[a[i].x1]+1)*(lsh[a[i].y2]-lsh[a[i].y1]+1));
    }
}
/**
2
2
0 0 1 1
1 1 2 2
3
0 0 2 6
1 1 4 4
1 3 3 9

2
3
0 0 2 6
1 1 4 4
1 3 3 9
*/


