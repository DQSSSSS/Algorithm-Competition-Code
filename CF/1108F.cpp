#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int fa[SZ];
vector<int> g[SZ];

int node[SZ],node2[SZ],vis[SZ];

void dfs(int u) {
    vis[u] = 1;
    node[++ node[0]] = u;
    node2[++ node2[0]] = u;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

struct haha {
    int f,t,d;
}l[SZ];

bool cmp(haha a,haha b) { return a.d < b.d; }

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++){
        l[i].f = read(),l[i].t = read(),l[i].d = read();
    }
    sort(l + 1,l + 1 + m,cmp);
    for(int i = 1;i <= n;i ++) fa[i] = i;

    int ans = 0;
    for(int k = 1,lst = 1;k <= m;k ++) {
        if(k == m || l[k].d != l[k+1].d) {
            int edgenum = 0,nodenum = 0,ltknum = 0;
            for(int i = lst;i <= k;i ++) {
                int x = find(l[i].f);
                int y = find(l[i].t);
                if(x != y) {
                    edgenum ++;
                    g[x].push_back(y);
                    g[y].push_back(x);
                }
            }
            for(int i = lst;i <= k;i ++) {
                int x = find(l[i].f);
                int y = find(l[i].t);
                if(x != y && !vis[x]) {
                    node[0] = 0;
                    dfs(x);
                    nodenum += node[0];
                    ltknum ++;
                }
            }
            for(int i = 1;i <= node2[0];i ++) {
                int x = node2[i];
                g[x].clear();
                vis[x] = 0;
            }
            node2[0] = 0;
            for(int i = lst;i <= k;i ++) {
                int x = find(l[i].f);
                int y = find(l[i].t);
                if(x != y) {
                    fa[x] = y;
                }
            }
            ans += edgenum - (nodenum - ltknum);
           // cout << l[k].d << " " << edgenum << " " << nodenum << " " << ltknum << endl;
            lst = k + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
