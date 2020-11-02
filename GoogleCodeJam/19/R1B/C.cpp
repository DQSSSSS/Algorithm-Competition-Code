#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

int n,m;
const int maxn = 1e5;

struct seg {
    int l,r;
    int maxn,minn;
}tree[SZ * 4];

void update(int p) {
    tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
    tree[p].minn = min(tree[p<<1].minn,tree[p<<1|1].minn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].maxn = 0;
        tree[p].minn = 1e9;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void change(int p,int x,int d) {
    if(tree[p].l == tree[p].r) {
        tree[p].minn = min(tree[p].minn,d);
        tree[p].maxn = max(tree[p].maxn,d);
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(p);
}

int ask_min(int p,int l,int r) {
    if(l > r) return 1e9;
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].minn;
    }
    int mid = tree[p].l + tree[p].r >> 1,ans = 1e9;
    if(l <= mid) ans = min(ans,ask_min(p<<1,l,r));
    if(mid < r) ans = min(ans,ask_min(p<<1|1,l,r));
    return ans;
}

int ask_max(int p,int l,int r) {
    if(l > r) return 0;
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].maxn;
    }
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans = max(ans,ask_max(p<<1,l,r));
    if(mid < r) ans = max(ans,ask_max(p<<1|1,l,r));
    return ans;
}

int a[SZ],b[SZ];
int L[SZ],R[SZ];
int Lb[SZ],Rb[SZ];
int Lb2[SZ],Rb2[SZ];
stack<int> S;

LL pre(int a[],int b[]) {
    for(int i = 1;i <= n;i ++) {
        while(S.size() && a[S.top()] < a[i]) S.pop();
        if(S.size()) L[i] = S.top() + 1;
        else L[i] = 1;
        S.push(i);
    }
    while(S.size()) S.pop();

    for(int i = n;i >= 1;i --) {
        while(S.size() && a[S.top()] <= a[i]) S.pop();
        if(S.size()) R[i] = S.top() - 1;
        else R[i] = n;
        S.push(i);
    }
    while(S.size()) S.pop();

    build(1,0,maxn);
    for(int i = 1;i <= n;i ++) {
        change(1,b[i],i);
        Lb[i] = ask_max(1,a[i]+m+1,maxn) + 1;
        Lb[i] = max(Lb[i],1);
    }
    build(1,0,maxn);
    for(int i = n;i >= 1;i --) {
        change(1,b[i],i);
        Rb[i] = ask_min(1,a[i]+m+1,maxn) - 1;
        Rb[i] = min(Rb[i],n);
    }

   /* puts("---");
    for(int i = 1;i <= n;i ++) printf("%d ",L[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",R[i]); puts("");
    puts("---");
    for(int i = 1;i <= n;i ++) printf("%d ",Lb[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",Rb[i]); puts("");
*/

    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(Lb[i] > i) continue;
        if(Rb[i] < i) continue;
        LL l = max(L[i],Lb[i]);
        LL r = min(R[i],Rb[i]);
        ans += (i-l+1) * (r-i+1);
      //  cout << i << " " << (i-l+1) * (r-i+1) <<endl;
    }

    //cout << ans << endl;

    build(1,0,maxn);
    for(int i = 1;i <= n;i ++) {
        change(1,b[i],i);
        Lb2[i] = ask_max(1,max(a[i]-m,0),min(a[i]+m,maxn)) + 1;
        Lb2[i] = max(Lb2[i],1);
    }
    build(1,0,maxn);
    for(int i = n;i >= 1;i --) {
        change(1,b[i],i);
        Rb2[i] = ask_min(1,max(a[i]-m,0),min(a[i]+m,maxn)) - 1;
        Rb2[i] = min(Rb2[i],n);
    }

    for(int i = 1;i <= n;i ++) {
        if(Lb2[i] > i) continue;
        if(Rb2[i] < i) continue;
        LL l = max(L[i],max(Lb[i],Lb2[i]));
        LL r = min(R[i],min(Rb[i],Rb2[i]));
        ans -= (i-l+1) * (r-i+1);
    //    cout << i << " " << (i-l+1) * (r-i+1) <<endl;
    }

   /* puts("---");
    for(int i = 1;i <= n;i ++) printf("%d ",Lb2[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",Rb2[i]); puts("");
*/
    return ans;
}

LL baoli() {
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = i;j <= n;j ++) {
            int ma = 0,mb = 0;
            for(int k = i;k <= j;k ++) {
                ma = max(ma,a[k]);
                mb = max(mb,b[k]);
            }
            if(abs(ma - mb) <= m) {
                ans ++;
                //cout << i << " " << j << endl;
            }
        }
    }
    return ans;
}

mt19937 rd(time(0));

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) b[i] = read();

      //  for(int i = 1;i <= n;i ++) a[i] = rd() % 1000 + 1;
       // for(int i = 1;i <= n;i ++) b[i] = rd() % 1000 + 1;

        LL ans = pre(a,b);
        printf("Case #%d: %lld\n",cc,ans);
        //printf("Case #%d: %lld\n",cc,baoli());

        //for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
        //for(int i = 1;i <= n;i ++) printf("%d ",b[i]); puts("");
    }
}
/**
233
5 0
0 8 0 8 0
4 0 4 0 4

233
5 1
3 3 6 4 2
9 5 3 1 6
*/
