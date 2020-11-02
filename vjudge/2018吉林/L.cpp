#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
const int SZ = 2e5 + 10;
const int mod = 1e9+7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a=='-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

int n,m;
int A[55],B[55];
int mark[55],xl[55];
vector<int> nodelist,g[55];

void remark(int u,int f) {
    nodelist.push_back(u);
    for(int v : g[u]) {
        if(v == f) continue;
        remark(v,u);
    }
}

int sz[55];

void predfs(int u,int f) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == f) continue;
        predfs(v,u);
        sz[u] += sz[v];
    }
}

int get_centroid(int u) {
    predfs(u,0);
    int s = sz[u];
    while(1) {
        int found = 1;
        for(int v : g[u]) {
            if(sz[v] > sz[u]) continue;
            if(sz[v] * 2 >= s) {
                u = v; found = 0; break;
            }
        }
        if(found) return u;
    }
}

pil up(pil a,pil b) {
    pil ans;
    ans.first = max(a.first,b.first);
    if(a.first == ans.first) ans.second += a.second;
    if(b.first == ans.first) ans.second += b.second;
    if(!ans.second) ans.first = -1;
    return ans;
}

pil a[2][5010];
pil ans[2][5010];
pil tmp[2][5010];

void dfs(int d,int dn,int S,int sa,int sb) {
    if(sa>m) return ;
    if(d == dn) {
        a[S&1][sa] = up(a[S&1][sa],make_pair(sb,1));
        return ;
    }
    int u = nodelist[d];
    if(!(xl[u] & S)) dfs(d+1,dn,S^(1<<mark[u]),sa+A[u],sb+B[u]);
    dfs(d+1,dn,S,sa,sb);
}

void work(int u,int r) {
    nodelist.clear();
    remark(u,r);
    for(int i = 0;i < nodelist.size();i ++) mark[nodelist[i]] = i;
    for(int u : nodelist) {
        xl[u] = 0;
        for(int v : g[u]) {
            if(v == r) continue;
            xl[u] ^= 1<<mark[v];
        }
    }
    for(int i = 0;i < 2;i ++)
        for(int j = 0;j <= m;j ++) {
            tmp[i][j] = make_pair(-1,0);
            a[i][j] = make_pair(-1,0);
        }
    dfs(0,nodelist.size(),0,0,0);
    for(int x = 0;x < 2;x ++) {
        for(int i = 0;i <= m;i ++) {
            if(ans[x][i].second == 0) continue;
            for(int y = 0;y < 2;y ++) {
                if(x==1&&y==1) continue;
                for(int j = 0;i+j <= m;j ++) {
                    if(a[y][j].second == 0) continue;
                    int sb = ans[x][i].first+a[y][j].first;
                    LL t = ans[x][i].second*a[y][j].second;
                    tmp[x][i+j] = up(tmp[x][i+j],make_pair(sb,t));
                }
            }
        }
    }
    /*cout << u << endl;
    for(int i = 0;i < 2;i ++) {
        cout << i << endl;
        for(int j = 0;j <= m;j ++) printf("%3d",a[i][j].first); puts("");
        for(int j = 0;j <= m;j ++) printf("%3d",a[i][j].second); puts("");
    }
    for(int i = 0;i < 2;i ++) {
        cout << i << endl;
        for(int j = 0;j <= m;j ++) printf("%3d",ans[i][j].first); puts("");
        for(int j = 0;j <= m;j ++) printf("%3d",ans[i][j].second); puts("");
    }
    for(int i = 0;i < 2;i ++) {
        cout << i << endl;
        for(int j = 0;j <= m;j ++) printf("%3d",tmp[i][j].first); puts("");
        for(int j = 0;j <= m;j ++) printf("%3d",tmp[i][j].second); puts("");
    }
    puts("--------");*/
    for(int i = 0;i < 2;i ++)
        for(int j = 0;j <= m;j ++)
            ans[i][j] = tmp[i][j];
}

void bl() {
    vector<pil> ans; ans.resize(m+1);
    for(int S = 0;S < (1<<n);S ++) {
        int sb = 0,sa = 0,b = 0;
        for(int i = 0;i < n;i ++) {
            if(S>>i&1) {
                bool flag = 0;
                for(int j : g[i+1]) if(S>>(j-1)&1) flag = 1;
                if(flag) { b=1; break;}
                sa += A[i+1];
                sb += B[i+1];
            }
        }
        if(b) continue;
        if(sa>m) continue;
        if(ans[sa].first < sb) ans[sa] = make_pair(sb,1);
        else if(ans[sa].first == sb) ans[sa].second ++;
    }
    for(int i = 1;i <= m;i ++) printf("%lld ",ans[i].second); puts("");
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) A[i]=read(),B[i]=read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int rt = get_centroid(1);
        predfs(rt,0);
        sort(g[rt].begin(),g[rt].end(),[](int x,int y) {return sz[x] < sz[y];});
        for(int i = 0;i <= m;i ++) {
            ans[0][i] = ans[1][i] = make_pair(-1,0);
        }
        ans[0][0] = make_pair(0,1);
        ans[1][A[rt]] = make_pair(B[rt],1);
       // cout << rt << endl;
        for(int x : g[rt]) work(x,rt);
        printf("Case %d:\n",++ cc);
        for(int i = 1;i <= m;i ++) {
            pil x = up(ans[0][i],ans[1][i]);
            printf("%lld%c",x.second,i==m?'\n':' ');
        }
        //bl();
    }
}

/**
1
4 5
1 1
2 2
3 2
2 1
1 2
2 3
3 4

3
3 2
1 1
1 1
1 1
1 2
1 3
4 5
1 1
2 2
3 2
2 1
1 2
2 3
3 4
5 10
3 1
2 2
4 4
7 8
5 16
1 2
1 3
2 4
2 5
*/
