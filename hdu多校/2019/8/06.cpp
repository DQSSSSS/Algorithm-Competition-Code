#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const LL INF = 1e18 + 10;
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

int a[SZ],b[SZ];
vector<int> g[SZ];
LL f[SZ][2],ans;

void dfs1(int u,int Fa) {
    f[u][0] = f[u][1] = a[u] - b[u];
    if(g[u].size() == 1) return ;
    LL d0 = -INF,d1 = INF;
    for(int v : g[u]) {
        if(v == Fa) continue;
        dfs1(v,u);
        d0 = max(d0,f[v][1]);
        d1 = min(d1,f[v][0]);
    }
    f[u][0] += d0;
    f[u][1] += d1;
}

void dfs2(int u,int Fa,LL w0,LL w1) {
    vector<int> son; son.push_back(0);
    for(int v : g[u]) {
        if(v == Fa) continue;
        son.push_back(v);
    }
    int len = son.size()-1;
    vector<LL> P[2],S[2];
    P[0].resize(son.size()+2);
    P[1].resize(son.size()+2);
    S[0].resize(son.size()+2);
    S[1].resize(son.size()+2);
    P[0][0] = INF;
    P[1][0] = -INF;
    for(int i = 1;i <= len;i ++) {
        int v = son[i];
        P[0][i] = min(f[v][0],P[0][i-1]);
        P[1][i] = max(f[v][1],P[1][i-1]);
    }
    S[0][len+1] = INF;
    S[1][len+1] = -INF;
    for(int i = len;i >= 1;i --) {
        int v = son[i];
        S[0][i] = min(f[v][0],S[0][i+1]);
        S[1][i] = max(f[v][1],S[1][i+1]);
    }
   // printf("%d %lld %lld %lld %lld\n",u,f[u][0],f[u][1],w0,w1);
    if(len == 0) ans = max(ans,w1);
    else ans = max(ans,min(f[u][1],w1));
    for(int i = 1;i <= len;i ++) {
        int v = son[i];
        LL ww0 = a[v] - b[v] + min(w1,a[u] - b[u] + min(P[0][i-1],S[0][i+1]));
        LL ww1 = a[v] - b[v] + max(w0,a[u] - b[u] + max(P[1][i-1],S[1][i+1]));
        dfs2(v,u,ww0,ww1);
    }
}


int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) b[i] = read();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(n == 1) {
            printf("%d\n",a[1] - b[1]);
            continue;
        }
        else if(n == 2) {
            printf("%d\n",a[1] + a[2] - b[1] - b[2]);
            continue;
        }
        int rt = 1;
        for(int i = 1;i <= n;i ++) {
            if(g[i].size() != 1) {
                rt = i;
                break;
            }
        }
        ans = -INF;
        dfs1(rt,0);
        dfs2(rt,0,-INF,INF);
        printf("%lld\n",ans);
    }
}

/**
233
4
1 2 5 1
3 4 3 0
1 2
2 3
3 4
*/
