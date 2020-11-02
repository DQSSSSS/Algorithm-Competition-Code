#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

vector<int> g[SZ],nodelist;

int num[SZ],mark[SZ],p[SZ],vis[SZ];

void dfs(int u) {
    nodelist.push_back(u);
    vis[u] = 1;
    for(int v : g[u]) {
        if(p[v]) continue;
        if(vis[v]) continue;
        dfs(v);
    }
}

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read(),k = read();
        for(int i = 1;i <= n;i ++) {
            g[i].clear();
            mark[i] = 0;
            num[i] = 0;
            p[i] = 0;
            vis[i] = 0;
        }
        for(int i = 1;i <= m;i ++) {
            int x = read();
            int y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i = 1;i <= k;i ++) {
            int x = read();
            p[x] = 1;
        }
        for(int i = 1;i <= n;i ++) {
            if(!vis[i] && !p[i]) {
                nodelist.clear();
                dfs(i);
                int flag = 0;
                for(int x : nodelist) {
                    num[x] = nodelist.size();
                    if(x == 1) flag = 1;
                }
                if(flag) {
                    for(int x : nodelist) {
                        mark[x] = 1;
                    }
                }
            }
        }
        double ans = 0;
        for(int i = 1;i <= n;i ++) {
            if(p[i]) {
                bool flag = 0;
                for(int v : g[i]) {
                    if(mark[v]) flag = 1;
                }
                double tmp = num[1];
                if(flag) {
                    for(int v : g[i]) {
                        if(!mark[v]) {
                            tmp += 1.0/g[i].size() * num[v];
                        }
                    }
                    ans = max(ans,tmp);
                }
            }
        }
        printf("%.6f\n",ans);
    }
}
