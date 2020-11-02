#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct DataStructure {
    int tim[SZ]; /// 每个元素出现多少次
    int num[SZ]; /// 出现i次的元素个数
    int ans;
    int element_num,col_num;

    void add(int x) {

        num[tim[x]] --;
        tim[x] ++;
        num[tim[x]] ++;
        ans = max(ans,tim[x]);
    }

    void del(int x) {
        num[tim[x]] --;
        tim[x] --;
        num[tim[x]] ++;
        while(ans>0&&num[ans] == 0) ans --;
    }

    void init(int e,int c) {
        element_num = e;
        col_num = c;
        for(int i = 0;i <= max(e,c);i ++) tim[i] = 0,num[i] = 0;
        num[0] = element_num;
        ans = 0;
    }

    int ask() {
        return ans;
    }
}data1,data2;

struct edge {
    int f,t,d;
};

vector<edge> g[SZ],g2[SZ],edgeList[SZ];
vector<int> nodeList[SZ],val[SZ];

int dfn[SZ],low[SZ],dfs_clock,allAns[SZ],Ans[SZ],a[SZ];
int col[SZ],bcnt;
bool hasWork[SZ],bridge[SZ],mark[SZ];

void tarjan(int u,int fa,int id) {
    hasWork[u] = 1;
    nodeList[id].push_back(u);
    dfn[u] = low[u] = ++dfs_clock;
    for(edge e : g[u]) {
        int v = e.t;
        if(v == fa) continue;
        if(!mark[e.d]) edgeList[id].push_back(e),mark[e.d]=1;
        if(!dfn[v]) {
            tarjan(v,u,id);
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]) bcnt ++,bridge[e.d] = 1;
        }
        else if(dfn[v]<dfn[u])
            low[u]=min(low[u],dfn[v]);
    }
}

void dfsColor(int u,int color) {
    col[u] = color;
    val[color].push_back(a[u]);
    for(edge e : g[u]) {
        int v = e.t;
        if(bridge[e.d] || col[v]) continue;
        dfsColor(v,color);
    }
}

int sz[SZ],son[SZ],faEdgeId[SZ];

void pre_dfs(int u,int fa) {
    sz[u] = val[u].size();
    son[u] = 0;
    for(edge e : g2[u]) {
        int v = e.t;
        if(v == fa) continue;
        pre_dfs(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v,faEdgeId[v] = e.d;
    }
}

vector<int> nodes;

void dfs2(int u,int fa) {
    for(int x : val[u]) nodes.push_back(x);
    for(edge e: g2[u]) {
        int v = e.t;
        if(v == fa) continue;
        dfs2(v,u);
    }
}

void dfs(int u,int fa,bool c,int id) {
    for(edge e : g2[u]) {
        int v = e.t;
        if(v == fa) continue;
        if(v != son[u]) dfs(v,u,0,e.d);
    }
    if(son[u]) dfs(son[u],u,1,faEdgeId[son[u]]);

    for(int x : val[u]) data1.del(x),data2.add(x);
    for(edge e : g2[u]) {
        int v = e.t;
        if(v == fa || v == son[u]) continue;
        nodes.clear();
        dfs2(v,u);
        for(int x : nodes) data1.del(x),data2.add(x);
    }
    Ans[id] = data1.ask() + data2.ask();
    if(!c) {
        nodes.clear();
        dfs2(u,fa);
        for(int x : nodes) data1.add(x),data2.del(x);
    }
}

int lsh[SZ];

void work(int u,int id) {
    nodeList[id].clear();
    edgeList[id].clear();
    bcnt = 0;
    dfs_clock = 0;
    tarjan(u,0,id);
    for(edge e : edgeList[id]) mark[e.d] = 0;

    lsh[0] = 0;
    for(int x : nodeList[id]) lsh[++ lsh[0]] = a[x];
    sort(lsh+1,lsh+1+lsh[0]); lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;
    for(int i : nodeList[id])
        a[i] = lower_bound(lsh+1,lsh+1+lsh[0],a[i])-lsh;

    int c = 0;
    for(int x : nodeList[id]) {
        if(!col[x]) {
            c ++;
            val[c].clear();
            dfsColor(x,c);
        }
    }

    for(int i = 1;i <= c;i ++) g2[i].clear();

    for(edge e : edgeList[id]) {
        if(col[e.f] != col[e.t]) {
            int u = col[e.f];
            int v = col[e.t];
            g2[u].push_back((edge){u,v,e.d});
            g2[v].push_back((edge){v,u,e.d});
        }
    }
/*
    puts("---------");
    printf("%d\n",c);
    for(int i = 1;i <= c;i ++) {
        for(int x : val[i]) printf("%d ",x); puts("");
    }
    for(edge e : edgeList[id]) printf("%d ",e.d); puts("");
    puts("---------");
*/

    data1.init(nodeList[id].size(),lsh[0]);
    data2.init(nodeList[id].size(),lsh[0]);

    for(int x : nodeList[id]) data1.add(a[x]);

    allAns[id] = data1.ask();

    for(edge e : edgeList[id]) {
        if(col[e.f] == col[e.t]) {
            Ans[e.d] = allAns[id];
        }
    }

    pre_dfs(1,0);
    dfs(1,0,0,0);
}

int main() {
    //freopen("B.in","r",stdin); freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= m;i ++) {
            bridge[i] = 0;
        }
        for(int i = 1;i <= n;i ++) {
            g[i].clear();
            hasWork[i] = 0;
            dfn[i] = 0;
            low[i] = 0;
            col[i] = 0;
        }
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            g[x].push_back((edge){x,y,i});
            g[y].push_back((edge){y,x,i});
        }

        int tot = 0;
        for(int i = 1;i <= n;i ++) {
            if(!hasWork[i]) {
                tot ++;
                work(i,tot);
            }
        }

        int sum = 0;
        for(int i = 1;i <= tot;i ++) sum += allAns[i];
        for(int i = 1;i <= tot;i ++) {
            for(edge e : edgeList[i])
                Ans[e.d] += sum - allAns[i];
        }
        for(int i = 1;i <= m;i ++) {
            printf("%d%c",Ans[i],i==m?'\n':' ');
        }

    }
}
