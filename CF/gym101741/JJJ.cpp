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

int n,m,a[SZ];
struct haha {
    int l,r,id,ans;
}b[SZ];

bool cmp(haha a,haha b) {
    return a.id < b.id;
}

void solve(int l,int r,int ql,int qr) {
    if(ql > qr) return ;
    if(l == r) {
        for(int i = ql;i <= qr;i ++) {
            b[i].ans = 1 + (a[l] == 0);
        }
        return ;
    }
    int mid = l + r >> 1;
    vector<haha> ta,tb,tc;

    vector<vector<int> > lv,rv;
    lv.resize(m); rv.resize(m);

    int tmp[20] = {};
    tmp[0] = 1;
    tmp[a[mid]] += 1;
    for(int j = 0;j < m;j ++) lv[j].push_back(tmp[j]);
    for(int i = mid - 1;i >= l;i --) {
        int id = mid - i,x = a[i];
        int tt[20] = {};
        for(int j = 0;j < m;j ++) tt[j] = tmp[(j-x+m)%m];
        for(int j = 0;j < m;j ++) add(tmp[j],tt[j]);
        for(int j = 0;j < m;j ++) lv[j].push_back(tmp[j]);
    }

    memset(tmp,0,sizeof tmp);
    tmp[0] = 1;
    tmp[a[mid+1]] += 1;
    for(int j = 0;j < m;j ++) rv[j].push_back(tmp[j]);
    for(int i = mid + 2;i <= r;i ++) {
        int id = i - (mid + 1),x = a[i];
        int tt[20] = {};
        for(int j = 0;j < m;j ++) tt[j] = tmp[(j-x+m)%m];
        for(int j = 0;j < m;j ++) add(tmp[j],tt[j]);
        for(int j = 0;j < m;j ++) rv[j].push_back(tmp[j]);
    }

    for(int i = ql;i <= qr;i ++) {
        if(b[i].r <= mid) {
            ta.push_back(b[i]);
        }
        else if(b[i].l > mid) {
            tb.push_back(b[i]);
        }
        else {
            int lid = mid - b[i].l,rid = b[i].r - mid - 1;
            for(int j = 0;j < m;j ++) add(b[i].ans,1ll*lv[j][lid]*rv[(m-j)%m][rid]%mod);
            tc.push_back(b[i]);
        }
    }
    for(int i = 0;i < ta.size();i ++) b[i+ql] = ta[i];
    for(int i = 0;i < tc.size();i ++) b[i+ql+ta.size()] = tc[i];
    for(int i = 0;i < tb.size();i ++) b[i+ql+ta.size()+tc.size()] = tb[i];
    solve(l,mid,ql,ql+ta.size()-1);
    solve(mid+1,r,qr-tb.size()+1,qr);
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read() % m;
    }

    int q = read();
    for(int i = 1;i <= q;i ++) {
        b[i].l = read();
        b[i].r = read();
        b[i].id = i;
    }
    solve(1,n,1,q);
    sort(b+1,b+1+q,cmp);
    for(int i = 1;i <= q;i ++) printf("%d\n",b[i].ans);
}
