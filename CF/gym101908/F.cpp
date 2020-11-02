#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
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
    int l,r,d,id;
}a[SZ];

bool cmp(haha a,haha b) {
    return a.r < b.r;
}

int tree[1100][3030],lsh[3030];

void add(int tree[],int x,int d) {
    for(int i = x;i <= lsh[0];i += i&-i)
        tree[i] = max(tree[i],d);
}

int ask(int tree[],int x) {
    int ans = -1e9;
    for(int i = x;i > 0;i -= i&-i)
        ans = max(tree[i],ans);
    return ans;
}

int main() {
    int m = read(),n = 0;
    for(int i = 1;i <= m;i ++) {
        int k = read();
        while(k --) {
            n ++;
            a[n].l = read() + 1;
            a[n].r = read() + 1;
            a[n].d = read();
            a[n].id = i-1;
            lsh[++ lsh[0]] = a[n].l;
            lsh[++ lsh[0]] = a[n].r;
        }
    }
    lsh[++ lsh[0]] = 1;

    sort(lsh + 1,lsh + 1 + lsh[0]);
    lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;

    sort(a + 1,a + 1 + n,cmp);
    for(int i = 1;i <= n;i ++) {
        a[i].l = lower_bound(lsh+1,lsh+1+lsh[0],a[i].l)-lsh;
        a[i].r = lower_bound(lsh+1,lsh+1+lsh[0],a[i].r)-lsh;
    }


    //for(int i = 1;i <= n;i ++) cout << a[i].l << " " << a[i].r << " " << a[i].d << " " << a[i].id << endl;

    //puts("");

    for(int i = 0;i < (1<<m);i ++)
        for(int j = 1;j <= lsh[0];j ++)
            tree[i][j] = -1e9;

    add(tree[0],1,0);

    for(int i = 1;i <= n;i ++) {
        int r = a[i].r,l = a[i].l,id = a[i].id;
        for(int j = 0;j < (1<<m);j ++) {
            if(j >> id & 1) {
                int ans = -1e9;
                ans = max(ans,ask(tree[j],l)+a[i].d);
                ans = max(ans,ask(tree[j-(1<<id)],l)+a[i].d);

             //   cout << ask(tree[j],l) << " " << ask(tree[j-(1<<id)],l) << endl;
             //   cout << j << " " << r << " " << ans << endl;
                add(tree[j],r,ans);
            }
        }
    }
    int ans = -1;
    for(int i = 1;i <= n;i ++)
        ans = max(ans,ask(tree[(1<<m)-1],a[i].r));
    cout << ans << endl;
}
