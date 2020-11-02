#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3100100;
const int INF = 1e9 + 10;
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

LL tree[2][SZ];
int tot;

void add(int id,int x,LL d) {
    for(int i = x;i <= tot;i += i & -i) tree[id][i] += d;
}

LL ask(int id,int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[id][i];
    return ans;
}

int L[100010],R[100010],val[100010];
LL sum[3100010];

struct node {
    int val,id;
}lsh[SZ];

bool operator <(node a,node b) { return a.val < b.val; }

struct haha {
    int l,r,k,id;
    LL ans;
}a[500010],bl[500010],br[500010];

bool operator <(haha a,haha b) { return a.id < b.id; }

void dfs(int l,int r,int L,int R) {
    if(l > r || L > R) return ;
    if(L == R) {
        for(int i = l;i <= r;i ++) {
            if(a[i].k) a[i].ans -= lsh[L].val;
           // cout << lsh[L].val << endl;
        }
        return ;
    }
    int mid = L + R >> 1,pl = 0,pr = 0;
    for(int i = mid+1;i <= R;i ++) {
        add(0,lsh[i].id,1);
        add(1,lsh[i].id,lsh[i].val);
    }
   // cout << l << " " << r << " -- " << L << " " << mid << " " << R << endl;
    for(int i = l;i <= r;i ++) {
        int x = ask(0,a[i].r) - ask(0,a[i].l-1);
        LL y = ask(1,a[i].r) - ask(1,a[i].l-1);
     //   cout << a[i].l << " " << a[i].r << " " << a[i].k << " " << x<< " " << y << endl;
        if(a[i].k >= x) {
            a[i].k -= x;
            a[i].ans -= y;
            br[++ pr] = a[i];
       //     cout << y << endl;
        }
        else {
            bl[++ pl] = a[i];
        }
    }
    for(int i = mid+1;i <= R;i ++) {
        add(0,lsh[i].id,-1);
        add(1,lsh[i].id,-lsh[i].val);
    }
    for(int i = 1;i <= pl;i ++) a[i+l-1] = bl[i];
    for(int i = 1;i <= pr;i ++) a[pl+i+l-1] = br[i];
    dfs(l,l+pl-1,mid+1,R);
    dfs(l+pl,r,L,mid);
}

int main() {
    //freopen("C.in","r",stdin);
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        int x = read();
        L[i] = tot + 1;
        while(x) {
            val[++ tot] = x - x / 2;
            sum[tot] = sum[tot - 1] + val[tot];
            lsh[tot].val = val[tot]; lsh[tot].id = tot;
            x /= 2;
        }
        R[i] = tot;
    }
    sort(lsh + 1,lsh + 1 + tot);

  /*  for(int i = 1;i <= tot;i ++) cout << val[i] << " "; puts("");
    for(int i = 1;i <= tot;i ++) printf("%3d",lsh[i].val); puts("");
    for(int i = 1;i <= tot;i ++) printf("%3d",lsh[i].id); puts("");
    for(int i = 1;i <= n;i ++) cout << L[i] << " " << R[i] << endl; puts("");
*/
    for(int i = 1;i <= m;i ++)  {
        a[i].l = read(),a[i].r = read(),a[i].k = read();
        a[i].id = i;
        a[i].ans = sum[R[a[i].r]] - sum[L[a[i].l]-1];
        a[i].l = L[a[i].l],a[i].r = R[a[i].r];
    //    cout << a[i].l << " " << a[i].r << " " << a[i].ans << endl;
    }
    dfs(1,m,1,tot);
    sort(a + 1,a + 1 + m);
    //for(int i = 1;i <= m;i ++) printf("%d\n",a[i].k);
    for(int i = 1;i <= m;i ++) printf("%lld\n",a[i].ans);
    return 0;
}
/**
5 1
2 4 7 9 7
1 3 2
*/
