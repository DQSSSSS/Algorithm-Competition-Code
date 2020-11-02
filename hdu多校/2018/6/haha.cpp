#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 4e-6;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int n,m;
struct edge {
    int f,t,id;
    LL d;
}l[SZ];

//bool cmp2(haha a,haha b) { return a.d < b.d; }
bool operator <(edge a,edge b) { return a.d < b.d; }

bool use[SZ];
int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

LD check(LD mid) {
    int pl = 0,pr = n;
    for(int i = 1;i <= m;i ++) {
        if(l[i].d < mid) pl = i;
    }
    pr = pl + 1;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    LD ans = 0;
    while(pl >= 1 || pr <= m) {
        int i;
        if(pr > m) i = pl --;
        else if(pl < 1) i = pr ++;
        else if(l[pl].d < l[pr].d) i = pl --;
        else i = pr ++;
        int x = find(l[i].f);
        int y = find(l[i].t);
        if(x != y) {
            fa[x] = y;
            ans += (l[i].d - mid) * (l[i].d - mid);
        }
    }
    return ans;
}

LL get(LD mid) {
    int pl = 0,pr = n;
    for(int i = 1;i <= m;i ++) {
        if(l[i].d < mid) pl = i;
    }
    pr = pl + 1;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) use[i] = 0;
    while(pl >= 1 || pr <= m) {
        int i;
        if(pr > m) i = pl --;
        else if(pl < 1) i = pr ++;
        else if(l[pl].d < l[pr].d) i = pl --;
        else i = pr ++;
        int x = find(l[i].f);
        int y = find(l[i].t);
        if(x != y) {
            fa[x] = y;
            use[i] = 1;
        }
    }

    /*for(int i = 1;i <= m;i ++){
        printf("%d %d %lld %d\n",l[i].f,l[i].t,l[i].d,use[i]);
    }
*/
    LL A = 0;
    for(int i = 1;i <= m;i ++)
        if(use[i]) A = (A + l[i].d);

    A%=mod;
  //  cout << A << endl;
  LL ks = ksm(n - 1,mod - 2);
    A = A * ks % mod;
  //  cout << A * (n - 1) % mod << endl;
    LL ans = 0;
    for(int i = 1;i <= m;i ++)
        if(use[i]) {
            LL d = (l[i].d - A) % mod;
           // (ans += d * d % mod) %= mod;
           ans = (ans + d * d) % mod;
        }
    ans = ans * ks % mod;
    ans += mod; ans %= mod;
    return ans;
}

int main() {
	cout << (unsigned long long)-1 << endl;
    freopen("233.txt","r",stdin);
    int T = read();
    while(T --) {
        n = read(),m = read();
        LD L = 1e5,R = 0;
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read(),v = read();
            l[i].f = x; l[i].t = y; l[i].d = v;
            l[i].id = i;
            L = min(L,(LD)l[i].d);
            R = max(R,(LD)l[i].d);
            //g[x].push_back(y);
            //g[y].push_back(x);
        }
        sort(l + 1,l + 1 + m);
        while(fabs(R - L) > eps) {
            LD midl = L + (R - L) / 3;
            LD midr = R - (R - L) / 3;
            if(check(midl) > check(midr)) L = midl;
            else R = midr;
        }
        printf("%.10f %.10f\n",(double)L,(double)R);
        printf("%lld\n",get((L + R) / 2));
    }
    return 0;
}
