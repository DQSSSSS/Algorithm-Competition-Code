#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct BIT {
    int n;
    LL tree[SZ];
    void add(int x,LL d) {
        for(int i = x;i <= n;i += i&-i) tree[i] += d;
    }

    LL ask(int x) {
        LL ans = 0;
        for(int i = x;i > 0;i -= i&-i) ans += tree[i];
        return ans;
    }

    LL ask(int l,int r) {
        return ask(r) - ask(l-1);
    }
}t0,t1;

struct ahha {
    int l,r,id;
    double ans,k;
}a[SZ];

bool cmp(ahha a,ahha b) {
    return a.id < b.id;
}

pii h[SZ];

void dfs(double al,double ar,int l,int r,int t,int nowp) {
    if(l > r) return ;
  //9  printf("%.3f %.3f %d %d %d %d\n",al,ar,l,r,t,nowp);
    if(t >= 50) {
        for(int i = l;i <= r;i ++) a[i].ans = al;
        return ;
    }
    double mid = (al+ar)/2;
    int sp = nowp;
    while(nowp >= 1 && h[nowp].first >= mid) {
        t0.add(h[nowp].second,1);
        t1.add(h[nowp].second,h[nowp].first);
      //  printf("t0 add %d %d\n",h[nowp].second,1);
      //  printf("t1 add %d %d\n",h[nowp].second,h[nowp].first);
        nowp --;
    }
    vector<ahha> bl,br;
  //  for(int i = l;i <= r;i ++) printf("%d\n",a[i].id);
    for(int i = l;i <= r;i ++) {
        double s0 = t0.ask(a[i].l,a[i].r);
        double s1 = t1.ask(a[i].l,a[i].r);
        if(s1-s0*mid > a[i].k) br.push_back(a[i]);
        else bl.push_back(a[i]);
    }
    for(int i = 0;i < bl.size();i ++) a[i+l] = bl[i];
    for(int i = 0;i < br.size();i ++) a[i+l+bl.size()] = br[i];
    dfs(al,mid,l,l+bl.size()-1,t+1,nowp);
    for(int i = sp;i > nowp;i --) {
        t0.add(h[i].second,-1);
        t1.add(h[i].second,-h[i].first);
       // printf("t0 del %d %d\n",h[i].second,1);
      //  printf("t1 del %d %d\n",h[i].second,h[i].first);
    }
    dfs(mid,ar,l+bl.size(),r,t+1,sp);
}

LL sum[SZ];

int main() {
    int n = read(),q = read();
    t0.n = n;
    t1.n = n;
    for(int i = 1;i <= n;i ++) {
        h[i].first = read();
        h[i].second = i;
        sum[i] = sum[i-1] + h[i].first;
    }
    sort(h+1,h+1+n);
    for(int i = 1;i <= q;i ++) {
        a[i].l = read();
        a[i].r = read();
        int x = read();
        int y = read();
        a[i].k = 1.0*(sum[a[i].r]-sum[a[i].l-1])/y*x;
        a[i].id = i;
    }
    dfs(0,1e5,1,q,0,n);
    sort(a+1,a+1+q,cmp);
    for(int i = 1;i <= q;i ++) {
        printf("%.10f\n",a[i].ans);
    }
}
