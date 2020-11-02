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

const int MAXN = 5000000+3;

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

void cdq1(int l,int r) {
    if(l >= r) return ;
    int mid = l + r >> 1;
    cdq1(l,mid); cdq1(mid+1,r);
    int pl = l,pr = mid + 1,p = l;
    LL A = 0,B = 0,AB = 0,O = 0;
    while(pl <= mid || pr <= r) {
        if(pr > r || (pl <= mid && b[pl].y <= b[pr].y)) {
            if(b[pl].type == 0) {
                int i = pl;
                A += b[i].x * b[i].b;
                B += b[i].y * b[i].b;
                AB += 1ll * b[i].x * b[i].y * b[i].b;
                O += b[i].b;
            }
            c[p ++] = b[pl ++];
        }
        else {
            if(b[pr].type == 1) {
                int i = pr;
                int id = b[i].id;
                a[id].ans2 += b[i].b * (O * (b[i].x+1) * (b[i].y+1)
                    - B * (b[i].x+1) - A * (b[i].y+1) + AB);
            }
            c[p ++] = b[pr ++];
        }
    }
    for(int i = l;i <= r;i ++) b[i] = c[i];
}

void cdq2(int l,int r) {
    if(l >= r) return ;
    int mid = l + r >> 1;
    cdq2(l,mid); cdq2(mid+1,r);
    int pl = l,pr = mid + 1,p = l;
    LL OO[5] = {0};
    while(pl <= mid || pr <= r) {
        if(pr > r || (pl <= mid && b[pl].y <= b[pr].y)) {
            int i = pl;
            if(b[i].type % 2 == 0) OO[b[i].type>>1] ++;
            c[p ++] = b[pl ++];
        }
        else {
            int i = pr;
            if(b[i].type % 2 == 1) {
                int id = b[i].id;
                int x = b[i].type>>1;
                a[id].ans1 -= OO[x];
            }
            c[p ++] = b[pr ++];
        }
    }
    for(int i = l;i <= r;i ++) b[i] = c[i];
}

LL A[5000010];

void add(LL tree[],int x,LL d) {
    for(int i = x;i <= 5000001;i += i & -i) tree[i] += d;
}

LL ask(LL tree[],int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

int main() {
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
        sort(b+1,b+1+tot,cmp);
        cdq2(1,tot);

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
                   - (a[i].x2-a[i].x1+1ll)*(a[i].y2-a[i].y1+1));
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
