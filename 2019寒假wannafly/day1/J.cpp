#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int a[SZ],c[SZ],n,m,it[SZ];
priority_queue<int> q;
vector<int> g[SZ];

LL check(int mid) {
    LL ans = 0;
    int t = 0;
    for(int i = 1;i <= n;i ++) {
        it[i] = 0;
        if(g[i].size() >= mid) {
            for(int j = 0;j <= g[i].size() - mid;j ++)
                ans += g[i][j],t ++,it[i] ++;
        }
    }
    if(t > mid) return -1;
    while(q.size()) q.pop();
    for(int i = 1;i <= n;i ++)
        for(int j = it[i];j < g[i].size();j ++)
            q.push(-g[i][j]);
   // cout << mid -    t << " ";
   //fuckyou judger
    while(t < mid) {
        t ++;
        int u = q.top(); q.pop();
        ans += -u;
    }
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i ++) {
        scanf("%d%d",&a[i],&c[i]);
        g[c[i]].push_back(a[i]);
    }
    int l = 0,r = m;
    for(int i = 1;i <= n;i ++)
        sort(g[i].begin(),g[i].end());
    while(r - l > 1) {
        int mid = l + r >> 1;
        if(check(mid) != -1) r = mid;
        else l = mid;
    }
    l = r,r = m;
    while(l + 100 <= r) {
        int midl = l + (r-l) / 3;
        int midr = r - (r-l) / 3;
        if(check(midl) < check(midr)) r = midr;
        else l = midl;
    }
    LL ans = 1e18;
    for(int i = l;i <= r;i ++) ans = min(ans,check(i));
    printf("%lld\n",ans);
    return 0;
}
