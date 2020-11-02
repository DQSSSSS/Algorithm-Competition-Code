#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

vector<int> g[SZ];

int now_sum_sz;
bool rt[SZ];

void dfs_sumsz(int u,int fa) {
    now_sum_sz ++;
    for(int v : g[u]) {
        if(v == fa || rt[v]) continue;
        dfs_sumsz(v,u);
    }
}

int maxn,root;

int find(int u,int fa) {
    int sz = 1,now = 0;
    for(int v : g[u]) {
        if(v == fa || rt[v]) continue;
        int sonsz = find(v,u);
        sz += sonsz;
        now = max(now,sonsz);
    }
    now = max(now,now_sum_sz - sz);
    if(now < maxn) maxn = now,root = u;
   // cout << "find " << u << " " << now << " " << maxn << " " << root << endl;
    return sz;
}

int dist[SZ],s,t;

void dfs_dist(int u,int fa,int d) {
    dist[++ t] = d;
    for(int v : g[u]) {
        if(v == fa || rt[v]) continue;
        dfs_dist(v,u,d+1);
    }
}

LL get_ans(int s,int t,int len) {
    sort(dist + s,dist + t + 1);
    len --;
    LL ans = 0;
    int r = t;
    for(int i = s;i <= t;i ++) {
        while(r > i && dist[i] + dist[r] > len) r --;
        ans += r - i;
        if(r == i) break;
    }
    LL sum = t-s+1;
    sum = (sum * (sum-1)) / 2;
    return sum - ans;
}

LL ans;

LL dfs(int x,int fa,int len) {
    now_sum_sz = 0;
    dfs_sumsz(x,fa);
    //cout << now_sum_sz << endl;
    maxn = now_sum_sz;
    find(x,fa);
   // cout << root << endl;
    int u = root;
    rt[u] = 1;
    s = 1,t = 0;
    //cout << x << " " << u << endl;
    for(int v : g[u]) {
        if(rt[v]) continue;
        s = t + 1;
        dfs_dist(v,u,1);
        ans -= get_ans(s,t,len);
    }
    dist[++ t] = 0;
    //cout << get_ans(1,t,len) << endl;
    ans += get_ans(1,t,len);
    for(int v : g[u]) if(!rt[v]) dfs(v,u,len);
}

int n;

LL work(int len) {
    for(int i = 1;i <= n;i ++) rt[i] = 0;
    ans = 0;
   // puts("---");
    dfs(1,0,len);
   // cout << len << " " << ans << endl;
    return ans;
}

int main() {
    freopen("awesome.in","r",stdin);
    int T = read();
    while(T --) {
        n = read();
        int l = read(),r = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        printf("%lld\n",work(n-1-r) - work(n-l));
       // work(n-1-r);
     //   work(n-1-(l-1));
//        printf("%lld\n",work(n-1-r));
 //       printf("%lld\n",work(n-1-l));
    }
    return 0;
}
/**
2
5 1 2
1 2
2 3
4 5
2 4
5 1 3
1 2
2 3
4 5
2 4

*/
