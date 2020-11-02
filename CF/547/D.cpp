#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

struct edge {
    int t,d;
};

vector<edge> g[SZ];

int cur[SZ],path[SZ],mark[SZ],n;
char a[SZ];

void dfs(int u) {
    for(int &i = cur[u];i < g[u].size();i ++) {
        int v = g[u][i].t,id = g[u][i].d;
        if(mark[id]) continue;
        mark[id] = 1;
        dfs(v);
     //   cout << u << " " << v << " " << i << " " << id << endl;
        path[++ path[0]] = u>2e5?-id:id;
    }
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) {
        int x = read(),y = read() + 2e5;
        g[x].push_back((edge){y,i});
        g[y].push_back((edge){x,i});
    }
    for(int i = 1,lst = -1,t = 4e5;i <= 4e5;i ++) {
        if(g[i].size() % 2) {
            if(lst == -1) lst = i;
            else {
                g[lst].push_back((edge){i,++ t});
                g[i].push_back((edge){lst,t});
                lst = -1;
            }
        }
    }
    for(int i = 1;i <= 4e5;i ++) {
        if(cur[i] < g[i].size()) {
            dfs(i);
        }
    }
    for(int i = 1;i <= path[0];i ++) a[abs(path[i])] = path[i]<0? 'b' : 'r';
    for(int i = 1;i <= n;i ++) printf("%c",a[i]);
}
