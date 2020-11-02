#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

vector<pii> g[SZ];

int dfn[SZ],dfs_clock,low[SZ],num[SZ],bri[SZ],du[SZ];

void dfs(int u,int f) {
    dfn[u] = low[u] = ++ dfs_clock;
    for(pii e : g[u]) {
        int v = e.first;
        if(v == f) continue;
        if(!dfn[v]) {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]) bri[e.second] = 1;
        }
        else if(dfn[v] < dfn[u])
            low[u] = min(low[u],dfn[v]);
    }
}

void dfs3(int u,int c) {
    num[u] = c;
    for(pii e : g[u]) {
        int v = e.first;
        if(num[v] || bri[e.second]) continue;
        dfs3(v,c);
    }
}

vector<int> node;
bool vis[SZ];

void dfs2(int u,int f) {
    vis[u] = 1;
    node.push_back(u);
    for(pii e : g[u]) {
        int v = e.first;
        if(v == f) continue;
        dfs2(v,u);
    }
}

int ff[SZ],tt[SZ];
vector<pii> aaa;

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        g[x].push_back(make_pair(y,i));
        g[y].push_back(make_pair(x,i));
        ff[i] = x;
        tt[i] = y;
    }

    for(int i = 1;i <= n;i ++)
        if(!dfn[i])
            dfs(i,0);

    int tot = 0;
    for(int i = 1;i <= n;i ++)
        if(!num[i])
           dfs3(i,++ tot);

    for(int i = 1;i <= n;i ++) g[i].clear();
    for(int i = 1;i <= m;i ++) {
        int x = ff[i],y = tt[i];
        if(num[x] != num[y]) {
            g[num[x]].push_back(make_pair(num[y],i));
            g[num[y]].push_back(make_pair(num[x],i));
            du[num[x]] ++;
            du[num[y]] ++;
        }
    }

    int ans = 0;
    for(int i = 1;i <= tot;i ++) {
        if(!vis[i]) {
            node.clear();
            dfs2(i,0);

            if(node.size() == 1) continue;
            if(node.size() == 2) {
                ans ++;
                int x = node[0],y = g[x][0].second;
                //if(num[ff[y]] != x) swap(ff[i],tt[i]);
                aaa.push_back(make_pair(ff[y],tt[y]));
                continue;
            }
            int tmp = 1e9,id = -1;
            for(int x : node) {
                if(du[x] == 1) continue;
                if(tmp > du[x]) {
                    tmp = du[x],id = x;
                }
            }
            ans += tmp;
            for(pii e : g[id]) {
                int y = e.second;
               // if(num[ff[y]] != id) swap(ff[y],tt[y]);
                aaa.push_back(make_pair(ff[y],tt[y]));
            }
        }
    }
    cout << ans << endl;
    sort(aaa.begin(),aaa.end());
    for(int i = 0;i < aaa.size();i ++) {
        printf("%lld %lld\n",aaa[i].first,aaa[i].second);
    }
}
