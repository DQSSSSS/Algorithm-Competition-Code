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

vector<vector<pii> > g;
map<int,int> mp;
int a[SZ],sum[SZ];
bool cmp(pii a,pii b) { return a.second < b.second; }

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) sum[i] = a[i] + sum[i-1];

    vector<pii> ttt;
    g.push_back(ttt);
    int tot = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j < i;j ++) {
            if(!mp[sum[i]-sum[j]]) {
                mp[sum[i]-sum[j]] = ++ tot;
                g.push_back(ttt);
            }
            g[mp[sum[i]-sum[j]]].push_back(make_pair(j+1,i));
        }

    int ans = 0,id = -1;
    for(int k = 1;k <= tot;k ++) {
        sort(g[k].begin(),g[k].end(),cmp);
        int tmp = 1,maxr = g[k][0].second;
        for(int i = 1;i < g[k].size();i ++) {
            pii p = g[k][i];
            if(p.first > maxr) tmp ++,maxr = p.second;
        }
        if(tmp > ans) ans = tmp,id = k;
        ans = max(ans,tmp);
    }
    printf("%d\n",ans);
    int maxr = -1;
    for(int i = 0;i < g[id].size();i ++) {
        pii p = g[id][i];
        if(p.first > maxr) {
            maxr = p.second;
            printf("%d %d\n",p.first,p.second);
        }
    }
}
