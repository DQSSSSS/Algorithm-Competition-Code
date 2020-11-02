#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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

struct node{
    int l,r;
    int cnt;
}tree[21000000];
int Tcnt = 0;
LL valR;

void insert(LL l,LL r,int last,int &now,LL v) {
    now = ++ Tcnt;
    tree[now] = tree[last];
    tree[now].cnt ++;
    if(l == r) return;
    LL mid = (l + r) >> 1;
    if(v <= mid) insert(l,mid,tree[last].l,tree[now].l,v);
    else insert(mid + 1,r,tree[last].r,tree[now].r,v);
}

int L[SZ],R[SZ],a[SZ],rt[SZ],b[SZ];
LL sum[SZ];

bool cmp(int x,int y) {
    return a[x] < a[y];
}

int ask_less(int l,int r,LL x) { ///有多少个小于等于x
    LL L = 0,R = valR;
    int pl = rt[l-1],pr = rt[r];
    int ans = 0;
    while(L != R) {
        LL mid = L + R >> 1;
        if(mid <= x) {
            ans += tree[tree[pr].l].cnt - tree[tree[pl].l].cnt;
            pl = tree[pl].r;
            pr = tree[pr].r;
            L = mid + 1;
        }
        else {
            pl = tree[pl].l;
            pr = tree[pr].l;
            R = mid;
        }
    }
    return ans;
}

int ask_lager(int l,int r,LL x) { ///有多少个大于等于x
    return r-l+1 - ask_less(l,r,x-1);
}

mt19937 rd(time(0));

int randlr(int l,int r) {
    int len = r-l+1;
    return rd() % (r-l+1);
}

int main() {
//    freopen("G.in","w",stdout); int cc = 3; printf("%d\n",cc); while(cc --) { int n = 300000; printf("%d\n",n); for(int i = 1;i <= n;i ++) printf("%d ",randlr(1,1e9)); puts(""); }
    freopen("G.in","r",stdin);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        Tcnt = 0;
        rt[0] = 0;
        tree[0].l = tree[0].r = tree[0].cnt = 0;

        stack<int> S;
        for(int i = n;i >= 1;i --) {
            while(S.size() && a[i] >= a[S.top()]) S.pop();
            R[i] = S.size() ? S.top()-1 : n;
            S.push(i);
        }
        while(S.size()) S.pop();
        for(int i = 1;i <= n;i ++) {
            while(S.size() && a[i] > a[S.top()]) S.pop();
            L[i] = S.size() ? S.top()+1 : 1;
            S.push(i);
        }

        for(int i = 1;i <= n;i ++)
            sum[i] = sum[i-1] + a[i];
        valR = 3e14;

        insert(0,valR,rt[0],rt[0],0);
        for(int i = 1;i <= n;i ++) {
            insert(0,3e14,rt[i-1],rt[i],sum[i]);
        }
        for(int i = 1;i <= n;i ++) b[i] = i;
        sort(b+1,b+1+n,cmp);

        LL ans = 0;

        for(int k = 1;k <= n;k ++) {
            int i = b[k];
            LL mn = a[i],l = L[i],r = R[i];
            if(i-l+1 < r-i+1) {
                for(int j = l-1;j < i;j ++) {
                    ans += ask_lager(i,r,2*mn+sum[j]);
                }
            }
            else {
                for(int j = i;j <= r;j ++) {
            //        cout << sum[j] - 2*mn << endl;
                    ans += ask_less(l-1,i-1,sum[j]-2*mn);
                }
            }
         //   cout << mn << " "<< l << " " << r << " " << ans << endl;
        }
        printf("%lld\n",ans);
    }
}
/**
5 3 2
1 3 2 1 2
*/

