#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 3e6 + 10;
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

int ch[SZ][27],id[SZ],tot;

int insert(char s[]) {
    int n = strlen(s);
    int p = 0;
    for(int i = 0;i < n;i ++) {
        int c = s[i] - 'a';
        if(!ch[p][c]) ch[p][c] = ++ tot;
        p = ch[p][c];
    }
    return p;
}

int fail[SZ];
vector<int> G[SZ];
int dfs_clock;
int pre[SZ],suf[SZ];

void dfs(int u) {
    pre[u] = ++ dfs_clock;
    for(int v : G[u]) {
        dfs(v);
    }
    suf[u] = ++ dfs_clock;
}

int dfs_trie_clock,trie_seq[SZ],trie_dfn[SZ];

void dfs_trie(int u) {
    trie_seq[++ dfs_trie_clock] = u;
    trie_dfn[u] = dfs_trie_clock;
    for(int i = 0;i < 26;i ++) {
        if(ch[u][i]) {
            int v = ch[u][i];
            dfs_trie(v);
        }
    }
    trie_seq[++ dfs_trie_clock] = u;
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
    for(int i = 1;i <= tot;i ++) {
      //  cout << fail[i] << " " << i << endl;
        G[fail[i]].push_back(i);
    }
    dfs(0);
    dfs_trie(0);
}

struct haha {
    int i,p,id,ans;
}b[SZ];

bool cmp(haha a,haha b) {
    return trie_dfn[id[a.i]] < trie_dfn[id[b.i]];
}

bool cmpid(haha a,haha b) {
    return a.id < b.id;
}

int tree[SZ];

void add(int x,int d) {
    for(int i = x;i <= dfs_clock;i += i & -i) tree[i] += d;
}

int ask(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

char s[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        int o = read(),j;
        if(o == 1) j = 0;
        else j = read();
        char s[2];
        scanf("%s",s);
        int c = s[0] - 'a';
        if(!ch[id[j]][c]) ch[id[j]][c] = ++ tot;
        id[i] = ch[id[j]][c];
    }
    int q = read();
    for(int i = 1;i <= q;i ++) {
        b[i].i = read();
        scanf("%s",s);
        b[i].p = insert(s);
        b[i].id = i;
    }
    build_ac();
    sort(b+1,b+1+q,cmp);

  //  for(int i = 1;i <= dfs_clock;i ++) printf("%4d",dfs_seq[i]); puts("");
   // for(int i = 1;i <= n;i ++)  printf("%d %d %d\n",i,id[i],pre[id[i]]);

    for(int i = 1,j = 1;i <= q;i ++) {
        while(j <= dfs_trie_clock && j <= trie_dfn[id[b[i].i]]) {
            int x = trie_seq[j];
            int d = trie_dfn[x] == j ? 1 : -1;
            add(pre[x],d);
            j ++;
        }
       // printf("%d %d %d\n",b[i].id,b[i].p,j);
       // for(int j = 1;j <= dfs_clock;j ++) printf("%4d",ask(j)-ask(j-1)); puts("");
        b[i].ans = ask(suf[b[i].p]) - ask(pre[b[i].p] - 1);
    }
    sort(b+1,b+1+q,cmpid);
    for(int i = 1;i <= q;i ++) printf("%d\n",b[i].ans);
}

/**
6
1 d
2 1 a
2 2 d
2 3 a
2 4 d
2 5 a
3
6 da
6 dada
6 ada

*/
