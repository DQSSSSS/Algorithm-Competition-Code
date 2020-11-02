#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

void add(int &a,const int &b) {
    a += b;
    if(a>=mod) a-=mod;
}

int n,m,a[SZ],id[SZ],B;

struct seg {
    int l,r,dep;
    vector<vector<int> > lv;
    vector<vector<int> > rv;
}tree[SZ * 4];


void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].dep = tree[p/2].dep + 1;
    if(l == r) {
        id[l] = p;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);

    tree[p].lv.resize(m);
    tree[p].rv.resize(m);

    int tmp[20] = {};
    tmp[0] = 1;
    tmp[a[mid]] += 1;
    for(int j = 0;j < m;j ++) tree[p].lv[j].push_back(tmp[j]);
    for(int i = mid - 1;i >= l;i --) {
        int id = mid - i,x = a[i];
        int tt[20] = {};
        for(int j = 0;j < m;j ++) tt[j] = tmp[(j-x+m)%m];
        for(int j = 0;j < m;j ++) add(tmp[j],tt[j]);
        if(id % B == 0) {
            for(int j = 0;j < m;j ++) tree[p].lv[j].push_back(tmp[j]);
        }
    }

    memset(tmp,0,sizeof tmp);
    tmp[0] = 1;
    tmp[a[mid+1]] += 1;
    for(int j = 0;j < m;j ++) tree[p].rv[j].push_back(tmp[j]);
    for(int i = mid + 2;i <= r;i ++) {
        int id = i - (mid + 1),x = a[i];
        int tt[20] = {};
        for(int j = 0;j < m;j ++) tt[j] = tmp[(j-x+m)%m];
        for(int j = 0;j < m;j ++) add(tmp[j],tt[j]);
        if(id % B == 0) {
            for(int j = 0;j < m;j ++) tree[p].rv[j].push_back(tmp[j]);
        }
    }
/*
    printf("[%d,%d] %d\n",l,r,mid);
    printf("lv: \n");
    for(int i = 0;i <= (mid - l + 1) / B;i ++) {
        for(int j = 0;j < m;j ++) {
            printf("%d ",tree[p].lv[j][i]);
        }
        puts("");
    }

    printf("rv: \n");
    for(int i = 0;i <= (r - mid) / B;i ++) {
        for(int j = 0;j < m;j ++) {
            printf("%d ",tree[p].rv[j][i]);
        }
        puts("");
    }*/
}

int ask(int l,int r) {
    if(l == r) {
        return 1 + (a[l] == 0);
    }
    int pl = id[l];
    int pr = id[r];
    if(tree[pl].dep > tree[pr].dep) pl /= 2;
    if(tree[pl].dep < tree[pr].dep) pr /= 2;
    while(pl != pr) pl /= 2,pr /= 2;
    int p = pl;
    int mid = tree[p].l + tree[p].r >> 1;
    int lid = (mid - l) / B,rid = (r - mid - 1) / B;

   // printf("[%d,%d]\n",tree[p].l,tree[p].r);
    int ans[20] = {};
    for(int i = 0;i < m;i ++){
        for(int j = 0;j < m;j ++) {
            add(ans[(i+j)%m],1ll * tree[p].lv[i][lid] * tree[p].rv[j][rid] % mod);
        }
    }

    for(int i = mid - (lid*B) - 1;i >= l;i --) {
        int x = a[i];
        int tmp[20] = {};
        for(int j = 0;j < m;j ++) tmp[j] = ans[(j-x+m)%m];
        for(int j = 0;j < m;j ++) add(ans[j],tmp[j]);
    }
    for(int i = mid + 1 + (rid*B) + 1;i <= r;i ++) {
        int x = a[i];
        int tmp[20] = {};
        for(int j = 0;j < m;j ++) tmp[j] = ans[(j-x+m)%m];
        for(int j = 0;j < m;j ++) add(ans[j],tmp[j]);
    }
    return ans[0];
}


int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read() % m;
    }
    B = 25;
    build(1,1,n);
    int q = read();
    while(q --) {
        int l = read(),r = read();
        printf("%d\n",ask(l,r));
    }
}

/*
10 10
5 1 3 2 0 8 6 4 3 8
233
1 2
1 3
1 4
2 4
6 8
5 9
5 5
*/
