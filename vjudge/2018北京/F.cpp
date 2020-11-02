#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 5e4 + 10;
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

struct Bitset {
    #define W (64)

    int n;
    ULL bits[SZ / W + 10];
    int num[SZ / W + 10];

    void preWork() {
        for(int i = 0;i <= n/W;i ++) num[i] = __builtin_popcountll(bits[i]);
        for(int i = n/W-1;i >= 0;i --) num[i] += num[i+1];
     //  for(int i = 0;i < m;i ++) printf("%d ",sum[i]); puts("");
      //  for(int i = 0;i <= n/W;i ++) printf("%llu ",bits[i]); puts("");
    }

    int ask(int x) {
        if(x > n) return 0;
        int blockid = x / W;
        int ans = __builtin_popcountll(bits[blockid]>>(x%W));
        blockid ++;
        if(blockid <= n/W) ans += num[blockid];
        return ans;
    }

    int ask(int l,int r) {
        return ask(l) - ask(r+1);
    }

    void Or(const Bitset &t) {
        for(int i = 0;i <= n / W;i ++) bits[i] |= t.bits[i];
    }

    void Copy(const Bitset &t) {
        n = t.n;
        for(int i = 0;i <= n / W;i ++) bits[i] = t.bits[i];
    }

    void Set(int x) {
        bits[x/W] |= 1llu << (x%W);
    }

    void init(int nn) {
        n = nn; //n ++;
        for(int i = 0;i <= n / W;i ++) bits[i] = 0;
    }

    void print() {
        for(int i = 0;i < n;i ++) {
            if(bits[i/W] >> (i%W) & 1)
                printf("%d ",i);
        }
        puts("");
    }

    #undef W
}bs[SZ];

struct Tarjan {

    int n;
    int dfn[SZ],low[SZ],dfs_clock,scccnt,sccnum[SZ];
    vector<int> g[SZ],sccnodes[SZ];
    stack<int> S;

    void dfs(int u) {
        dfn[u] = low[u]= ++ dfs_clock;
        S.push(u);
        for(int v : g[u]) {
            if(!dfn[v]) {
                dfs(v);
                low[u] = min(low[u],low[v]);
            }
            else if(!sccnum[v])
                low[u] = min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u]) {
            scccnt ++;
            while(1) {
                int x = S.top(); S.pop();
                sccnum[x] = scccnt;
                sccnodes[scccnt].push_back(x);
                if(x == u) break;
            }
        }
    }

    vector<int> g2[SZ];
    int cd[SZ];

    void work(Bitset bs[]) {
        for(int i = 1;i <= n;i ++)
            if(!dfn[i])
                dfs(i);
      //  for(int u = 1;u <= n;u ++) printf("%d ",sccnum[u]); puts("");
        for(int u = 1;u <= n;u ++)
            for(int v : g[u])
                if(sccnum[u] != sccnum[v]) {
                    g2[sccnum[v]].push_back(sccnum[u]);
                    cd[sccnum[u]] ++;
                }
        static Bitset tmp[SZ];
        for(int i = 1;i <= scccnt;i ++) {
            tmp[i].init(n); //tmp[i].print();
            for(int x : sccnodes[i])
                tmp[i].Set(x);
        }
        queue<int> q;
        for(int i = 1;i <= scccnt;i ++)
            if(cd[i] == 0) {
                q.push(i);
            }
        while(q.size()) {
            int v = q.front(); q.pop();
           // printf("%d: ",v); tmp[v].print();
            for(int x : sccnodes[v]) bs[x].Copy(tmp[v]);
            for(int u : g2[v]) {
                tmp[u].Or(tmp[v]);
                cd[u] --;
                if(cd[u] == 0) {
                    q.push(u);
                }
            }
        }
    }

    void addEdge(int x,int y) {
        g[x].push_back(y);
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= scccnt;i ++) {
            g2[i].clear();
            sccnodes[i].clear();
            cd[i] = 0;
        }
        for(int i = 1;i <= n;i ++) {
            g[i].clear();
            dfn[i] = low[i] = sccnum[i] = 0;
        }
        scccnt = 0;
        dfs_clock = 0;
    }

}tarjan;

int now[SZ];

void work(int n,int &mid,int id,int &k) {
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        int t,l,r;
        if(i>>id&1)
            t = bs[i].ask(l=now[i],r=now[i]+(1<<id)-1);
        else
            t = bs[i].ask(l=now[i]+(1<<id),r=now[i]+(2<<id)-1);
        ans += t;
     //   printf("%d: [%d,%d] %d\n",i,l,r,t);
    }
    //cout << id << " " << ans << " " << k << endl;
    if(k <= ans) {
        for(int i = 1;i <= n;i ++) {
            if((i>>id&1) == 0) {
                now[i] |= 1 << id;
            }
        }
        mid |= 1 << id;
    }
    else {
        k -= ans;
        for(int i = 1;i <= n;i ++) {
            if(i>>id&1) {
                now[i] |= 1 << id;
            }
         }
    }
    //cout << k << endl;
   // for(int i = 1;i <= n;i ++) printf("%d ",now[i]); puts("");
}

int main() {
   // freopen("F.in","r",stdin); freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read(),m = read(),Q = read();
        tarjan.init(n);
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            tarjan.addEdge(x,y);
        }
        tarjan.work(bs);
//        for(int i = 1;i <= n;i ++) bs[i].print();
        for(int i = 1;i <= n;i ++){
            bs[i].preWork();
        }
        while(Q --) {
            int k = read();
            int ans = 0;
            for(int i = 1;i <= n;i ++) now[i] = 0;
            for(int i = 16;i >= 0;i --) {
                work(n,ans,i,k);
            }
            printf("%d\n",ans);
        }
    }
}
