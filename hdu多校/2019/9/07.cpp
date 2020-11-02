#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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
/*
void kaizhan() {
    int size = 256 << 20; // 256MB
    char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p));
}
*/
int st[SZ][22];
vector<int> G[SZ];

int f[SZ],g[SZ];

void dfs1(int u,int fa) {
    f[u] = 1; g[u] = 1;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs1(v,u);
        g[u] = max(g[u],f[u] + f[v]);
        f[u] = max(f[u],f[v] + 1);
    }
}

void change_max(int l,int r,int d) {
    if(r<0||d<0) return ;
    int k = log2(r-l+1);
    st[l][k] = max(st[l][k],d);
    st[r-(1<<k)+1][k] = max(st[r-(1<<k)+1][k],d);
}

struct haha {
    set<pii> s;
    void push(int x,int y) {
        s.insert(make_pair(x,y));
    }

    void del(int x,int y) {
        s.erase(make_pair(x,y));
    }

    int find_one_max() {
        if(s.empty()) return -INF;
        return prev(s.end()) -> first;
    }

    int find_two_max() {
        if(s.size() < 2) return -INF;
        return prev(s.end()) -> first + prev(prev(s.end())) -> first;
    }
};

void dfs2(int u,int fa,int w0,int w1) {
    change_max(1,g[u],w1);
    change_max(1,w1,g[u]);
    //printf("%d %d %d\n",u,w0,w1);

    haha s,s2;
    for(int v : G[u]) {
        if(v == fa) continue;
        s.push(f[v],v);
        s2.push(g[v],v);
    }
    for(int v : G[u]) {
        if(v == fa) continue;
        s.del(f[v],v);
        s2.del(g[v],v);
        int ww1 = max(max(max(w1,s.find_two_max()+1),
                      max(max(s.find_one_max()+1,w0),s.find_one_max()+w0)),
                      s2.find_one_max());
        int ww0 = max(w0+1,s.find_one_max()+2);
        dfs2(v,u,ww0,ww1);
        s.push(f[v],v);
        s2.push(g[v],v);
    }
}

int main() {
//    kaizhan(); freopen("test.in","r",stdin); freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) G[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = read();
            int y = read();
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(n == 1) { puts("0"); continue; }
        if(n == 2) { puts("1"); continue; }
        for(int j = 0;j <= log2(n);j ++) {
            for(int i = 1;i + (1<<j) - 1 <= n;i ++) {
                st[i][j] = 0;
            }
        }
        int rt;
        for(int i = 1;i <= n;i ++) {
            if(G[i].size() != 1) {
                rt = i;
                break;
            }
        }
       // printf("%d\n",rt);
        dfs1(rt,0);
        //for(int i = 1;i <= n;i ++) printf("%d ",f[i]); puts("");
        dfs2(rt,0,-INF,-INF);
        for(int j = log2(n);j >= 1;j --) {
            for(int i = 1;i + (1<<j) - 1 <= n;i ++) {
                st[i][j-1] = max(st[i][j-1],st[i][j]);
                st[i+(1<<(j-1))][j-1] = max(st[i+(1<<(j-1))][j-1],st[i][j]);
            }
        }
        LL ans = 0;
        for(int i = 1;i <= n;i ++) ans += st[i][0];
       // for(int i = 1;i <= n;i ++) printf("%d ",st[i][0]); puts("");
        printf("%lld\n",ans);
    }
}
/**
233
10
1 2
2 3
3 4
2 5
5 6
6 7
1 8
8 9
9 10
*/
