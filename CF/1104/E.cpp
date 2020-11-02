#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

int n,m,k,deep[SZ],fa[SZ],leaf[SZ];
vector<int> g[SZ];

void dfs(int u,int f) {
    fa[u] = f;
    deep[u] = deep[f] + 1;
    bool flag = 0;
    for(int v : g[u]) {
        if(v == f) continue;
        if(deep[v]) continue;
        dfs(v,u);
        flag = 1;
    }
    if(!flag) leaf[u] = 1;
}

void print(int id,int ed) {
    while(id != ed) printf("%d ",id),id = fa[id];
    printf("%d\n",ed);
}

int main() {
    n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    int maxd = 0,id;
    for(int i = 1;i <= n;i ++) if(maxd < deep[i]) maxd = deep[i],id = i;
    if(maxd > n / k) {
        puts("PATH");
        cout << maxd << endl;
        print(id,1);
    }
    else {
        puts("CYCLES");
        for(int v = 1;v <= n;v ++) {
            if(leaf[v] && k) {
                k --;
                int x = -1,y = -1;
                for(int i : g[v]) {
                    if(i == fa[v]) continue;
                    if(x == -1) x = i;
                    else { y = i; break; }
                }
                if(deep[x] < deep[y]) swap(x,y);
                int a = deep[v] - deep[x],b = deep[x] - deep[y];
                if((a+1)%3) {
                    printf("%d\n",a+1); print(v,x);
                }
                else if((a+b+1)%3) {
                    printf("%d\n",a+b+1); print(v,y);
                }
                else {
                    printf("%d\n",b+2);
                    printf("%d ",v); print(x,y);
                }
            }
        }
    }
    return 0;
}
