#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

struct edge {
    int t,d;
};

vector<edge> G[SZ];

int f[SZ][2],h[SZ];

void dfs1(int u,int fa) {
    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) continue;
        dfs1(v,u);
    }
    int premax[G[u].size()+1][2] = {};
    int sufmax[G[u].size()+1][2] = {};
    memset(premax,0,sizeof premax);
    memset(sufmax,0,sizeof sufmax);
    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) {
            if(i==0) continue;
            premax[i][0] = premax[i-1][0];
            continue;
        }
        if(i==0)
            premax[i][0] = f[v][0] + e.d;
        else
            premax[i][0] = max(premax[i-1][0],f[v][0]+e.d);
    }
    for(int i = G[u].size()-1;i >= 0;i --) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) {
            sufmax[i][0] = sufmax[i+1][0];
            continue;
        }
        sufmax[i][0] = max(sufmax[i+1][0],f[v][0]+e.d);
    }
    f[u][0] = 0,f[u][1] = INF;
    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) continue;
        int o;
        if(i==0) o = sufmax[i+1][0];
        else o = max(premax[i-1][0],sufmax[i+1][0]);
        f[u][0] = max(f[u][0],f[v][0] + e.d);
        f[u][1] = min(f[u][1],max(o,min(f[v][0],f[v][1] + e.d)));
    }
}

void dfs2(int u,int fa,int w0,int w1) {
    int delval[G[u].size()+1] = {};
    int nodelval[G[u].size()+1] = {};

    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) continue;
        delval[i] = min(f[v][0],f[v][1]+e.d);
        nodelval[i] = f[v][0] + e.d;
    }

    int P[G[u].size()+1][2] = {};
    int S[G[u].size()+1][2] = {};
    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) {
            if(i) P[i][0] = P[i-1][0],P[i][1] = P[i-1][1];
            continue;
        }
        if(i==0) P[i][0] = nodelval[i],P[i][1] = delval[i];
        else {
            P[i][0] = max(P[i-1][0],nodelval[i]);
            P[i][1] = min(max(P[i-1][0],delval[i]),max(P[i-1][1],nodelval[i]));
        }
    }
    S[G[u].size()][0] = 0; S[G[u].size()][1] = INF;
    for(int i = G[u].size()-1;i >= 0;i --) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) {
            S[i][0] = S[i+1][0]; S[i][1] = S[i+1][1];
            continue;
        }
        S[i][0] = max(S[i+1][0],nodelval[i]);
        S[i][1] = min(max(S[i+1][0],delval[i]),max(S[i+1][1],nodelval[i]));
    }
//*****************************************/
    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) continue;
        int o,p;
        if(i==0) o = S[i+1][0],p = S[i+1][1];
        else {
            o = max(P[i-1][0],S[i+1][0]);
            p = min(max(P[i-1][1],S[i+1][0]),max(P[i-1][0],S[i+1][1]));
        }
        int ww0 = max(w0+e.d,o+e.d);
        int ww1 = min(max(w1+e.d,o+e.d),min(max(w0+e.d,p+e.d),max(w0,o)));
      /*  cout << p << endl;
        printf("%d %d %d %d|%d %d %d\n",u,v,ww0,ww1,
               max(w1+e.d,o+e.d),max(w0+e.d,p+e.d),max(w0,o));*/
        dfs2(v,u,ww0,ww1);
    }
/*
    printf("%d : \n",u);
    for(int i = 0;i < G[u].size();i ++) printf("%3d",G[u][i]); puts("");
    for(int i = 0;i < G[u].size();i ++) printf("%3d",premax[i][0]); puts("");
    for(int i = 0;i < G[u].size();i ++) printf("%3d",sufmax[i][0]); puts("");
    for(int i = 0;i < G[u].size();i ++) printf("%3d",premax[i][1]); puts("");
    for(int i = 0;i < G[u].size();i ++) printf("%3d",sufmax[i][1]); puts("");
*/
    h[u] = 0;
    int maxn = 0;
    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) continue;
        maxn = max(maxn,nodelval[i]);
    }
    h[u] = max(w1,maxn);
    for(int i = 0;i < G[u].size();i ++) {
        int v = G[u][i].t;
        edge e = G[u][i];
        if(v == fa) continue;
        int o;
        if(i==0) o = S[i+1][0];
        else o = max(P[i-1][0],S[i+1][0]);
        h[u] = min(h[u],max(max(w0,min(f[v][0],f[v][1]+e.d)),o));
    }
}


int main() {
//    freopen("1.in","r",stdin); freopen("1.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) G[i].clear();
        for(int i = 1;i < n;i ++) {
            int u = read(),v = read(),w = read();
            G[u].push_back((edge){v,w});
            G[v].push_back((edge){u,w});
        }
        dfs1(1,0);
        dfs2(1,0,-INF,-INF);
        int ans = 1e9;
    /*    for(int i = 1;i <= n;i ++) printf("%5d",i); puts("");
        for(int i = 1;i <= n;i ++) printf("%5d",h[i]); puts("");
        for(int i = 1;i <= n;i ++) printf("%5d",f[i][0]); puts("");
        for(int i = 1;i <= n;i ++) printf("%5d",f[i][1]); puts("");*/
        int id = -1;
        for(int i = 1;i <= n;i ++) if(ans > h[i]) ans = h[i],id = i;
        printf("%d %d\n",id,ans);
    }
}
/**
1
10
2 1 139
3 1 72
4 2 141
5 2 133
6 5 121
7 5 49
8 7 182
9 5 174
10 9 171

1
9
2 1 1
3 2 9
4 1 8
5 1 1
6 1 9
7 3 9
8 6 5
9 5 8
*/
