#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

vector<int> g[SZ];

int fa[SZ],son[SZ],deep[SZ],n;
int a[SZ];

void dfs(int u,int f) {
	deep[u] = deep[f] + 1;
	fa[u] = f;
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(v == f) continue;
        son[u] ++;
        dfs(v,u);
    }
}

bool check() {
	for(int i = 2,pf = 1,p = 2;i <= n;i ++) {
        if(i == n || deep[a[i]] != deep[a[i + 1]]) {
            int npf = p,ed = p - 1;
            int deepnow = deep[a[p]];
            while(pf <= ed) {
	            int t = 0;
	            while(p <= n && deep[a[p]] == deepnow && fa[a[p]] == a[pf])
	            	p ++,t ++;
                if(t != son[a[pf]]) return false;
                pf ++;
			}
           	pf = npf; p = i + 1;
        }
    }
    return true;
}

int main() {
    n = read();
    for(int i = 1;i < n;i ++){
   		int x = read(),y = read();
   		g[x].push_back(y);
   		g[y].push_back(x);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i ++) {
    	a[i] = read();
	}
	for(int i = 1,maxdep = 0;i <= n;i ++) {
        if(deep[a[i]] < maxdep) { puts("No"); return 0; }
        maxdep = max(deep[a[i]],maxdep);
	}
	if(a[1] != 1) { puts("No"); return 0; }
	if(check()) puts("Yes");
	else puts("No");
	return 0;
}
/**
8
1 2
2 3
2 4
2 5
3 6
3 7
5 8
1 2 3 4 5 6 7 8
*/
