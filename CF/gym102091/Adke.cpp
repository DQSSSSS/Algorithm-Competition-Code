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

int n,a[SZ],S[SZ],L[SZ],R[SZ];

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
}

int maxdeep[SZ],zero[SZ],deep[SZ];
int dfn[SZ],sz[SZ],dfs_clock = 0;

void dfs(int u,int f) {
    dfn[u] = ++ dfs_clock;
    deep[u] = deep[f] + 1;
    zero[u] = zero[f];
    if(f && a[u] == a[f]) zero[u] ++;

    if(l[u]) {
        dfs(l[u],u);
        sz[u] += sz[l[u]];
        if(a[l[u]] != a[u]) maxdeep[u] = max(maxdeep[u],maxdeep[l[u]]);
    }
    if(r[u]) {
        dfs(r[u],u);
        sz[u] += sz[r[u]];
        if(a[r[u]] != a[u]) maxdeep[u] = max(maxdeep[u],maxdeep[r[u]]);
    }
    if(!l[u] && !r[u]) maxdeep[u] = deep[u];
}

int ask(int x,int y) {
    if(deep[x] > deep[y]) swap(x,y);
    if(deep[x] == deep[y]) return 0;
    if(dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + sz[x] - 1) {
        if(zero[y] - zero[x]) return 0;
        return deep[y] - deep[x];
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
    dfs(root,0);

    for(int i = 1;i <= n;i ++) cout << deep[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) cout << maxdeep[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) cout << l[i] << " " << r[i] << endl; puts("");

    while(m --) {
        int x = read(),y = read();
        if(y == 0) {
            printf("%d\n",maxdeep[x] - deep[x]);
        }
        else {
            printf("%d\n",ask(x,y));
        }
    }
    return 0;
}
