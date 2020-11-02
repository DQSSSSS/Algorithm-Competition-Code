#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 998244353;

LL read(){
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
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int a[SZ];
pii b[SZ],c[SZ];

vector<pii> g[SZ];
int f[SZ];

int ask(int id,int x) {
    int sum = 0;
    int l = -1,r = g[id-1].size();
    while(r-l>1) {
        int mid = l + r >> 1;
        if(g[id-1][mid].first >= x) l = mid;
        else r = mid;
    }
    if(l == -1) sum = g[id-1][g[id-1].size()-1].second;
    else sum = (g[id-1][g[id-1].size()-1].second - g[id-1][l].second + mod) % mod;

    int pre;
    if(g[id].size()) pre = g[id][g[id].size()-1].second;
    else pre = 0;
    g[id].push_back(make_pair(x,(sum+pre)%mod));
    return sum;
}

void work(int a[],int n,pii b[]) {
    for(int i = 0;i <= n;i ++)
        g[i].clear(),f[i] = INF;
    g[0].push_back(make_pair(-INF,1));
    for(int i = 1;i <= n;i ++) {
        int id = lower_bound(f+1,f+1+n,a[i]) - f;
        int ans = ask(id,a[i]);
        b[i] = make_pair(id,ans);
        f[id] = a[i];
    }/*
    for(int i = 1;i <= n;i ++) printf("%d ",f[i]); puts("");
    for(int i = 0;i <= n;i ++) {
        for(pii x: g[i]) {
            printf("(%d,%d) ",x.first,x.second);
        }
        puts("");
    }
    puts("");*/
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    work(a,n,b);
    reverse(a+1,a+1+n);
    for(int i = 1;i <= n;i ++) a[i] = -a[i];
    work(a,n,c);
    for(int i = 1;i <= n/2;i ++) swap(c[i],c[n-i+1]);

    int len = 0,sum = 0;
    for(int i = 1;i <= n;i ++)
        len = max(len,b[i].first);
    for(int i = 1;i <= n;i ++) {
        if(b[i].first == len) (sum += b[i].second) %= mod;
    }
/*
    cout << len << " " << sum << endl;
    for(int i = 1;i <= n;i ++) printf("%d ",b[i].first); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",b[i].second); puts("");

    for(int i = 1;i <= n;i ++) printf("%d ",c[i].first); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",c[i].second); puts("");
*/
    for(int i = 1;i <= n;i ++) {
        int ans;
        if(b[i].first + c[i].first - 1 == len) {
            ans = 1ll * b[i].second * c[i].second % mod * ksm(sum,mod-2) % mod;
        }
        else ans = 0;
//        printf("%d%c",ans,i == n ? '\n' : ' ');
        printf("%d ",ans);
    }
}
