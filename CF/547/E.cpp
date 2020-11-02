#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
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

int ch[SZ][28],totp,fail[SZ],ed[SZ];
vector<int> nodelist[SZ];

void insert(char s[],int id) {
    int n = strlen(s),p = 0;
    for(int i = 0;i < n;i ++) {
        int c = s[i] - 'a';
        if(!ch[p][c]) ch[p][c] = ++ totp;
        p = ch[p][c];
        nodelist[id].push_back(p);
    }
    nodelist[id].push_back(0);
    ed[id] = p;
}

void build_ac() {
    queue<int> q;
    fail[0] = 0;
    for(int i = 0;i < 26;i ++) {
        int u = ch[0][i];
        if(u) { q.push(u); fail[u] = 0; }
    }
    while(q.size()) {
        int f = q.front(); q.pop();
        for(int i = 0;i < 26;i ++) {
            int u = ch[f][i];
            if(!u) continue;
            q.push(u);
            int v = fail[f];
            while(v && !ch[v][i]) v = fail[v];
            fail[u] = ch[v][i];
        }
    }
}

int dfn[SZ],sz[SZ],dfs_clock;
vector<int> g[SZ];

void dfs(int u) {
    dfn[u] = ++ dfs_clock;
    sz[u] = 1;
    for(int v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

LL tree[SZ];

void add(int x,int d) {
    for(int i = x;i <= dfs_clock;i += i & -i) tree[i] += d;
}

LL ask(int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

struct haha {
    int pos,k,id,d;
}a[SZ];

bool cmp(haha a,haha b) { return a.pos < b.pos; }

LL ans[SZ];

char s[SZ];

int main() {
    int n = read(),q = read();
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s);
        insert(s,i);
    }
    build_ac();
    for(int i = 1;i <= totp;i ++) {
        g[fail[i]].push_back(i);
    }
    dfs(0);
    int tot = 0;
    for(int i = 1;i <= q;i ++) {
        int l = read(),r = read(),k = read();
        a[++ tot] = (haha){l-1,k,i,-1};
        a[++ tot] = (haha){r,k,i,1};
    }
    sort(a+1,a+1+tot,cmp);
//    for(int i = 1,now = 1;i <= dfs_clock;i ++) cout << dfn[i] << " "; puts("");
 //   for(int i = 1,now = 1;i <= tot;i ++) cout << a[i].pos << " " << a[i].k << endl;
    for(int i = 1,now = 1;i <= tot;i ++) {
        while(now <= a[i].pos) {
            for(int p : nodelist[now]) add(dfn[p],1);
            now ++;
        }
        int p = ed[a[i].k];
     //   cout << i << endl;
        ans[a[i].id] += a[i].d * (ask(dfn[p]+sz[p]-1) - ask(dfn[p]-1));
    }
    for(int i = 1;i <= q;i ++) {
        printf("%lld\n",ans[i]);
    }
}
/**
4 3
*/
