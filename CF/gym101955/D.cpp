#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 4e5 + 10;
const int INF = 1e9 + 10;
const LL mod = 1e9 + 7;
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

vector<int> g[SZ];
void dfs_sz(int u,int f) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(rt[v] || v == f) continue;
        dfs_sz(v,u);
        sz[u] += sz[v];
    }
}
int get_centroid(int u) {
    dfs_sz(u,0);
    int s = sz[u];
    while(1) {
        int found = 1;
        for(int v : g[u]) {
            if(rt[v] || sz[v] > sz[u]) continue;
            if(sz[v] * 2 >= s) {
                u = v; found = 0; break;
            }
        }
        if(found) return u;
    }
}

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= m;i ++) {


        }
    }
}
