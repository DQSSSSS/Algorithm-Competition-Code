#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e5 + 10;
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

int n,a[SZ],S[SZ],l[SZ],r[SZ];

void build() { //l r : iµÄ×ó¶ù×Ó/ÓÒ¶ù×Ó
    for(int i = 1;i <= n;i ++) l[i] = r[i] = 0;
    int top = 0;
    for(int i = 1;i <= n;i ++) {
        int k = top;
        while(k && a[S[k]] < a[i]) k --;
        if(k) r[S[k]] = i;
        if(k < top) l[i] = S[k + 1];
        top = k;
        S[++ top] = i;
    }
   // for(int i = 1;i <= n;i ++) cout << i << " " << l[i] << " " << r[i] << endl; puts("");
}

int ans_from_root[SZ],mu[SZ],ans_from_this[SZ],tmp[SZ];
int deep[SZ];
int dfn[SZ],sz[SZ],dfs_clock = 0;

void work(int v,int u) {
    sz[u] += sz[v];
    if(a[v] == a[u]) {
        if(l[v])
            ans_from_this[u] = max(ans_from_this[u],ans_from_this[l[v]] + 1);
        tmp[u] = max(tmp[u],tmp[v]);
    }
    else {
        ans_from_this[u] = max(ans_from_this[u],tmp[v] + 1);
        tmp[u] = max(tmp[u],tmp[v] + 1);
    }
}

void dfs(int u,int f) {
    dfn[u] = ++ dfs_clock;
    deep[u] = deep[f] + 1;
    sz[u] = 1;

    if(f && a[u] == a[f]) ans_from_root[u] = ans_from_root[f];
    else ans_from_root[u] = ans_from_root[f] + 1;
    ans_from_this[u] = 0;

    if(l[u]) {
        dfs(l[u],u);
        work(l[u],u);
    }
    if(r[u]) {
        dfs(r[u],u);
        work(r[u],u);
    }
}

int ask(int x,int y) {
    if(y == 0) return ans_from_this[x];
    if(deep[x] > deep[y]) swap(x,y);
    if(deep[x] == deep[y]) return 0;
    if(dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + sz[x] - 1) {
        if(x < y && r[x] < y && a[x] == a[r[x]]) return 0;
        return ans_from_root[y] - ans_from_root[x];
    }
    else return 0;
}

bool use[SZ];

int main() {
    n = read();
    int m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    build();

    for(int i = 1;i <= n;i ++) {
        use[l[i]] = 1; use[r[i]] = 1;
    }
    int root;
    for(int i = 1;i <= n;i ++) {
        if(!use[i]) {
            root = i;
            break;
        }
    }
    //cout << root << endl;
    ans_from_root[0] = -1;
    dfs(root,0);
    /*
    puts("");
    for(int i = 1;i <= n;i ++) printf("%3d",i); puts("  ");
    for(int i = 1;i <= n;i ++) printf("%3d",a[i]); puts("  a");
    for(int i = 1;i <= n;i ++) printf("%3d",ans_from_root[i]); puts("  ans_from_root");
    for(int i = 1;i <= n;i ++) printf("%3d",tmp[i]); puts("  tmp");
    for(int i = 1;i <= n;i ++) printf("%3d",ans_from_this[i]); puts("  ans_from_this");
    for(int i = 1;i <= n;i ++) cout << i << " " << l[i] << " " << r[i] << endl; puts("");
*/
    while(m --) {
        int x = read(),y = read();
        printf("%d\n",ask(x,y));
    }
    return 0;
}
