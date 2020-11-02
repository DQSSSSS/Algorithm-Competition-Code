#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int lsh[SZ],tree[SZ];

void add(int x,int d) {
    for(int i = x;i <= lsh[0];i += i & -i) tree[i] += d;
}

int ask(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

LL ans[SZ];

struct haha {
    int type,x,y,id,d;
}a[SZ],b[SZ];

void cdq(int l,int r) {
    if(l == r) return ;
    int mid = l + r >> 1;
    cdq(l,mid); cdq(mid+1,r);

    int j = l;
    for(int i = mid + 1;i <= r;i ++) {
        while(j <= mid && a[j].x <= a[i].x) {
            if(a[j].type == 1) add(a[j].y,a[j].d);
            j ++;
        }
        if(a[i].type == 2) ans[a[i].id] += a[i].d * ask(a[i].y);
    }
    for(int i = l;i < j;i ++) if(a[i].type == 1) add(a[i].y,-a[i].d);
   // for(int i = 1;i <= lsh[0];i ++) assert(tree[i] == 0);

    j = mid;
    for(int i = r,s = 0;i >= mid+1;i --) {
        while(j >= l && a[j].x >= a[i].x) {
            if(a[j].type == 2) add(a[j].y,a[j].d),s += a[j].d;
            j --;
        }
        if(a[i].type == 1) ans[a[i].id] += a[i].d * (s - ask(a[i].y - 1));
    }
    for(int i = mid;i > j;i --) if(a[i].type == 2) add(a[i].y,-a[i].d);

   // for(int i = 1;i <= lsh[0];i ++) assert(tree[i] == 0);

    int p = l,pl = l,pr = mid + 1;
    while(pl <= mid || pr <= r) {
        if(pl > mid || (pr <= r && a[pl].x >= a[pr].x)) b[p ++] = a[pr ++];
        else b[p ++] = a[pl ++];
    }
    for(int i = l;i <= r;i ++) a[i] = b[i];
}

int main() {
    int n = read(),tot = 0;
    for(int i = 1;i <= n;i ++) {
        int o = read();
        if(o == 1) {
            a[++ tot].type = 1;
            a[tot].x = read();
            a[tot].y = read();
            a[tot].id = i;
            a[tot].d = 1;
        }
        else {
            int x1 = read(),y1 = read(),x2 = read(),y2 = read();
            a[++ tot].type = 2; a[tot].x = x2; a[tot].y = y2; a[tot].id = i; a[tot].d = 1;
            a[++ tot].type = 2; a[tot].x = x1-1; a[tot].y = y2; a[tot].id = i; a[tot].d = -1;
            a[++ tot].type = 2; a[tot].x = x2; a[tot].y = y1-1; a[tot].id = i; a[tot].d = -1;
            a[++ tot].type = 2; a[tot].x = x1-1; a[tot].y = y1-1; a[tot].id = i; a[tot].d = 1;
        }
    }

    //for(int i = 1;i <= tot;i ++) printf("%d %d %d %d\n",a[i].type,a[i].x,a[i].y,a[i].d); puts("");

    for(int i = 1;i <= tot;i ++) {
        lsh[++ lsh[0]] = a[i].x;
        lsh[++ lsh[0]] = a[i].y;
    }

    sort(lsh + 1,lsh + 1 + lsh[0]);
    lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
    for(int i = 1;i <= tot;i ++) {
        a[i].x = lower_bound(lsh+1,lsh+1+lsh[0],a[i].x)-lsh;
        a[i].y = lower_bound(lsh+1,lsh+1+lsh[0],a[i].y)-lsh;
    }
    cdq(1,tot);
    for(int i = 1;i <= n;i ++)
        printf("%lld\n",ans[i] += ans[i-1]);
    return 0;
}
