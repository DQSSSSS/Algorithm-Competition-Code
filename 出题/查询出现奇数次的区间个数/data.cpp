#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 998244353;
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

int a[SZ],n,m,L[SZ],R[SZ],X[SZ],Opt[SZ];
mt19937 rd(time(0));

int randlr(int l,int r) { return rd()%(r-l+1)+l; }

void get_data1(int maxn) {
    int maxval = 1e9;
    n = randlr(maxn/10*9,maxn);
    for(int i = 1;i <= n;) {
        int d = randlr(1,3);
        int x = randlr(1,maxval);
        while(d--)
            a[i++] = x;
    }
    random_shuffle(a+1,a+1+n);
    m = randlr(maxn/10*9,maxn);
    for(int i = 1;i <= m;i ++) {
        Opt[i] = randlr(1,2);
        if(Opt[i] == 1) {
            L[i] = randlr(1,n);
            X[i] = randlr(1,100) <= 80 ? a[randlr(1,n)] : randlr(1,maxval);
        }
        else {
            L[i] = randlr(1,n);
            R[i] = randlr(1,n);
            X[i] = randlr(1,100) <= 80 ? a[randlr(1,n)] : randlr(1,maxval);
            if(L[i] > R[i]) swap(L[i],R[i]);
        }
    }

    printf("%d\n",n);
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
    printf("%d\n",m);
    for(int i = 1;i <= m;i ++) {
        if(Opt[i] == 1) printf("%d %d %d\n",Opt[i],L[i],X[i]);
        else printf("%d %d %d %d\n",Opt[i],L[i],R[i],X[i]);
    }
    puts("");
}

void get_data2(int maxval) {
    n = randlr(99001,100000);
    for(int i = 1;i <= n;i ++) a[i] = randlr(1,maxval);
    m = randlr(89989,100000);
    for(int i = 1;i <= m;i ++) {
        Opt[i] = randlr(1,2);
        if(Opt[i] == 1) {
            L[i] = randlr(1,n),X[i] = randlr(1,maxval);
        }
        else {
            L[i] = randlr(1,n);
            R[i] = randlr(1,n);
            X[i] = randlr(1,maxval);
            if(L[i] > R[i]) swap(L[i],R[i]);
        }
    }

    printf("%d\n",n);
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
    printf("%d\n",m);
    for(int i = 1;i <= m;i ++) {
        if(Opt[i] == 1) printf("%d %d %d\n",Opt[i],L[i],X[i]);
        else printf("%d %d %d %d\n",Opt[i],L[i],R[i],X[i]);
    }
    puts("");
}

int main() {
    freopen("data.in","w",stdout);
    int T = 20;
    printf("%d\n",T);
   // get_data1(5);
    get_data2(1);
    get_data2(2);
    get_data2(5);
    get_data2(5);
    get_data2(1000);
    get_data2(1000);
    get_data2(100000);
    get_data2(100000);
    T -= 8;
    while(T --)
        get_data1(100000);

    /*for(int i = 1;i <= m;i ++) {
        int l = L[i],r = R[i],x = X[i];
        int ans = 0;
        for(int j = l;j <= r;j ++) if(__gcd(x,a[j]) == 1) ans ++;
        printf("%d\n",ans);
    }*/
    return 0;
}
