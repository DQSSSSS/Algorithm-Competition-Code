#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 3e6 + 10;
const LL INF = 1e15 + 10;
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
    int f,t;
    LL d;
}l[SZ];

int head[SZ],nxt[SZ],tot = 1;

void build(int f,int t,LL d) {
    l[++ tot] = (edge){f,t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d) {
  //  printf("%d %d %lld\n",f,t,d);
    build(f,t,d); build(t,f,0);
}

int deep[SZ];

bool bfs(int s,int e) {
    for(int i = 1;i <= e;i ++) deep[i] = 0; queue<int> q;
    q.push(s); deep[s] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = nxt[i]) {
            int v = l[i].t;
            if(l[i].d && !deep[v]) {
                deep[v] = deep[u] + 1;
                if(v == e) return true;
                q.push(v);
            }
        }
    }
    return false;
}
LL dfs(int u,LL flow,int e) {
    if(u == e || flow == 0) return flow;
    LL ans = flow;
    for(int i = head[u];i;i = nxt[i]) {
        int v = l[i].t;
        if(l[i].d && deep[v] == deep[u] + 1) {
            LL f = dfs(v,min(ans,l[i].d),e);
            if(f > 0) {
                l[i].d -= f; l[i^1].d += f; ans -= f;
                if(ans == 0) break;
            }
            else deep[v] = 0;
        }
    }
    if(ans == flow) deep[u] = 0;
    return flow - ans;
}
LL dinic(int s,int e) {
    LL ans = 0;
    while(bfs(s,e)) {
        LL tmp = dfs(s,INF,e);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

int f[110][110];

struct hhhh {
    int x,a,f,p;
}a[SZ];

vector<pii> base[SZ];
LL val[SZ];
int id[SZ],ff[SZ],tt[SZ],mark[SZ];

int main() {
    int n = read(),m = read();
    memset(f,63,sizeof f);
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        f[x][y] = f[y][x] = 1;
    }
    for(int k = 1;k <= n;k ++) f[k][k] = 0;
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++)
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);

    int S = read(),B = read(),K = read();
    for(int i = 1;i <= S;i ++) {
        a[i].x = read(),a[i].a = read(),a[i].f = read(),a[i].p = read();
    }
    for(int i = 1;i <= B;i ++) {
        int x = read(),d = read(),g = read();
        base[x].push_back(make_pair(d,g));
    }
    for(int i = 1;i <= n;i ++) {
        sort(base[i].begin(),base[i].end());
        int maxg = -1;
        for(int j = 0;j < base[i].size();j ++) {
            maxg = max(maxg,base[i][j].second);
            base[i][j].second = maxg;
        }
    }

    for(int i = 1;i <= S;i ++) {
        int u = a[i].x;
        LL maxg = -INF;
        for(int v = 1;v <= n;v ++) {
            if(f[u][v] <= a[i].f) {
                auto it = upper_bound(base[v].begin(),base[v].end(),make_pair(a[i].a,(int)(1e9+1)));
                if(it == base[v].begin()) continue;
                it --;
                maxg = max(maxg,1ll * it -> second);
            }
        }
        if(maxg == -INF) val[i] = -1e14;
        else val[i] = maxg - a[i].p;
    }
    for(int i = 1;i <= K;i ++) {
        ff[i] = read(),tt[i] = read();
        mark[ff[i]] = 1;
        mark[tt[i]] = 1;
    }

    LL ans = 0;
   // for(int i = 1;i <= S;i ++) cout << i << " " << val[i] << endl;
    for(int i = 1;i <= S;i ++) if(!mark[i]) ans += max(val[i],0ll);
    int tot = 0;
    for(int i = 1;i <= S;i ++)
        if(mark[i]) {
            id[i] = ++ tot;
        }
 //   cout << tot << endl;
    int s = tot + 1,e = s + 1;
    LL sum = 0;
    for(int i = 1;i <= S;i ++) {
        if(!mark[i]) continue;
        if(val[i] > 0) {
            sum += val[i];
            insert(s,id[i],val[i]);
        }
        else {
            insert(id[i],e,-val[i]);
        }
    }
    for(int i = 1;i <= K;i ++) {
        int x = id[ff[i]],y = id[tt[i]];
        insert(x,y,INF);
    }

    cout << ans + sum - dinic(s,e);

}
