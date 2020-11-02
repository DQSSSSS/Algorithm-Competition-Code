#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

int read() {
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct node {
    int sz,l,r;
}tree[SZ * 4];

int Tcnt = 1;

void insert(int p,int l,int r,int x,int d) {
    tree[p].sz += d;
    if(l == r) return ;
    int mid = l + r >> 1;
    if(x <= mid) {
        if(tree[p].l == 0) tree[p].l = ++ Tcnt;
        insert(tree[p].l,l,mid,x,d);
    }
    else {
        if(tree[p].r == 0) tree[p].r = ++ Tcnt;
        insert(tree[p].r,mid+1,r,x,d);
    }
}

int lsh[SZ];

int ask(int k) {
    if(tree[1].sz < k) return -1;
    int l = 1,r = lsh[0],p = 1;
    while(l != r) {
        int mid = l + r >> 1;
        if(tree[tree[p].l].sz >= k)
            r = mid,p = tree[p].l;
        else
            k -= tree[tree[p].l].sz,l = mid + 1,p = tree[p].r;
    }
    return l;
}

priority_queue<pii> q;

struct haha {
    int op,now,val,r;
}a[SZ];

int main() {
    //freopen("K.in","r",stdin);
   //freopen("K.out","w",stdout);
    int T = read(),cc = 0;
    while(T --) {
        int n = read();

        while(q.size()) q.pop();
        lsh[0] = 0;
        for(int i = 1;i <= Tcnt;i ++) tree[i].sz = tree[i].l = tree[i].r = 0;
        Tcnt = 1;

        for(int i = 1;i <= n;i ++) {
            a[i].op = read();
            if(a[i].op == 1) {
                a[i].now = read();
                a[i].val = read();
                a[i].r = read();
                lsh[++ lsh[0]] = a[i].val;
            }
            else {
                a[i].now = read();
                a[i].val = read();
            }
        }

        sort(lsh + 1,lsh + 1 + lsh[0]);
        lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;

        printf("Case %d:\n",++ cc);
        //for(int i = 1;i <= lsh[0];i ++) cout << lsh[i] << " "; puts("");
        for(int i = 1;i <= n;i ++) {
            if(a[i].op == 1) {
                a[i].val = lower_bound(lsh + 1,lsh + 1 + lsh[0],a[i].val) - lsh;
                insert(1,1,lsh[0],a[i].val,1);
                q.push(make_pair(-a[i].r,a[i].val));
            }
            else {
                while(q.size() && -q.top().first < a[i].now) {
                    insert(1,1,lsh[0],q.top().second,-1); q.pop();
                }
                //cout << " --" << tree[1].sz << endl;
                int ans = ask(a[i].val);
                if(ans != -1) ans = lsh[ans];
                printf("%d\n",ans);
            }
        }
    }
}
/**

*/
