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

int b[SZ],c[SZ],du[SZ],vis[SZ];
map<int,int> mp;
vector<pii> g[SZ];

void dfs1(int u,int fa) {
    vis[u] = 1;
    for(pii p : g[u]) {
        int v = p.first;
        if(vis[v]) continue;
        dfs1(v,u);
    }
}

vector<int> ans;
int fst[SZ];

void dfs2(int u,int fa) {
    for(int &i = fst[u];i < g[u].size();i ++) {
        pii p = g[u][i];
        int v = p.first;
        if(vis[p.second]) continue;
        vis[p.second] = 1;
        dfs2(v,u);
    }
    ans.push_back(u);
}

int bb[SZ],cc[SZ];
int lsh[SZ];

bool check() {
    int n = ans.size();
    for(int i = 0;i < ans.size() - 1;i ++) bb[i+1] = min(lsh[ans[i]],lsh[ans[i+1]]);
    for(int i = 0;i < ans.size() - 1;i ++) cc[i+1] = max(lsh[ans[i]],lsh[ans[i+1]]);

    sort(b+1,b+n); sort(bb+1,bb+n);
    sort(c+1,c+n); sort(cc+1,cc+n);

  /*  for(int i = 1;i < n;i ++) cout << bb[i] << " "; puts("");
    for(int i = 1;i < n;i ++) cout << b[i] << " "; puts("");
    for(int i = 1;i < n;i ++) cout << cc[i] << " "; puts("");
    for(int i = 1;i < n;i ++) cout << c[i] << " "; puts("");
    for(int i = 0;i < n;i ++) cout << lsh[ans[i]] << " "; puts("");
*/
    for(int i = 1;i < n;i ++) if(b[i] != bb[i]) return false;
    for(int i = 1;i < n;i ++) if(c[i] != cc[i]) return false;
    return true;
}



int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
        b[i] = read();
        if(!mp[b[i]]) mp[b[i]] = ++ lsh[0],lsh[lsh[0]] = b[i];
    }
    for(int i = 1;i < n;i ++) {
        c[i] = read();
        if(!mp[c[i]]) mp[c[i]] = ++ lsh[0],lsh[lsh[0]] = c[i];
    }
    for(int i = 1;i < n;i ++) {
        int x = mp[b[i]],y = mp[c[i]];
        g[x].push_back(make_pair(y,i));
        g[y].push_back(make_pair(x,i));
        du[x] ++;
        du[y] ++;
    }
    dfs1(1,0);
    for(int i = 1;i <= lsh[0];i ++) {
        if(!vis[i]) return puts("-1"),0;
    }

    int ji = 0,f = 1;
    //for(int i = 1;i <= lsh[0];i ++) cout << lsh[i] << " " << du[i] << endl;
    for(int i = 1;i <= lsh[0];i ++) {
        if(du[i] & 1) {
            ji ++;
            f = i;
            if(ji > 2) return puts("-1"),0;
        }
    }
    memset(vis,0,sizeof vis);
    dfs2(f,0);
    reverse(ans.begin(),ans.end());

    if(!check()) return puts("-1"),0;
    for(int x : ans) printf("%d ",lsh[x]);
}
