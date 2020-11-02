#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int n,k;
LL a[SZ],sum[SZ];
int pr[SZ];
char s[SZ];

void get_pr() {
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || s[i] != s[i + 1]) {
            for(int j = lst;j <= i;j ++) {
                int t = j - lst + 1;
                if(t <= k) pr[j] = lst;
                else pr[j] = j - k + 1;
            }
            lst = i + 1;
        }
    }
}


struct seg {
    int l,r;
    LL mx;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = min(tree[p << 1].mx,tree[p <<1 | 1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].mx = 1e18;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p << 1,l,mid);
    build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int x,LL d) {
    if(tree[p].l == tree[p].r) {
        tree[p].mx = d;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p << 1,x,d);
    else change(p << 1 | 1,x,d);
    update(p);
}

LL ask(int p,int l,int r) {
    if(l > r) return 0;
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 1e18;
    if(l <= mid) ans = min(ans,ask(p << 1,l,r));
    if(mid < r) ans = min(ans,ask(p << 1 | 1,l,r));
    return ans;
}

LL f[SZ][2];

int main() {
    n = read(),k = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
    }
    scanf("%s",s + 1);
    LL ans = 0;
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || s[i] != s[i + 1]) {
            sort(a + lst,a + i + 1);
            int pos = i,dd = k;
            while(pos >= lst && dd--) {
                ans += a[pos --];
            }
            lst = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
