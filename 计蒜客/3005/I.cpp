#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

struct BIT {
    LL tree[SZ];
    int n;

    void add(int x,int d) {
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }

    LL ask(int x) {
        LL ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    void add(int l,int r,int d) {
        add(l,d);
        add(r+1,-d);
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= n;i ++) tree[i] = 0;
    }
}tr;

int a[SZ],n,m,ans[SZ],pos[SZ];
vector<int> g[SZ];

struct haha {
    int l,r,id;
}b[SZ];

bool cmp(haha a,haha b) { return a.l < b.l; }

void work() {
    for(int i = 1;i <= n;i ++) {
        pos[a[i]] = i;
    }

    tr.init(n);
    for(int i = 1;i <= n;i ++) g[i].clear();
    for(int i = 1;i <= n;i ++) {
        for(int j = i+i;j <= n;j += i) {
            if(pos[i] < pos[j]) {
                g[i].push_back(pos[j]);
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int v : g[i]) {
            tr.add(v,n,1);
        }
    }

    sort(b+1,b+1+m,cmp);
    for(int i = 1,j = 1;i <= m;i ++) {
        while(j < b[i].l) {
            for(int v : g[a[j]]) {
                tr.add(v,n,-1);
            }
            j ++;
        }
        ans[b[i].id] += tr.ask(b[i].r);
    }
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
    }
    for(int i = 1;i <= m;i ++) {
        b[i].l = read();
        b[i].r = read();
        b[i].id = i;
    }

    work();

    for(int i = 1;i <= m;i ++) {
        b[i].l = n-b[i].l+1;
        b[i].r = n-b[i].r+1;
        swap(b[i].l,b[i].r);
    }
    reverse(a+1,a+1+n);
    work();

    for(int i = 1;i <= m;i ++) {
        printf("%d\n",ans[i]);
    }
}
/**
5 5
3 5 2 1 4
1 3
2 4
3 5
1 5
2 5
*/
