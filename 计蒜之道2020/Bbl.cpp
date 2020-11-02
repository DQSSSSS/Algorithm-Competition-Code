#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

vector<int> G[SZ];

int ans[SZ],w1[SZ],w2[SZ],deep[SZ],fa[SZ];
vector<int> depNodes[SZ];

void dfs(int u,int f) {
    deep[u] = deep[f] + 1;
    depNodes[deep[u]].push_back(u);
    fa[u] = f;
    for(int v : G[u]) {
        dfs(v,u);
    }
}

int main() {
    int n = read(),x = read();
    for(int i = 2;i <= n;i ++) {
        int p = read();
        G[p].push_back(i);
    }
    for(int i = 1;i <= n;i ++) {
        w1[i] = read();
        w2[i] = w1[i] ^ x;
    }
    LL ans = 0;
    for(int u = 1;u <= n;u ++) {
        for(int i = 1;i <= n;i ++) depNodes[i].clear();
        dfs(u,0);
        int t = 0;
        for(int d = 1;d <= n;d ++){
            map<int,int> mp;
            for(int id : depNodes[d]) {
                mp[w1[id]] ++;
            }
            if(x) {
                for(int id : depNodes[d]) {
                    if(mp[w2[id]]) {
                        t ++;
                        break;
                    }
                }
            }
            else {
                for(int id : depNodes[d]) {
                    if(mp[w2[id]] > 1) {
                        t ++;
                        break;
                    }
                }
            }
        }

        (ans += u ^ (n-t)) %= mod;
    }
    cout << ans << endl;
}


