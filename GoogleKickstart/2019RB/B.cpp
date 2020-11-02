#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const LL INF = 1e18 + 10;
const int SZ = 5e5 + 10;
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

struct haha {
    LL s,e,l;
}a[SZ];

bool cmp1(haha a,haha b) { return a.s * b.l < b.s * a.l; }
bool cmp2(haha a,haha b) { return a.l < b.l; }
bool cmp3(haha a,haha b) { return a.s < b.s; }
bool cmp4(haha a,haha b) { return a.e * b.l < b.e * a.l; }
bool cmp5(haha a,haha b) { return a.e > b.e; }
bool cmp6(haha a,haha b) { return a.e * b.l * b.s < b.e * a.l * a.s; }

LL f[SZ];

LL work(int n,int m) {
    for(int i = 0;i <= m;i ++) f[i] = -INF;
    f[0] = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = m;j >= a[i].s;j --) {
            if(a[i].e - (j-a[i].s) * a[i].l <= 0) continue;
            f[j] = max(f[j],f[j-a[i].s] + a[i].e - (j-a[i].s) * a[i].l);
        }
    }
    LL ans = 0;
    for(int i = 0;i <= m;i ++) ans = max(ans,f[i]);
    //for(int i = 0;i <= m;i ++) printf("%lld ",f[i]<0?-1:f[i]); puts("");
    return ans;
}

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read();
        LL maxt = 1e5;
        for(int i = 1;i <= n;i ++) {
            a[i].s = read();
            a[i].e = read();
            a[i].l = read();
        }
        LL ans = 0;
        sort(a+1,a+1+n,cmp1); ans = max(ans,work(n,maxt));
        sort(a+1,a+1+n,cmp2); ans = max(ans,work(n,maxt));
        sort(a+1,a+1+n,cmp3); ans = max(ans,work(n,maxt));
        sort(a+1,a+1+n,cmp4); ans = max(ans,work(n,maxt));
        sort(a+1,a+1+n,cmp5); ans = max(ans,work(n,maxt));
        sort(a+1,a+1+n,cmp6); ans = max(ans,work(n,maxt));

        printf("Case #%d: %lld\n",cc,ans);
    }
}
