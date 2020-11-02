#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha {
    int l,r,id;
    LL ans;
}a[SZ];

int B;

bool cmp(haha a,haha b) {
    if(a.l/B == b.l/B) return a.r < b.r;
    return a.l < b.l;
}

bool cmp2(haha a,haha b) { return a.id < b.id; }

int tree[SZ];
int lsh[SZ],L[SZ],R[SZ],P[SZ],b[SZ];

void add(int x,int d) {
    for(int i = x;i <= lsh[0];i += i & -i) tree[i] += d;
}

LL ask(int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

LL ask(int l,int r) {
    return ask(r) - ask(l-1);
}

int main() {
    int n = read(),m = read(),k = read();
    for(int i = 1;i <= n;i ++) {
        b[i] = read();
        lsh[++ lsh[0]] = b[i];
        lsh[++ lsh[0]] = b[i]-k;
        lsh[++ lsh[0]] = b[i]+k;
    }
    B = sqrt(n) + 1;
    for(int i = 1;i <= m;i ++) {
        a[i].l = read();
        a[i].r = read();
        a[i].id = i;
    }
    sort(a+1,a+1+m,cmp);
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;

    for(int i = 1;i <= n;i ++) {
        L[i] = lower_bound(lsh+1,lsh+1+lsh[0],b[i]-k)-lsh;
        P[i] = lower_bound(lsh+1,lsh+1+lsh[0],b[i])-lsh;
        R[i] = lower_bound(lsh+1,lsh+1+lsh[0],b[i]+k)-lsh;
    }

    int l = 1,r = 0;
    LL ans = 0;
    for(int i = 1;i <= m;i ++) {
        while(r < a[i].r) {
            r ++;
            ans += ask(L[r],R[r]);
            add(P[r],1);
        }
        while(r > a[i].r) {
            add(P[r],-1);
            ans -= ask(L[r],R[r]);
            r --;
        }
        while(l > a[i].l) {
            l --;
            ans += ask(L[l],R[l]);
            add(P[l],1);
        }
        while(l < a[i].l) {
            add(P[l],-1);
            ans -= ask(L[l],R[l]);
            l ++;
        }
        a[i].ans = ans;
    }
    sort(a+1,a+1+m,cmp2);
    for(int i = 1;i <= m;i ++) printf("%lld\n",a[i].ans);
}
