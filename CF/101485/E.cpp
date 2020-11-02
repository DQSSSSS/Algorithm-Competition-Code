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

vector<int> g[SZ];

bool vis[SZ];
int match[SZ];

bool dfs(int u) {
    for(int v : g[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            if(!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

map<LL,int> mp;

pii a[SZ];
LL num[SZ],b[SZ];

int main() {
    int n = read(),tot = 0;
    for(int i = 1;i <= n;i ++) {
        LL x = read(),y = read();
        if(!mp[x+y]) mp[x+y] = ++ tot; g[i].push_back(mp[x+y]);
        if(!mp[x-y]) mp[x-y] = ++ tot; g[i].push_back(mp[x-y]);
        if(!mp[x*y]) mp[x*y] = ++ tot; g[i].push_back(mp[x*y]);
        a[i].first = x;
        a[i].second = y;
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= tot;j ++) vis[j] = 0;
        if(dfs(i)) ans ++;
    }
    if(ans != n) puts("impossible");
    else {
        for(pli p : mp) {
            num[p.second] = p.first;
        }
        for(int i = 1;i <= tot;i ++) b[match[i]] = i;
        for(int i = 1;i <= n;i ++) {
            int x = a[i].first;
            int y = a[i].second;
            LL z = num[b[i]];
            char c;
            if(x+y==z) c = '+';
            if(x-y==z) c = '-';
            if(1ll*x*y==z) c = '*';
            printf("%d %c %d = %lld\n",x,c,y,z);
        }
    }
}
